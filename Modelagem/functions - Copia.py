import numpy as np
import matplotlib.pyplot as plt

# dados disponibilizados
Vx = np.array([300.0, 320.0, 340.0, 360.0, 380.0, 400.0, 420.0, 440.0, 460.0, 480.0, 500.0, 520.0, 540.0, 560.0, 580.0, 600.0, 620.0, 640.0, 660.0, 680.0, 700.0])
Dy = np.array([5002.39, 4596.20, 4256.56, 3889.62, 3661.76, 3542.03, 3344.48, 3246.15, 3255.30, 3243.25, 3137.67, 3155.84, 3142.69, 3064.64, 3213.86, 3321.36, 3382.10, 3439.77, 3506.81, 3721.41, 3681.15])

# para obter o tamanho do vetor
n = len(Vx)

# calculando a partir dos dados os somatorios de xi^k, com k de 0 a 10
xi = [sum(Vx[i] ** k for i in range(n)) for k in range(9)]

# o mesmo será feito para obter os somatorios relacionados a yi, e tambem yixi^k, com k de 0 a 5
yi = sum(Dy)
yixi = [sum(Dy[i] * (Vx[i] ** k) for i in range(n)) for k in range(5)]

# seguindo a logica AX = B
# utilizando os dados obtidos para criar a matriz a
A = np.array([
    [xi[0], xi[1], xi[2], xi[3], xi[4]],
    [xi[1], xi[2], xi[3], xi[4], xi[5]],
    [xi[2], xi[3], xi[4], xi[5], xi[6]],
    [xi[3], xi[4], xi[5], xi[6], xi[7]],
    [xi[4], xi[5], xi[6], xi[7], xi[8]],
])

# utilizando os dados obtidos para criar a matriz b
B = np.array([
    [yi],
    [yixi[1]],
    [yixi[2]],
    [yixi[3]],
    [yixi[4]],
])

# calcula o sistema linear para obter os coeficientes de a
coef_a = np.linalg.solve(A, B)

# função de previsão utilizando os coeficientes encontrados
def polinomio(V):
    return (
        coef_a[0] * (V ** 0) + coef_a[1] * (V ** 1) + coef_a[2] * (V ** 2) + coef_a[3] * (V ** 3) + coef_a[4] * (V ** 4)
    )[0] # para extrair o valor
# forma um equacao semelhente a: y = a0 + a1 * x^1 + a2 * x^2 + a3 * x^3 + a4 * x^4
ncoef = len(coef_a)


# funcao para calcular o arrasto a partir da equacao disponibilizada
def modelo(V):
    return 0.01 * 0.6 * V**2 + (0.95 / 0.6) * (16000 / V)**2


# utilizando a razao aurea para encontrar a velocidade otima que fornece o minimo arrasto total
def secao_aurea(f, a, b, tol):
    R = (np.sqrt(5) - 1) / 2
    d = b - a
    
    x1 = b - R * d
    x2 = a + R * d
    f1 = f(x1)
    f2 = f(x2)

    # Loop principal do método para atualiza-la
    while abs(b - a) > tol:
        if f1 > f2:
            a = x1
            x1 = x2
            f1 = f2
            x2 = a + R * (b - a)
            f2 = f(x2)
        else:
            b = x2
            x2 = x1
            f2 = f1
            x1 = b - R * (b - a)
            f1 = f(x1)

    # Retorna o ponto minimo e o arrasto total
    x_min = (a + b) / 2
    f_min = f(x_min)
    return x_min, f_min

velocidade_otima, arrasto_minimo = secao_aurea(polinomio, 300, 700, 1e-6)
velocidade_otima_modelo, arrasto_minimo_modelo = secao_aurea(modelo, 300, 700, 1e-6)

# funcao para calcular o erro medio quadratico da raiz
def erro_mq(y_modelo, y_calculado):
    erro = np.sqrt(np.mean((y_modelo - y_calculado) ** 2))
    return erro

m_fornecido = modelo(Vx)
m_ajustado = polinomio(Vx)

erro_fornecido = erro_mq(Dy, m_fornecido)
erro_ajustado = erro_mq(Dy, m_ajustado)

desvio_fornecido = Dy - m_fornecido
desvio_ajustado = Dy - m_ajustado