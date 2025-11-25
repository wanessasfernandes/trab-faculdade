from metodos import menu_funcao
import time

# menu principal
while True:
    print("\nSelecione o método numérico:")
    time.sleep(0.3)
    print("[ 1 ] - Método de Euler")
    time.sleep(0.3)
    print("[ 2 ] - Método de Runge-Kutta de 4ª Ordem")
    time.sleep(0.3)
    print("[ 3 ] - Sair do programa...")
    time.sleep(0.3)
    op_metodo = int(input("Digite a opção: "))

    # para escolher o método númerico e definir o passo
    if op_metodo in [1, 2]:
        metodo = "Euler" if op_metodo == 1 else "Runge-Kutta"

        while True:
            print(f"\nEscolha o passo para o método de {metodo}:")
            time.sleep(0.3)
            if metodo == "Euler":
                print("[ 1 ] - h = 0,5\n[ 2 ] - h = 0,1\n[ 3 ] - h = 0,05\n[ 4 ] - Voltar")
            else:
                print("[ 1 ] - h = 1,0\n[ 2 ] - h = 0,5\n[ 3 ] - h = 0,1\n[ 4 ] - Voltar")
            time.sleep(0.3)
            op_h = int(input("Digite a opção: "))

            if metodo == "Euler":
                passos = {1: 0.5, 2: 0.1, 3: 0.05}
            else:
                passos = {1: 1.0, 2: 0.5, 3: 0.1}

            if op_h in passos:
                menu_funcao(passos[op_h], metodo)
            elif op_h == 4:
                print("\nVoltando ao menu principal...")
                break
            else:
                print("\nDigite uma opção válida.")

    elif op_metodo == 3:
        print("\nEncerrando...")
        break
    else:
        print("\nDigite uma opção válida.")