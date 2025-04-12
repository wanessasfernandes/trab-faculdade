import numpy as np
import matplotlib.pyplot as plt

# importando as funcoes e as variáveis necessárias
from functions import (
    polinomio,
    modelo,
)
from functions import (
    Vx,
    Dy,
    coef_a,
    velocidade_otima,
    arrasto_minimo,
    velocidade_otima_modelo,
    arrasto_minimo_modelo,
    erro_fornecido,
    erro_ajustado,
    desvio_fornecido,
    desvio_ajustado,
)

# exibicao dos resultados obtidos durante todo o processo
print("\n" + "-"*80)
print(f"\n- Coeficientes calculados:\n\ta0 = {coef_a[0][0]}\n\ta1 = {coef_a[1][0]}\n\ta2 = {coef_a[2][0]}\n\ta3 = {coef_a[3][0]}\n\ta4 = {coef_a[4][0]}\n")
print(f"- Função de Regressão Polinomial de grau 4:\n\n\ty = {float(coef_a[0][0]):.2f} + ({float(coef_a[1][0]):.2f}) * x^1 + {float(coef_a[2][0]):.2f} * x^2 + ({float(coef_a[3][0]):.2f}) * x^3 + {float(coef_a[4][0]):.2e} * x^4")

print("\n" + "-"*80)

print("\nResultados em relação a equação modelo:\n")
print(f"- Velocidade ótima que minimiza o arrasto: {velocidade_otima_modelo:.2f} m/s")
print(f"- Valor mínimo total do arrasto: {arrasto_minimo_modelo:.2f} N")
print("\n\nResultados em relação ao polinômio de grau 4:\n")
print(f"- Velocidade ótima que minimiza o arrasto: {velocidade_otima:.2f} m/s")
print(f"- Valor mínimo total do arrasto: {arrasto_minimo:.2f} N")

print("\n" + "-"*80)

print(f"\nEMQ referente ao modelo fornecido: {erro_fornecido:.4f}")
print(f"EMQ referente ao modelo ajustado (Polinômio de Grau 4): {erro_ajustado:.4f}")

print("\n" + "-"*80 + "\n")

print(f"{'Desvio Fornecido':>17} | {'Desvio Ajustado':>17}")
for d_for, d_aju in zip(desvio_fornecido, desvio_ajustado):
    print(f"{d_for:17.2f} | {d_aju:17.2f}")

print("\n" + "-"*80 + "\n")

# estrutura de repeticao para visulizacao dos graficos dispostos
while(True):
    opcao = int(input("Escolha uma das opções a baixo para visualizar:\n  1 - Gráfico ajustado a partir do polinômio\n  2 - Gráfico das curvas sobrepostas\n  3 - Encerrar sessão\nQual será a opção: "))

    if opcao > 0 and opcao < 4:
        if opcao == 1:
            Vx_plot = np.linspace(300, 700, 500)
            Dy_ajustado = [polinomio(V) for V in Vx_plot]

            plt.scatter(Vx, Dy, label='Dados originais', color='lightcoral')
            plt.plot(Vx_plot, Dy_ajustado, label=f'Polinômio de grau 4', color='indigo')
            plt.axvline(velocidade_otima, linestyle='--', label=f'V ótima = {velocidade_otima:.2f} m/s', color='violet')
            plt.scatter([velocidade_otima], [arrasto_minimo], label=f' Ponto Mínimo', color='teal')

            plt.xlabel('Velocidade (m/s)')
            plt.ylabel('Arrasto (N)')
            plt.title('Arrasto Total x Velocidade Ótima')
            plt.legend()
            plt.grid()
            plt.show()
            
            print("\n")
        
        if opcao == 2:
            Vx_plot = np.linspace(300, 700, 500)
            Dy_ajustado = [polinomio(V) for V in Vx_plot]
            Dy_modelo = [modelo(V) for V in Vx_plot]
            
            plt.plot(Vx_plot, Dy_ajustado, label=f'Polinômio Ajustado', color='indigo')
            plt.plot(Vx_plot, Dy_modelo, label=f'Função Modelo', color='lightcoral')
            
            plt.scatter([velocidade_otima], [arrasto_minimo], label=f' Ponto Mínimo Ajustado', color='teal')
            plt.scatter([velocidade_otima_modelo], [arrasto_minimo_modelo], label=f' Ponto Mínimo Modelo', color='crimson')
            
            plt.xlabel('Velocidade (m/s)')
            plt.ylabel('Arrasto (N)')
            plt.title('Modelo x Aproximado')
            plt.legend()
            plt.grid()
            plt.show()
            
            print("\n")
        
        if opcao == 3:
            break

# fim
print("\n" + "-"*80)
print("\nFeito por:\n\n\t Maria Eduarda Bonan Silva - 202410331011\n\t Wanessa de Souza Fernandes - 202410331211\n\n")