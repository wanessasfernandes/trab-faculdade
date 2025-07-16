#include "Fila.h"

void Fila::enfileirar(elemento* elem) {
    lista.inserirNoFim(elem);
}

void Fila::desenfileirar() {
    lista.removerInicio();
}

bool Fila::filaVazia() const {
    return lista.vazia();
}
void Fila::imprimir(){
	lista.imprimirListaCircular();
}

void Fila::topo(){
	lista.imprimirtopo();
}
