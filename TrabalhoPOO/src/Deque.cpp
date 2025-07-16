#include "Deque.h"

void Deque::inserirFrente(elemento* elem) {
    lista.inserirNoInicio(elem);
}

void Deque::inserirTras(elemento* elem) {
    lista.inserirNoFim(elem);
}

void Deque::removerFrente() {
    lista.removerInicio();
}

void Deque::removerTras() {
  lista.removerFim();
}

bool Deque::dequeVazio() const {
    return lista.vazia();
}

void  Deque::imprimir_inicio(){
	lista.imprimirtopo();
}

void Deque::imprimir_ultimo(){
	lista.imprimirultimo();
}
