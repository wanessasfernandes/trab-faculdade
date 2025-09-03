import sympy as sp
import numpy as np 
import matplotlib.pyplot as plt
import time

# Definições das funções
x = sp.Symbol('x')
fx = x**2 + 2*x
gx = sp.cos(x) + 2*sp.sin(x)

# Método de newton
def newton(func, x0, e=1e-6, max_i = 100):
    df = sp.diff(func, x)   # Derivada primeira 
    ddf = sp.diff(df, x)    # Derivada segunda d

    fp = sp.lambdify(x, df, 'numpy')        # f'(x)
    fdp = sp.lambdify(x, ddf, 'numpy')      # f''(x)

    xmin = x0

    for i in range(max_i):
        dfx = fp(xmin)
        ddfx = fdp(xmin)

        if abs(ddfx) < e:
            print("Derivada segunda muito pequena, método falhou.")
            return None

        x_next = xmin - dfx/ddfx

        if abs(x_next - xmin) < e:
            return x_next
        xmin = x_next

    return xmin

# Função pra plotar gráfico
def graf(func, xmin, nome_func, intervalo=(-5,5)):
    func = sp.lambdify(x, func, 'numpy')
    x_plot = np.linspace(intervalo[0], intervalo[1], 400)
    y_plot = func(x_plot)

    y_min = func(xmin)

    plt.plot(x_plot, y_plot, label=nome_func, color='indigo')
    plt.scatter(xmin, y_min, color='red', label=f"Mínimo ({xmin:.2f}, {y_min:.2f})")
    plt.axhline(0, linestyle='--', color="gray")
    plt.axvline(0, linestyle='--', color="gray")
    plt.legend()
    plt.grid()
    plt.xlabel("x")
    plt.ylabel("f(x)")
    plt.title(f"Gráfico da função {nome_func}")
    plt.show()

while True:
    print("Escolha uma função para visualizar seu menu: \n")
    time.sleep(0.3)
    print("[ 1 ] - f(x) = x² + 2x")
    time.sleep(0.3)
    print("[ 2 ] - g(x) = cos(x) + 2*sin(x)")
    time.sleep(0.3)
    print("[ 3 ] - Sair do programa...")
    time.sleep(0.3)
    op_func = int(input("Digite a opção: "))

    if op_func == 1:
        print("\nMenu da função f(x) = x² + 2x")
        print("[ 1 ] - Resultado Final")
        print("[ 2 ] - Gráfico")
        print("[ 3 ] - Sair")
        op_menu = int(input("Digite a opção: "))

        while True: 
            if op_menu == 1:
                x0 = float(input("Digite o chute inicial x0: "))
                min = newton(fx, x0)
                print(f"O resultado é X = {min:.3f}")

            elif op_menu == 2:
                x0 = float(input("Digite o chute inicial x0: "))
                xmin = newton(fx, x0)
                graf(fx, xmin, "f(x) = x² + 2x")

            elif op_menu == 3:
                print("saindo...")  
                break  

            else: 
                print("Opção inválida.")  
                     
    elif op_func == 2:
        print("\nMenu da função g(x) = cos(x) + 2*sin(x)")
        print("[ 1 ] - Resultado Final")
        print("[ 2 ] - Gráfico")
        print("[ 3 ] - Sair")
        op_menu = int(input("Digite a opção: "))

        while True: 
            if op_menu == 1:
                x0 = float(input("Digite o chute inicial x0: "))
                min = newton(gx, x0)
                print(f"O resultado é X = {min:.3f}")

            elif op_menu == 2:
                x0 = float(input("Digite o chute inicial x0: "))
                xmin = newton(gx, x0)
                graf(gx, xmin, "g(x) = cos(x) + 2*sin(x)")

            elif op_menu == 3:
                print("saindo...")  
                break  

            else: 
                print("Opção inválida.") 

    elif op_func == 3:    
        print("Encerrando...")
        break;
    else:
        print("Insira uma opção válida.")