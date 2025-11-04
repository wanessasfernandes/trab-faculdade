import numpy as np 
import matplotlib.pyplot as plt
import time

#menu secundário
def menu_funcao(h):
    while True: 
        print("\nO que você deseja visualizar?")
        time.sleep(0.3)
        print("[ 1 ] - Resultado Final")
        time.sleep(0.3)
        print("[ 2 ] - Gráfico da solução numérica e analítica")
        time.sleep(0.3)
        print("[ 3 ] - Desvio relativo percentual")
        time.sleep(0.3)
        print("[ 4 ] - Voltar")
        time.sleep(0.3)
        op_menu = int(input("Digite a opção: "))

        N0, L, P = 1000, 2.7, 20
        t, N_euler = metodoEuler(h, N0, L, P)
        N_exato = solAnaltica(t, N0, L, P)
    
        if op_menu == 1:
            print(f"Resultado final com passo de {h} é {N_euler[-1]:.4f} núcleos")

        elif op_menu == 2:
            plt.figure(figsize=(7,4))
            plt.plot(t, N_exato, label="Solução Analítica", linestyle='--')
            plt.plot(t, N_euler, label="Solução Numérica (Euler)", marker='o')
            plt.title(f"Soluções para h = {h}")
            plt.xlabel("Tempo (dias)")
            plt.ylabel("Número de núcleos")
            plt.legend()
            plt.grid(True)
            plt.show()
        
        elif op_menu == 3:
            desvio = abs((N_euler - N_exato) / N_exato) * 100
            print("\nDesvios relativos percentuais:")

            plt.figure(figsize=(7,4))
            plt.plot(t, desvio, marker='o', color='red')
            plt.title(f"Desvio Relativo Percentual do passo: h = {h}")
            plt.xlabel("Tempo (dias)")
            plt.ylabel("Desvio (%)")
            plt.grid(True)
            plt.show()


        elif op_menu == 4:
            print("\nVoltando ao menu principal...\n")  
            break  

        else: 
            print("\nOpção inválida.") 

#funções principais
def func(N0, L, P):
    return (-L*N0 + P)

def metodoEuler(h, N0, L, P, tf = 5):
    t = np.arange(0, tf + h, h) #array de tempo com cada passo
    N = np.zeros(len(t)) #array de resultados
    N[0] = N0

    for i in range(1, len(t)):
        dN = func(N[i-1], L, P) 
        N[i] = N[i-1] + h * func(N[i-1], L, P) #atualização de Euler 

    return t, N

def solAnaltica(t, N0, L, P):
    return ((P/L) + (N0 - (P/L)) * np.exp(-L * t))

#menu principal
while True: 
    print("Escolha uma opção de passo para visualizar seu menu de opções: ")
    time.sleep(0.3)
    print("[ 1 ] - h = 0,5")
    time.sleep(0.3)
    print("[ 2 ] - h = 0,1")
    time.sleep(0.3)
    print("[ 3 ] - h = 0,05")
    time.sleep(0.3)
    print("[ 4 ] - Sair do programa...")
    time.sleep(0.3)
    op_func = int(input("Digite a opção: "))

    if op_func == 1: 
        menu_funcao(0.5)
    elif op_func == 2:
        menu_funcao(0.1)
    elif op_func == 3: 
        menu_funcao(0.05)
    elif op_func == 4:
        print("\nEncerrando...")
        break
    else: 
        print("\nDigite uma opção válida.")