import numpy as np
import time
import matplotlib.pyplot as plt

# Funções
def f(x):
    return (1 - x[0])**2 + 100*(x[1] - (x[0]**2))**2

def g(x):
    return np.cos(x[0]) + np.sin(x[1])


def nelder_mead(func, pontos, tol=1e-6, max_iteracao=200, alpha=1, gamma=2, beta=0.5, sigma=0.5):
    
    simplex = [np.array(p, dtype=float) for p in pontos]
    simplex_inicial = simplex.copy() # para guardar o simplex inicial
    
    hist_f = [func(simplex[0])]
    hist_x = [np.array(simplex[0])]
    
    for iteracao in range(max_iteracao):
        # Ordenação
        vf = [func(v) for v in simplex]                        # valores da função
        indices = sorted(range(len(vf)), key=lambda i: vf[i])  # ordena pelos valores
        simplex = [simplex[i] for i in indices]                # reordena os pontos
        vf = [vf[i] for i in indices]                          # reordena os valores
        
        # Vértices e Funções
        xl, fxl = simplex[0], vf[0]    # melhor
        xs, fxs = simplex[-2], vf[-2]  # segundo pior
        xn, fxn = simplex[-1], vf[-1]  # pior
                
        hist_x.append(xl.copy())
        hist_f.append(fxl)

        if np.std(vf) < tol:
            break

        # Cálculo do centróide (sem o pior vértice (xn))
        centroid = np.mean(simplex[:-1], axis=0)

        # Reflexão
        xr = centroid + alpha * (centroid - xn)
        fxr = func(xr)

        if fxs > fxr >= fxl:
            simplex[-1] = xr
            continue

        # Expansão
        elif fxr < fxl:
            xe = centroid + gamma * (xr - centroid)
            fxe = func(xe)
            
            if fxe < fxr:
                simplex[-1] = xe
            else:
                simplex[-1] = xr
            continue

        # Contração
        else:
            xc = centroid + beta * (xn - centroid)
            fxc = func(xc)
                
            if fxc < fxn:
                simplex[-1] = xc
                
            # Concentração escolhida
            else:
                for i in range(1, len(simplex)):
                    simplex[i] = xl + sigma * (simplex[i] - xl)
                    
    # Centroide e nomes dos pontos finais
    centroide_final = np.mean(simplex[:-1], axis=0)
    nome_pontos = {'xl': xl, 'xs': xs, 'xn': xn}

    return xl, func(xl), iteracao + 1, hist_x, hist_f, simplex_inicial, simplex, centroide_final, nome_pontos
    
    
def graf_simplex_inicial(simplex_inicial, titulo="Simplex Inicial"):
    plt.figure(figsize=(6,6))

    xs_i = [p[0] for p in simplex_inicial] + [simplex_inicial[0][0]]
    ys_i = [p[1] for p in simplex_inicial] + [simplex_inicial[0][1]]
    plt.plot(xs_i, ys_i, 'o-', color='lightcoral', label="Simplex inicial")

    # Pontos iniciais
    for i, p in enumerate(simplex_inicial):
        plt.text(p[0]+0.02, p[1]+0.02, f"p{i+1}", fontsize=12, color='indigo')

    plt.xlabel("x₁")
    plt.ylabel("x₂")
    plt.title(titulo)
    plt.legend()
    plt.grid(True)
    plt.show()


def graf_simplex_final(simplex_final, centroide, nome_pontos=None, titulo="Simplex Final"):
    plt.figure(figsize=(6,6))

    xs_f = [p[0] for p in simplex_final] + [simplex_final[0][0]]
    ys_f = [p[1] for p in simplex_final] + [simplex_final[0][1]]
    plt.plot(xs_f, ys_f, 'o-', color='lightcoral', label="Simplex final")

    # Centroide final
    plt.scatter(centroide[0], centroide[1], color='indigo', s=50, label="Centroide final")

    # xl, xs, xn
    if nome_pontos:
        for nome, ponto in nome_pontos.items():
            plt.text(ponto[0]+0.02, ponto[1]+0.02, nome, fontsize=12, color='indigo')

    plt.xlabel("x₁")
    plt.ylabel("x₂")
    plt.title(titulo)
    plt.legend()
    plt.grid(True)
    plt.show()


def graf_conv(hist_f, titulo):
    plt.figure(figsize=(7, 5))
    plt.plot(range(len(hist_f)), hist_f, marker='.', linestyle='-')
    plt.title(titulo)
    plt.xlabel("Iteração")
    plt.ylabel("Valor da Função f(x)")
    plt.grid(True)
    
    try:
        if min(hist_f) > 0:
            plt.yscale('log')
        else:
            plt.yscale('linear')
            
    except:
        plt.yscale('linear')
    
    plt.show()


# Menu principal
while True:
    print("Escolha uma função para visualizar seu menu: ")
    time.sleep(0.3)
    print("[ 1 ] - f(x₁, x₂) = (1 - x₁)² + 100(x₂ - x₁²)²")
    time.sleep(0.3)
    print("[ 2 ] - g(x₁, x₂) = cos(x₁) + sen(x₂)")
    time.sleep(0.3)
    print("[ 3 ] - Sair do programa...")
    time.sleep(0.3)
    try:
        op_func = int(input("Digite a opção: "))
    except ValueError:
        print("\nOpção inválida. Por favor, digite um número.")
        continue

    if op_func in [1, 2]:
        while True:
            funcao = f if op_func==1 else g
            nome = "f(x₁, x₂) = (1 - x₁)² + 100(x₂ - x₁²)²" if op_func==1 else "g(x₁, x₂) = cos(x₁) + sen(x₂)"
            variavel = "f(x₁, x₂)" if op_func==1 else "g(x₁, x₂)"
            
            print(f"\nMenu da função {nome}")
            time.sleep(0.3)
            print("[ 1 ] - Resultado Final")
            time.sleep(0.3)
            print("[ 2 ] - Gráfico da função")
            time.sleep(0.3)
            print("[ 3 ] - Gráfico da convergência")
            time.sleep(0.3)
            print("[ 4 ] - Voltar")
            time.sleep(0.3)
            try:
                op_menu = int(input("Digite a opção: "))
            except ValueError:
                print("\nOpção inválida. Por favor, digite um número.")
                continue

            if op_menu in [1, 2, 3]:
                try:
                    print("\nDigite as coordenadas (x, y) para os 3 pontos iniciais do simplex: ")
                    p1_x = float(input("\nPonto 1 - x₁: "))
                    p1_y = float(input("Ponto 1 - x₂: "))
                    p2_x = float(input("\nPonto 2 - x₁: "))
                    p2_y = float(input("Ponto 2 - x₂: "))
                    p3_x = float(input("\nPonto 3 - x₁: "))
                    p3_y = float(input("Ponto 3 - x₂: "))
                    
                    pontos = [[p1_x, p1_y], [p2_x, p2_y], [p3_x, p3_y]]
                    minimo, fmin, it, hist_x, hist_f, simplex_inicial, simplex_final, centroide_final, nome_pontos = nelder_mead(funcao, pontos)
                    
                except Exception as e:
                    print(f"Ocorreu um erro: {e}")
                    continue

                if op_menu == 1:
                    print(f"\nResultado: x = {minimo}, {variavel} = {fmin:.6f}, iterações = {it}")
                elif op_menu == 2:
                    graf_simplex_inicial(simplex_inicial, f"{variavel} - Simplex Inicial")
                    graf_simplex_final(simplex_final, centroide_final, nome_pontos, f"{variavel} - Simplex Final")
                elif op_menu == 3:
                    graf_conv(hist_f, f"Convergência do Simplex para {variavel}")

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