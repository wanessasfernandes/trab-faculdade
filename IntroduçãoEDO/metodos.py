import numpy as np 
import matplotlib.pyplot as plt
import time

# paramêtros
N0, L, P, tf = 1000, 2.7, 20, 5

# funções principais
def func(t, N):
    return ((-L * N) + P) # eq diferencial modelo

def metodoEuler(h):
    t = np.arange(0, tf + h, h) # vetor de tempo com cada passo
    N = np.zeros(len(t))        # vetor de resultados
    N[0] = N0                   # condição inicial

    for i in range(1, len(t)): # calcula as iterações do método de Euler
        N[i] = N[i-1] + h * func(t[i-1], N[i-1]) # atualização de Euler

    return t, N

def metodoRungeKutta(h):
    t = np.arange(0, tf + h, h) # vetor de tempo com cada passo
    N = np.zeros(len(t))        # vetor de resultados
    N[0] = N0                   # condição inicial
    
    for i in range(1, len(t)): # calcula as iterações do método de Runge-Kutta
        k1 = func(t[i-1], N[i-1])
        k2 = func(t[i-1] + (h/2), N[i-1] + ((h/2) * k1))
        k3 = func(t[i-1] + (h/2), N[i-1] + ((h/2) * k2))
        k4 = func(t[i-1] + h, N[i-1] + (h * k3))
        
        N[i] = N[i-1] + ((h/6) * (k1 + (2 * k2) + (2 * k3) + k4)) # atualização de Runge-Kutta

    return t, N

def solAnalitica(t):
    return ((P/L) + (N0 - (P/L)) * np.exp(-L * t)) # eq diferencial resolvida analíticamente

# menu secundário
def menu_funcao(h, metodo):
    from metodos import metodoEuler, metodoRungeKutta, solAnalitica
    
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

        t, N_metodo = metodoEuler(h) if metodo == "Euler" else metodoRungeKutta(h)
        N_exato = solAnalitica(t)
        desvio = abs((N_metodo - N_exato) / N_exato) * 100 # calculo do desvio
    
        if op_menu == 1:  # exibe os resultados
            print(f"\n{'Iteração':^12}{'t (dias)':^12}{'Numérica':^16}{'Analítica':^16}{'Desvio (%)':^15}")
            print("-"*70)
            for i in range(len(t)):
                time.sleep(0.1)
                print(f"{i:^10}|{t[i]:^12.2f}|{N_metodo[i]:^15.4f}|{N_exato[i]:^15.4f}|{desvio[i]:^12.2f}")

        elif op_menu == 2:  # plota o gráfico de comparação entre as soluções em cada passo
            plt.figure(figsize=(7,4))
            plt.plot(t, N_exato, label="Solução Analítica", linestyle='-', color="#6699CC")
            plt.plot(t, N_metodo, label=f"Solução Numérica ({metodo})", marker='o', linestyle='-.', markersize=5, color="#CB5165")
            plt.title(f"Soluções para h = {h}")
            plt.xlabel("Tempo (dias)")
            plt.ylabel("Número de núcleos")
            plt.legend()
            plt.grid(True)
            plt.show()
        
        elif op_menu == 3:  # plota o gráfico do desvio de cada passo
            plt.figure(figsize=(7,4))
            plt.plot(t, desvio, marker='o', linestyle='--', markersize=5, color='red')
            plt.title(f"Desvio Relativo Percentual do passo: h = {h}")
            plt.xlabel("Tempo (dias)")
            plt.ylabel("Desvio (%)")
            plt.grid(True)
            plt.show()

        elif op_menu == 4:
            print("\nVoltando...")
            break

        else:
            print("\nOpção inválida.")