import time
import math

def menu(lista, txt): 
    '''
    printa os menus (que eu fiz em formato de lista) de acordo com o título de cada um deles
    '''
    print('\n')
    print('--'*22)
    print(f'{txt}'.center(44))

    for i, item in enumerate(lista, start=1):
        print(f'[ {i} ]  {item}', flush=True)
        time.sleep(0.5)

    print('\n')    
    r = int(input('Escolha uma opção e pressione ENTER: ')) #retorna a opção do usuario 

    return r

def função(f, x):
    '''
    retorna o valor de cada entrada, fiz assim pra poder reaproveitar em todos os métodos 
    e f é o numero da opção
    '''
    if f == 1:
        return x**3 - 7*(x**2) + 14*x - 6

    elif f == 2:
        return x**3 - 2*(x**2) - 3*x + 10
    
    else:
        return x**2 + math.sin(x) - 5


def bisseção(f): #recebe só o parametro de qual a função o usuário quer 

    print('\n')
    a = float(input('Insira um valor para o intervalo inferior: '))
    b = float(input('Insira um valor para o intervalo supeior: '))
    e = float(input('Insira um valor para a precisão: '))
    iteração = 0

    while math.fabs(b - a) > e:

        m = (a + b) / 2
        fa = função(f, a)
        fb = função(f, b)
        fm = função(f, m)

        print(f'\nIteração {iteração}: ')
        print(f'a = {a:.6f}, f(a) = {fa:.6f}') 
        time.sleep(0.3)
        print(f'b = {b:.6f}, f(b) = {fb:.6f}') 
        time.sleep(0.3)
        print(f'x = {m:.6f}, f(x) = {fm:.6f}') 
        time.sleep(0.3)
        print(f'(b-a) = {math.fabs(b - a)}\n')
        time.sleep(0.3)
            
        iteração += 1

        if (fa * fm < 0):
            b = m

        else:
            a = m 

    raiz = (a + b)/2
    print(f'\nA raiz aproximada é {raiz:.6f} com precisão {e}')    
    time.sleep(1)


while True:
    '''
    Loop principal do programa que exibe o menu e processa as escolhas do usuário 
    '''
    met = menu([
        'Bisseção',
        'Newton-Raphson',
        'Secante',
        'Sair do programa'
    ], 'Qual função você deseja utilizar?\n')

    if met == 1:
        fx = menu([
        'f(x) = x³ - 7x² + 14x - 6',
        'f(x) = x³ - 2x² - 3x + 10',
        'f(x) = x² + sen(x) - 5',
        ], 'Qual método você deseja utilizar?\n')
        
        bisseção(fx)

    elif met == 4:
        print('Saindo do programa...\n')    
        time.sleep(0.5)

    else:
        print('Opção inválida. Por favor, insira uma opção válida. ')    








