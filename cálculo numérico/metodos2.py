import time
import math

def menu(lista, txt): 
    '''
    printa os menus (em formato de lista) de acordo com o título de cada um deles
    '''
    print('\n')
    print('--'*22)
    print(f'{txt}'.center(44))

    for i, item in enumerate(lista, start=1):
        print(f'[ {i} ]  {item}', flush=True)
        time.sleep(0.5)

    print('\n')
    r = int(input('Escolha uma opção e pressione ENTER: ')) # retorna a opção do usuario 

    return r


def função(f, x): # retorna o valor de cada f(x)
    
    if f == 1:
        return x**3 - 7*(x**2) + 14*x - 6

    elif f == 2:
        return x**3 - 2*(x**2) - 3*x + 10
    
    else:
        return x**2 + math.sin(x) - 5


def interpolacao(fx):
    n = int(input("Grau da interpolação (1 para linear, 2 para quadrática): "))
    m = n + 1  # Número de pontos necessários
    
    x = []
    y = []
    
    print("\nDigite os pontos conhecidos:")
    for i in range(m):
        x_val = float(input(f"x[{i}]: "))
        y_val = função(fx, x_val)
        x.append(x_val)
        y.append(y_val)
    
    z = float(input("\nValor a interpolar (z): "))
    
    if n == 1:
        # Interpolação linear
        yz = y[0] + (y[1] - y[0])/(x[1] - x[0]) * (z - x[0])
    elif n == 2:
        # Interpolação quadrática
        L0 = ((z - x[1])*(z - x[2]))/((x[0] - x[1])*(x[0] - x[2]))
        L1 = ((z - x[0])*(z - x[2]))/((x[1] - x[0])*(x[1] - x[2]))
        L2 = ((z - x[0])*(z - x[1]))/((x[2] - x[0])*(x[2] - x[1]))
        yz = y[0]*L0 + y[1]*L1 + y[2]*L2
    
    print(f"\nO valor interpolado é: {yz:.6f}")
    

def interpolacao_lagrange(m, x, y, z):
    '''
    Implementa o método de interpolação de Lagrange
    '''
    r = 0
    for i in range(m):
        c = 1
        d = 1
        for j in range(m):
            if i != j:
                c *= (z - x[j])
                d *= (x[i] - x[j])
        r += y[i] * (c / d)
    print(f"\nO valor interpolado é: {r:.6f}")


def lagrange(fx):
    '''
    Interface para o método de Lagrange
    '''
    m = int(input("Número de pontos conhecidos: "))
    x = []
    y = []
    
    print("\nDigite os pontos conhecidos:")
    for i in range(m):
        x_val = float(input(f"x[{i}]: "))
        y_val = função(fx, x_val)
        x.append(x_val)
        y.append(y_val)
    
    z = float(input("\nValor a interpolar (z): "))
    interpolacao_lagrange(m, x, y, z)


def trapezio(fx):
    while True:
        try:
            a = float(input("Digite o limite inferior de integração: "))
            b = float(input("Digite o limite superior de integração: "))
            if b > a:
                break
            print("Erro: O limite superior deve ser maior que o inferior.")
        except ValueError:
            print("Erro: digite um número válido.")

    while True:
        try:
            m = int(input("Número de subintervalos (mínimo 1): "))
            if m >= 1:
                break
            print("Erro: deve haver pelo menos 1 subintervalo.")
        except ValueError:
            print("Erro: digite um número inteiro válido.")

    def f(x):
        return função(fx, x)

    h = (b - a) / m
    soma = 0.5 * (f(a) + f(b))

    for i in range(1, m):
        soma += f(a + i * h)

    integral = h * soma
    print(f"\nValor da integral aproximada: {integral:.6f}")


def simpson(fx):
    while True:
        try:
            a = float(input("Digite o limite inferior de integração: "))
            b = float(input("Digite o limite superior de integração: "))
            if b > a:
                break
            print("Erro: O limite superior deve ser maior que o inferior.")
        except ValueError:
            print("Erro: digite um número válido.")
    
    # Garante que m seja par
    while True:
        try:
            m = int(input("Número de subintervalos (deve ser par, mínimo 2): "))
            if m >= 2 and m % 2 == 0:
                break
            print("Erro: m deve ser par e ≥ 2.")
        except ValueError:
            print("Erro: digite um número inteiro válido.")

    def f(x):
        return função(fx, x)

    h = (b - a) / m  # Tamanho do subintervalo
    soma = f(a) + f(b)

    for i in range(1, m):
        xi = a + i * h
        if i % 2 == 0:
            soma += 2 * f(xi)
        else:
            soma += 4 * f(xi)

    integral = (h / 3) * soma
    print(f"\nValor da integral aproximada: {integral:.6f}")

while True:
    '''
    Loop principal do programa que exibe o menu e processa as escolhas do usuário 
    '''
    met = menu([
        'Interpolação linear ou quadrática',
        'Forma de Lagrange',
        'Método do Trapézio',
        'Método Simpson 1/3 composto',
        'Sair do programa'
    ], 'Qual método você deseja utilizar?\n')

    if met in [1, 2, 3, 4]:
        fx = menu([
        'f(x) = x³ - 7x² + 14x - 6',
        'f(x) = x³ - 2x² - 3x + 10',
        'f(x) = x² + sen(x) - 5',
        ], 'Qual função você deseja utilizar?\n')
        
        if met == 1:
            interpolacao(fx)
        elif met == 2:
            lagrange(fx)
        elif met == 3:
            trapezio(fx)
        elif met == 4:
            simpson(fx)

    elif met == 5:
        print('Saindo do programa...\n')    
        time.sleep(0.5)
        break

    else:
        print('Opção inválida. Por favor, insira uma opção válida. ')