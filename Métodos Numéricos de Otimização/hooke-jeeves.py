import numpy as np
import time
import matplotlib.pyplot as plt
import sympy as sp

# Funções
def f(x):
    return (x[0] - 2)**4 + (x[0] - 2*x[1])**2

def g(x):
    return np.cos(x[0]) + np.sin(x[1])

f_sym = (sp.symbols('x0') - 2)**4 + (sp.symbols('x0') - 2*sp.symbols('x1'))**2
g_sym = sp.cos(sp.symbols('x0')) + sp.sin(sp.symbols('x1'))

# Newton 1D
def newton_1d(expr, var, tol=1e-6, max_i=100):
    d1 = sp.diff(expr, var)
    d2 = sp.diff(d1, var)

    f = sp.lambdify(var, expr, "numpy")
    df = sp.lambdify(var, d1, "numpy")
    d2f = sp.lambdify(var, d2, "numpy")

    x = 0.0
    for _ in range(max_i):
        g1 = df(x)
        h = d2f(x)
        if abs(g1) < tol or h == 0:
            break
        x -= g1 / h
    return x

# Hooke-Jeeves + busca de linha via Newton
def hooke_jeeves(func, expr, x0, max_i=50, tol=1e-6):
    x = np.array(x0, dtype=float)
    vars = sp.symbols('x0 x1')

    hist_f = [func(x)]
    hist_x = [x.copy()]

    for i in range(max_i):
        melhoria = False
        base = x.copy()

        # Exploratório
        for j in range(len(x)):
            d = np.zeros_like(x)
            d[j] = 1.0

            phi_pos = expr.subs({vars[k]: base[k] + d[k] * sp.Symbol('l') for k in range(len(x))})
            l_pos = newton_1d(phi_pos, sp.Symbol('l'))
            x_pos = base + l_pos * d

            phi_neg = expr.subs({vars[k]: base[k] - d[k] * sp.Symbol('l') for k in range(len(x))})
            l_neg = newton_1d(phi_neg, sp.Symbol('l'))
            x_neg = base - l_neg * d

            f_atual, f_pos, f_neg = func(base), func(x_pos), func(x_neg)

            if f_pos < f_atual and f_pos < f_neg:
                base = x_pos
                melhoria = True
            elif f_neg < f_atual:
                base = x_neg
                melhoria = True

        if not melhoria:
            break

        # Padrão
        d_p = base - x
        phi_p = expr.subs({vars[k]: base[k] + d_p[k] * sp.Symbol('l') for k in range(len(x))})
        l_p = newton_1d(phi_p, sp.Symbol('l'))
        x_p = base + l_p * d_p

        x = x_p if func(x_p) < func(base) else base

        hist_x.append(x.copy())
        hist_f.append(func(x))

        if np.linalg.norm(hist_x[-1] - hist_x[-2]) < tol:
            break

    return x, func(x), i + 1, hist_x, hist_f

# Gráficos
def graf(func, xmin, titulo):
    x1 = np.linspace(xmin[0] - 4, xmin[0] + 4, 100)
    x2 = np.linspace(xmin[1] - 4, xmin[1] + 4, 100)
    X1, X2 = np.meshgrid(x1, x2)
    Z = np.array([[func([xx, yy]) for xx, yy in zip(xrow, yrow)] for xrow, yrow in zip(X1, X2)])

    fig = plt.figure(figsize=(7, 5))
    ax = fig.add_subplot(111, projection='3d')
    ax.plot_surface(X1, X2, Z, cmap="viridis", alpha=0.8)
    ax.scatter(xmin[0], xmin[1], func(xmin), color="red", s=60, label="Mínimo encontrado")
    ax.set_title(titulo)
    ax.set_xlabel("x₁")
    ax.set_ylabel("x₂")
    ax.set_zlabel("f(x₁, x₂)")
    ax.legend()
    plt.show()

def graf_conv(hist_f, titulo):
    plt.figure(figsize=(6, 4))
    plt.plot(range(len(hist_f)), hist_f, marker='o')
    plt.title(titulo)
    plt.xlabel("Iteração")
    plt.ylabel("f(x)")
    plt.grid()
    plt.show()

# Menu principal
while True:
    print("Escolha uma função para visualizar seu menu: ")
    time.sleep(0.3)
    print("[ 1 ] - f(x₁, x₂) = (x₁ - 2)⁴ + (x₁ - 2x₂)²")
    time.sleep(0.3)
    print("[ 2 ] - g(x₁, x₂) = cos(x₁) + sen(x₂)")
    time.sleep(0.3)
    print("[ 3 ] - Sair do programa...")
    time.sleep(0.3)
    try:
        op_func = int(input("Digite a opção: "))
    except ValueError:
        print("\nOpção inválida. Por favor, digite um número.")
        continue

    if op_func == 1:
        while True:
            print("\nMenu da função f(x₁, x₂) = (x₁ - 2)⁴ + (x₁ - 2x₂)²")
            time.sleep(0.3)
            print("[ 1 ] - Resultado Final")
            time.sleep(0.3)
            print("[ 2 ] - Gráfico da função")
            time.sleep(0.3)
            print("[ 3 ] - Gráfico da convergência")
            time.sleep(0.3)
            print("[ 4 ] - Voltar")
            time.sleep(0.3)
            try:
                op_menu = int(input("Digite a opção: "))
            except ValueError:
                print("\nOpção inválida. Por favor, digite um número.")
                continue

            if op_menu in [1, 2, 3]:
                try:
                    x1_init = float(input("\nDigite o valor inicial de x1: "))
                    x2_init = float(input("Digite o valor inicial de x2: "))
                    minimo, fmin, it, hist_x, hist_f = hooke_jeeves(f, f_sym, [x1_init, x2_init])
                except Exception as e:
                    print(f"Ocorreu um erro: {e}")
                    continue

                if op_menu == 1:
                    print(f"\nResultado: x = {minimo}, f(x) = {fmin:.6f}, iterações = {it}")
                elif op_menu == 2:
                    graf(f, minimo, "f(x₁, x₂) = (x₁ - 2)⁴ + (x₁ - 2x₂)²")
                elif op_menu == 3:
                    graf_conv(hist_f, "Convergência do Hooke-Jeeves para f(x)")

            elif op_menu == 4:
                print("\nVoltando ao menu principal...\n")
                break
            else:
                print("\nOpção inválida.")

    elif op_func == 2:
        while True:
            print("\nMenu da função g(x₁, x₂) = cos(x₁) + sen(x₂)")
            time.sleep(0.3)
            print("[ 1 ] - Resultado Final")
            time.sleep(0.3)
            print("[ 2 ] - Gráfico da função")
            time.sleep(0.3)
            print("[ 3 ] - Gráfico da convergência")
            time.sleep(0.3)
            print("[ 4 ] - Voltar")
            time.sleep(0.3)
            try:
                op_menu = int(input("Digite a opção: "))
            except ValueError:
                print("\nOpção inválida. Por favor, digite um número.")
                continue

            if op_menu in [1, 2, 3]:
                try:
                    x1_init = float(input("\nDigite o valor inicial de x1: "))
                    x2_init = float(input("Digite o valor inicial de x2: "))
                    minimo, fmin, it, hist_x, hist_f = hooke_jeeves(g, g_sym, [x1_init, x2_init])
                except Exception as e:
                    print(f"Ocorreu um erro: {e}")
                    continue

                if op_menu == 1:
                    print(f"\nResultado: x = {minimo}, g(x) = {fmin:.6f}, iterações = {it}")
                elif op_menu == 2:
                    graf(g, minimo, "g(x₁, x₂) = cos(x₁) + sen(x₂)")
                elif op_menu == 3:
                    graf_conv(hist_f, "Convergência do Hooke-Jeeves para g(x)")

            elif op_menu == 4:
                print("\nVoltando ao menu principal...\n")
                break
            else:
                print("\nOpção inválida.")

    elif op_func == 3:
        print("\nEncerrando...")
        break
    else:
        print("\nInsira uma opção válida.")

print("\n" + "-"*80)
print("\nFeito por:\n\n\t Maria Eduarda Bonan Silva - 202410331011\n\t Wanessa de Souza Fernandes - 202410331211\n\n")
