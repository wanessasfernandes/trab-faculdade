import sympy as sp
import numpy as np 
import matplotlib.pyplot as plt
import time

# Definição das funções
x = sp.Symbol('x')
fx = x**2 + 2*x
gx = sp.cos(x) + 2*sp.sin(x)

# Método do Gradiente Descendente
def gradiente_descendente(func, x0, alfa=0.1, e=1e-6, max_i=1000):
    df = sp.diff(func, x)             # Derivada primeira
    fp = sp.lambdify(x, df, 'numpy')  # f'(x)
    f_func = sp.lambdify(x, func, 'numpy')

    xmin = x0
    iteracao = [xmin]

    for i in range(max_i):
        grad = fp(xmin)
        if abs(grad) < e:
            break
        x_next = xmin - alfa * grad   # Atualização
        iteracao.append(x_next)
        if abs(x_next - xmin) < e:
            break
        xmin = x_next

    return xmin, iteracao

# Função para plotar gráfico da função
def graf(func, xmin, nome_func, intervalo=(-5,5)):
    func = sp.lambdify(x, func, 'numpy')
    x_plot = np.linspace(intervalo[0], intervalo[1], 400)
    y_plot = func(x_plot)

    y_min = func(xmin)

    plt.plot(x_plot, y_plot, label=nome_func, color='darkgreen')
    plt.scatter(xmin, y_min, color='red', label=f"Mínimo ({xmin:.2f}, {y_min:.2f})")
    plt.axhline(0, linestyle='--', color="gray")
    plt.axvline(0, linestyle='--', color="gray")
    plt.legend()
    plt.grid()
    plt.xlabel("x")
    plt.ylabel("f(x)")
    plt.title(f"Gráfico da função {nome_func}")
    plt.show()

# Função para plotar o gráfico do erro
def graf_erro(iteracao):
    if len(iteracao) < 2:
        print("Poucos dados para plotar erro.")
        return

    erro = [abs(iteracao[i+1] - iteracao[i]) for i in range(len(iteracao)-1)]
    iteracoes = range(1, len(erro)+1)

    plt.plot(iteracoes, erro, marker='o', color='darkgreen')
    plt.yscale("log")
    plt.xlabel("Iteração")
    plt.ylabel("Erro")
    plt.title("Erro a cada iteração")
    plt.grid(True, which="both", linestyle="--", alpha=0.6)
    plt.show()

# MENU PRINCIPAL
while True:
    print("Escolha uma função para visualizar seu menu: ")
    time.sleep(0.3)
    print("[ 1 ] - f(x) = x² + 2x")
    time.sleep(0.3)
    print("[ 2 ] - g(x) = cos(x) + 2*sin(x)")
    time.sleep(0.3)
    print("[ 3 ] - Sair do programa...")
    time.sleep(0.3)
    op_func = int(input("Digite a opção: "))

    if op_func == 1:
        while True: 
            print("\nMenu da função f(x) = x² + 2x")
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
        
            if op_menu == 1:
                x0 = float(input("\nDigite o chute inicial x0: "))
                alfa = float(input("Digite o passo (alfa): "))
                minimo, iteracao = gradiente_descendente(fx, x0, alfa)
                if minimo is not None:
                    print(f"O resultado é X = {minimo:.3f}")
                    print(f"Número de iterações: {len(iteracao)-1}")

            elif op_menu == 2:
                x0 = float(input("\nDigite o chute inicial x0: "))
                alfa = float(input("Digite o passo (alfa): "))
                xmin, iteracao = gradiente_descendente(fx, x0, alfa)
                graf(fx, xmin, "f(x) = x² + 2x")
            
            elif op_menu == 3:
                x0 = float(input("\nDigite o chute inicial x0: "))
                alfa = float(input("Digite o passo (alfa): "))
                xmin, iteracao = gradiente_descendente(fx, x0, alfa)
                graf_erro(iteracao)

            elif op_menu == 4:
                print("\nVoltando ao menu principal...\n")  
                break  

            else: 
                print("\nOpção inválida.")  
                     
    elif op_func == 2:
        while True: 
            print("\nMenu da função g(x) = cos(x) + 2*sin(x)")
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
        
            if op_menu == 1:
                x0 = float(input("\nDigite o chute inicial x0: "))
                alfa = float(input("Digite o passo (alfa): "))
                minimo, iteracao = gradiente_descendente(gx, x0, alfa)
                if minimo is not None:
                    print(f"O resultado é X = {minimo:.3f}")
                    print(f"Número de iterações: {len(iteracao)-1}")

            elif op_menu == 2:
                x0 = float(input("\nDigite o chute inicial x0: "))
                alfa = float(input("Digite o passo (alfa): "))
                xmin, iteracao = gradiente_descendente(gx, x0, alfa)
                graf(gx, xmin, "g(x) = cos(x) + 2*sin(x)")
            
            elif op_menu == 3:
                x0 = float(input("\nDigite o chute inicial x0: "))
                alfa = float(input("Digite o passo (alfa): "))
                xmin, iteracao = gradiente_descendente(gx, x0, alfa)
                graf_erro(iteracao)

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
