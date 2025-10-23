import numpy as np
import matplotlib.pyplot as plt
import time

# Definições das funções
def f(x):
    return x**2 + 2*x

def g(x):
    return np.cos(x) + 2*np.sin(x)

# Método da seção áurea
def secao_aurea(func, a, b, tol, verbose=True):
    R = (np.sqrt(5) - 1) / 2
    d = b - a
    
    x1 = b - R * d
    x2 = a + R * d
    f1 = func(x1)
    f2 = func(x2)
    i = 1
    delay = 0.5

    while abs(b - a) > tol:

        if verbose:
            print("-"*80)    
            print("Iteração - ", i)
            print("-"*80)   
            time.sleep(delay) 
            print(f"x1 = {x1:.3f}")
            print(f"x2 = {x2:.3f}")
            print(f"F(x1) = {f1:.3f}")
            print(f"F(x2) = {f2:.3f}")
            time.sleep(delay)

        if f1 > f2:
            a = x1
            x1 = x2
            f1 = f2
            x2 = a + R * (b - a)
            f2 = func(x2)

            if verbose:
                print("\nComo F(x1) > F(x2): ")
                time.sleep(delay)
                print(f"x1 = {x1:.3f}")
                print(f"x2 = {x2:.3f}")
                print(f"F(x1) = {f1:.3f}")
                print(f"F(x2) = {f2:.3f}")
                time.sleep(delay)
                print("Portanto...")
                time.sleep(delay)
                print("o intervalo à esquerda de x1 é descartado.")

        else:
            b = x2
            x2 = x1
            f2 = f1
            x1 = b - R * (b - a)
            f1 = func(x1)

            if verbose:
                print("\nComo F(x2) > F(x1): \n")
                time.sleep(delay)
                print(f"x1 = {x1:.3f}")
                print(f"x2 = {x2:.3f}")
                print(f"F(x1) = {f1:.3f}")
                print(f"F(x2) = {f2:.3f}\n")
                time.sleep(delay)
                print("Portanto...")
                time.sleep(delay)
                print("o intervalo à direita de x2 é descartado.")

        i += 1

    xmin = (a + b) / 2
    return xmin

# Escolha da função
print("\nEscolha a função que deseja analisar:")
print("[ 1 ] - f(x) = x² + 2x")
print("[ 2 ] - g(x) = cos(x) + 2*sin(x)")
op_func = int(input("Digite a opção: "))

if op_func == 1:
    func = f
    nome_func = "f(x) = x² + 2x"
    intervalo = (-3, 5)
elif op_func == 2:
    func = g
    nome_func = "g(x) = cos(x) + 2*sin(x)"
    intervalo = (-2*np.pi, 2*np.pi)
else:
    print("Opção inválida. Encerrando...")
    exit()

# Menu principal
while True:
    print("\nEscolha uma das opções abaixo para visualizar:")
    time.sleep(0.3)
    print("[ 1 ] - Resultado final")
    time.sleep(0.3)
    print("[ 2 ] - Gráfico ajustado")
    time.sleep(0.3)
    print("[ 3 ] - Encerrar sessão")
    time.sleep(0.3)
    opcao = int(input("Qual será a opção: "))

    if opcao == 1:
        raiz1 = secao_aurea(func, intervalo[0], intervalo[1], 1e-2, verbose=True)
        print("-"*80)    
        print("\nPortanto...")
        print(f" x = {raiz1:.3f}\n F(x) = {func(raiz1):.3f}")
    
    elif opcao == 2:
        raiz1 = secao_aurea(func, intervalo[0], intervalo[1], 1e-2, verbose=False)
        x_min = raiz1
        y_min = func(x_min)
        
        x_plot = np.linspace(intervalo[0], intervalo[1], 400)
        y_plot = func(x_plot)

        plt.scatter(raiz1, func(raiz1), label=f'Ponto Mínimo ({x_min:.1f},{y_min:.1f})', color='lightcoral')
        plt.plot(x_plot, y_plot, label=nome_func, color='indigo')
        plt.axhline(0, linestyle='--', color="violet")
        plt.axvline(0, linestyle='--', color='violet')
        
        plt.plot([x_min, x_min], [min(y_plot), y_min], linestyle="--", color="teal")
        plt.plot([min(x_plot), x_min], [y_min, y_min], linestyle="--", color="teal")
        
        plt.xlabel('x')
        plt.ylabel('f(x)')
        plt.title('Método da Seção Áurea')
        plt.legend()
        plt.grid()
        plt.show()
    
    elif opcao == 3:
        break

print("\n" + "-"*80)
print("\nFeito por:\n\n\t Maria Eduarda Bonan Silva - 202410331011\n\t Wanessa de Souza Fernandes - 202410331211\n\n")
