#include "Pilha.h"

void Pilha::empilhar(elemento* elem) {
    lista.inserirNoFim(elem);
}

void Pilha::desempilhar() {
    lista.removerFim();
}

bool Pilha::pilhaVazia() const {
    return lista.vazia();
}

void Pilha::ultimo() {
	lista.imprimirultimo();
}

void Pilha::imprimir(){
	lista.imprimirListaCircular();
}
