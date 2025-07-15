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
    retorna o valor de cada f(x)
    '''
    if f == 1:
        return x**3 - 7*(x**2) + 14*x - 6

    elif f == 2:
        return x**3 - 2*(x**2) - 3*x + 10
    
    else:
        return x**2 + math.sin(x) - 5


def derivada(f, x):
    '''
    derivadas manuais para utilizar no método de newton
    '''
    if f == 1:
        return 3*(x**2) - 14*x + 14

    elif f == 2:
        return 3*(x**2) - 4*x - 3
    
    else:
        return 2*x + math.cos(x)


def bisseção(f):

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


def newton(f):
    
    print('\n')
    x = float(input('Insira um valor inicial (X₀): '))
    e = float(input('Insira um valor para a precisão: '))
    max_iteração = int(input('Insira um n° máximo de iterações: '))
    iteração = 1
    erro = e + 1
    
    while erro > e and iteração < max_iteração:
        fx = função(f, x)
        dfx = derivada(f, x)
        
        if dfx != 0:
            xi = x - (fx / dfx)
            erro = abs(xi - x)
            
            print(f'\nIteração {iteração}: ')
            print(f'x = {x:.6f}, f(x) = {fx:.6f}')
            time.sleep(0.3)
            print(f'erro = {erro:.6f}')
            time.sleep(0.3)
            
            x = xi
            iteração += 1
            
        else:
            print('Derivada zero. Encerrando...')
            break
    
    if erro <= e:  
        print(f'\nA raiz aproximada é {xi:.6f} com precisão {e}')    
    else:
        print('\nNúmero máximo de iterações atingido.')
        print(f'Última aproximação: x = {x:.6f}, erro = {erro:.6f}')
        time.sleep(0.3)
    
    time.sleep(1)


def secante(f):
    
    print('\n')
    x0 = float(input('Insira um valor para o intervalo inferior (X₀): '))
    x1 = float(input('Insira um valor para o intervalo superior (X₁): '))
    e = float(input('Insira um valor para a precisão: '))
    max_iteração = int(input('Insira um n° máximo de iterações: '))
    iteração = 1
    erro = e + 1
    
    while erro > e and iteração < max_iteração:
        f0 = função(f, x0)
        f1 = função(f, x1)
        
        if (f1 - f0) != 0:
            x2 = x1 - ((f1 * (x1 - x0)) / (f1 - f0))
            erro = abs(x2 - x1)
            
            print(f'\nIteração {iteração}: ')
            print(f'x = {x2:.6f}, f(x) = {função(f, x2):.6f}')
            time.sleep(0.3)
            print(f'erro = {erro:.6f}')
            time.sleep(0.3)
            
            x0 = x1
            x1 = x2
            iteração += 1
                      
        else:
            print('Divisão igual a zero. Encerrando...')
            break
    
    if erro <= e:  
        print(f'\nA raiz aproximada é {x1:.6f} com precisão {e}')    
    else:
        print('\nNúmero máximo de iterações atingido.')
        print(f'Última aproximação: x = {x1:.6f}, erro = {erro:.6f}')
        time.sleep(0.3)
    
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
    ], 'Qual método você deseja utilizar?\n')

    if met in [1, 2, 3]:
        fx = menu([
        'f(x) = x³ - 7x² + 14x - 6',
        'f(x) = x³ - 2x² - 3x + 10',
        'f(x) = x² + sen(x) - 5',
        ], 'Qual método você deseja utilizar?\n')
        
        if met == 1:
            bisseção(fx)
        elif met == 2:
            newton(fx)
        elif met == 3:
            secante(fx)

    elif met == 4:
        print('Saindo do programa...\n')    
        time.sleep(0.5)
        break

    else:
        print('Opção inválida. Por favor, insira uma opção válida. ')