import sympy as sp
import numpy as np
import matplotlib.pyplot as plt
import time

x1, x2 = sp.symbols('x1 x2')

fx = (x1 - 2)**4 + (x1 - 2*x2)**2
gx = sp.cos(x1) + 2*sp.sin(x2)

# Cálculo do gradiente numérico
def grad_f(func, ponto):
    x1, x2 = sp.symbols('x1 x2')
    p1, p2 = ponto

    dfx1 = sp.lambdify((x1, x2), sp.diff(func, x1), 'numpy')
    dfx2 = sp.lambdify((x1, x2), sp.diff(func, x2), 'numpy')

    return np.array([dfx1(p1, p2), dfx2(p1, p2)], dtype=float)

# Cálculo de Beta (Fletcher–Reeves)
def Beta_calc(ponto_novo, ponto_antigo, func):
    grad_novo = grad_f(func, ponto_novo)
    grad_antigo = grad_f(func, ponto_antigo)

    num = np.dot(grad_novo, grad_novo)
    den = np.dot(grad_antigo, grad_antigo)

    if den == 0:
        return 0
    return num / den

# Método de Newton-Raphson
def newton(func_t, x0, e=1e-6, max_i=100):
    t = sp.symbols('t')

    df = sp.diff(func_t, t)
    ddf = sp.diff(df, t)

    fp = sp.lambdify(t, df, 'numpy')
    fdp = sp.lambdify(t, ddf, 'numpy')

    xmin = x0

    for _ in range(max_i):
        dfx = fp(xmin)
        ddfx = fdp(xmin)

        if abs(ddfx) < e:
            print("Derivada segunda muito pequena. Método falhou.")
            return xmin

        x_next = xmin - dfx/ddfx

        if abs(x_next - xmin) < e:
            return x_next

        xmin = x_next

    return xmin

def DFP_mod(func, x0, tol=1e-6, max_iter=1000):
    x1, x2, t = sp.symbols('x1 x2 t')

    ponto = x0.astype(float)
    grad = grad_f(func, ponto)
    d = -grad

    iteracoes = [ponto.copy()]

    for k in range(max_iter):
        # linha de busca: f(ponto + t*d)
        func_t = func.subs([(x1, ponto[0] + t*d[0]),
                            (x2, ponto[1] + t*d[1])])

        lambd = newton(func_t, 0)

        ponto_novo = ponto + lambd*d
        erro = np.linalg.norm(ponto_novo - ponto)
        iteracoes.append(ponto_novo.copy())

        if erro < tol:
            return ponto_novo, iteracoes

        # atualiza beta e direção
        beta = Beta_calc(ponto_novo, ponto, func)
        grad_novo = grad_f(func, ponto_novo)

        d = -grad_novo + beta*d
        ponto = ponto_novo

    return ponto, iteracoes

def graf(func_expr, xmin, nome_func, intervalo=(-5,5), num_points=100):
    x1, x2 = sp.symbols('x1 x2')
    func = sp.lambdify((x1, x2), func_expr, 'numpy')

    X = np.linspace(intervalo[0], intervalo[1], num_points)
    Y = np.linspace(intervalo[0], intervalo[1], num_points)
    Xg, Yg = np.meshgrid(X, Y)

    Z = func(Xg, Yg)

    fig = plt.figure(figsize=(10,7))
    ax = fig.add_subplot(111, projection='3d')
    ax.plot_surface(Xg, Yg, Z, cmap='viridis', alpha=0.8)

    z_min = func(*xmin)
    ax.scatter(xmin[0], xmin[1], z_min, color='red', s=60,
               label=f"({xmin[0]:.2f}, {xmin[1]:.2f}, {z_min:.2f})")

    ax.set_xlabel("x₁")
    ax.set_ylabel("x₂")
    ax.set_zlabel("f(x₁,x₂)")
    ax.set_title(nome_func)
    ax.legend()
    plt.show()

def graf_erro(iteracoes):
    if len(iteracoes) < 2:
        print("Poucos dados para plotar erro.")
        return

    erro = [np.linalg.norm(iteracoes[i+1] - iteracoes[i])
            for i in range(len(iteracoes)-1)]

    plt.plot(range(1, len(erro)+1), erro, marker='o')
    plt.yscale("log")
    plt.xlabel("Iteração")
    plt.ylabel("Erro (norma)")
    plt.title("Erro a cada iteração (DFP)")
    plt.grid(True, linestyle="--", alpha=0.6)
    plt.show()

def menu_funcao(func, expr, nome):
    while True:
        print(f"\nMenu da função {nome}(x₁, x₂) = {expr}")
        time.sleep(0.3)
        print("[ 1 ] - Resultado Final")
        time.sleep(0.3)
        print("[ 2 ] - Gráfico da função")
        time.sleep(0.3)
        print("[ 3 ] - Gráfico do erro")
        time.sleep(0.3)
        print("[ 4 ] - Voltar")
        time.sleep(0.3)

        op_menu = int(input("Digite a opção: "))

        if op_menu in [1,2,3]:
            x_ini = float(input("\nDigite o chute inicial x₁: "))
            y_ini = float(input("Digite o chute inicial x₂: "))
            xmin, iteracao = DFP_mod(func, np.array([x_ini, y_ini]))

        if op_menu == 1:
            print(f"O resultado é X = [{xmin[0]:.3f}, {xmin[1]:.3f}]")

        elif op_menu == 2:
            graf(func, xmin, f"{nome}(x₁, x₂) = {expr}")

        elif op_menu == 3:
            graf_erro(iteracao)

        elif op_menu == 4:
            print("\nVoltando ao menu principal...\n")
            break

        else:
            print("\nOpção inválida.")

while True:
    print("Escolha uma função para visualizar seu menu: ")
    time.sleep(0.3)
    print("[ 1 ] - f(x₁, x₂) = (x₁ - 2)⁴ + (x₁ - 2x₂)²")
    time.sleep(0.3)
    print("[ 2 ] - g(x₁, x₂) = cos(x₁) + 2*sin(x₂)")
    time.sleep(0.3)
    print("[ 3 ] - Sair do programa...")
    time.sleep(0.3)
    op_func = int(input("Digite a opção: "))

    if op_func == 1:
        menu_funcao(fx, "(x₁ - 2)⁴ + (x₁ - 2x₂)²", "f")

    elif op_func == 2:
        menu_funcao(gx, "cos(x₁) + 2*sin(x₂)", "g")

    elif op_func == 3:
        print("\nEncerrando...")
        break

    else:
        print("\nInsira uma opção válida.")

print("\n" + "-"*80)
print("\nFeito por:\n\n\t Maria Eduarda Bonan Silva - 202410331011\n\t Wanessa de Souza Fernandes - 202410331211\n\n")