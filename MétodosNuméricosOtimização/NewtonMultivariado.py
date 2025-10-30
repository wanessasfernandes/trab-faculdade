import sympy as sp
import numpy as np 
import matplotlib.pyplot as plt
import time

def menu_funcao(func, expr, nome):
    while True: 
        print(f"\nMenu da função {nome}(x₁, x₂) = {expr}")
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
            x1 = float(input("\nDigite o chute inicial x₁: "))
            x2 = float(input("Digite o chute inicial x₂: "))
            minimo, iteracao = NewtonMult(x1, x2, func, grad_f, hess_f)
            if minimo is not None:
                print(f"O resultado é X = [{minimo[0]:.3f}, {minimo[1]:.3f}]")

        elif op_menu == 2:
            x1 = float(input("\nDigite o chute inicial x₁: "))
            x2 = float(input("Digite o chute inicial x₂: "))
            xmin, iteracao = NewtonMult(x1, x2, func, grad_f, hess_f)
            graf(func, xmin, f"{nome}(x₁, x₂) = {expr}")
        
        elif op_menu == 3:
            x1 = float(input("\nDigite o chute inicial x₁: "))
            x2 = float(input("Digite o chute inicial x₂: "))
            xmin, iteracao = NewtonMult(x1, x2, func, grad_f, hess_f)
            graf_erro(iteracao)

        elif op_menu == 4:
            print("\nVoltando ao menu principal...\n")  
            break  

        else: 
            print("\nOpção inválida.") 

# Definições das funções
x1 = sp.Symbol('x1')
x2 = sp.Symbol('x2')
fx = (x1 - 2)**4 + (x1 - 2*x2)**2
gx = sp.cos(x1) + 2*sp.sin(x2)

#calculo do gradiente
def grad_f(func, x):
    x1_val, x2_val = x
    x1, x2 = sp.symbols('x1 x2')
    grad_x1 = sp.lambdify((x1,x2), sp.diff(func, x1), 'numpy')
    grad_x2 = sp.lambdify((x1,x2), sp.diff(func, x2), 'numpy')
    return np.array([grad_x1(x1_val, x2_val), grad_x2(x1_val, x2_val)])

#calculo da hessiana
def hess_f(func, x):
    x1_val, x2_val = x
    x1, x2 = sp.symbols('x1 x2')
    h11 = sp.lambdify((x1,x2), sp.diff(func, x1, x1), 'numpy')
    h12 = sp.lambdify((x1,x2), sp.diff(func, x1, x2), 'numpy')
    h21 = sp.lambdify((x1,x2), sp.diff(func, x2, x1), 'numpy')
    h22 = sp.lambdify((x1,x2), sp.diff(func, x2, x2), 'numpy')
    return np.array([[h11(x1_val, x2_val), h12(x1_val, x2_val)],
                     [h21(x1_val, x2_val), h22(x1_val, x2_val)]])

def NewtonMult(x1, x2, func, grad_f, hess_f, e=1e-6, max_i=100):

    xk = np.array([x1, x2], dtype=float)
    hist = [xk.copy()]

    for i in range(max_i):
        gk = grad_f(func, xk)
        hk = hess_f(func, xk)

        #verifica se a Hessiana é invertível
        if np.linalg.det(hk) == 0:
            print("Hessiana singular. O método não pode prosseguir.")
            return None, hist

        #passo de Newton 
        hk_inv = np.linalg.inv(hk)
        xk1 = xk - np.dot(hk_inv, gk)

        hist.append(xk1.copy())

        #critério de parada
        if np.linalg.norm(xk1 - xk) < e:
            print(f"\nConvergência alcançada em {i+1} iterações.")
            return xk1, hist

        xk = xk1

    print("\nNúmero máximo de iterações atingido.")
    return xk, hist

#fnção para plotar gráfico da função
def graf(func_expr, xmin, nome_func, intervalo=(-5,5), num_points=100):
    x1, x2 = sp.symbols('x1 x2')
    func = sp.lambdify((x1, x2), func_expr, 'numpy')  # converte a expressão

    #criar a grade de pontos
    X1 = np.linspace(intervalo[0], intervalo[1], num_points)
    X2 = np.linspace(intervalo[0], intervalo[1], num_points)
    X1_grid, X2_grid = np.meshgrid(X1, X2)

    #avaliar a função em todos os pontos
    Z = func(X1_grid, X2_grid)

    #criar o gráfico 3D
    fig = plt.figure(figsize=(10,7))
    ax = fig.add_subplot(111, projection='3d')
    ax.plot_surface(X1_grid, X2_grid, Z, cmap='viridis', alpha=0.8)

    #marcar o mínimo
    z_min = func(*xmin)
    ax.scatter(xmin[0], xmin[1], z_min, color='red', s=50, label=f'Mínimo ({xmin[0]:.2f}, {xmin[1]:.2f}, {z_min:.2f})')

    ax.set_xlabel('x1')
    ax.set_ylabel('x2')
    ax.set_zlabel('f(x1, x2)')
    ax.set_title(f'Gráfico 3D da função {nome_func}')
    ax.legend()
    plt.show()

# Gráfico do erro por iteração
def graf_erro(iteracao):
    if len(iteracao) < 2:
        print("Poucos dados para plotar erro.")
        return

    erro = [np.linalg.norm(iteracao[i+1] - iteracao[i]) for i in range(len(iteracao)-1)]
    iteracoes = range(1, len(erro)+1)

    plt.plot(iteracoes, erro, marker='o', color='indigo')
    plt.yscale("log")
    plt.xlabel("Iteração")
    plt.ylabel("Erro (norma)")
    plt.title("Erro a cada iteração")
    plt.grid(True, which="both", linestyle="--", alpha=0.6)
    plt.show()

# Menu principal
while True:
    print("Escolha uma função para visualizar seu menu: ")
    time.sleep(0.3)
    print("[ 1 ] - f(x₁, x₂) = (x₁-2)⁴ + (x₁ - 2x₂)²")
    time.sleep(0.3)
    print("[ 2 ] - g(x₁, x₂) = cos(x₁) + 2*sin(x₂)")
    time.sleep(0.3)
    print("[ 3 ] - Sair do programa...")
    time.sleep(0.3)
    op_func = int(input("Digite a opção: "))

    if op_func == 1:
        menu_funcao(fx, "(x₁-2)⁴ + (x₁ - 2x₂)²", "f")

    elif op_func == 2:
        menu_funcao(gx, "cos(x₁) + 2*sin(x₂)", "g")

    elif op_func == 3:    
        print("\nEncerrando...")
        break

    else:
        print("\nInsira uma opção válida.")

print("\n" + "-"*80)
print("\nFeito por:\n\n\t Maria Eduarda Bonan Silva - 202410331011\n\t Wanessa de Souza Fernandes - 202410331211\n\n")  
