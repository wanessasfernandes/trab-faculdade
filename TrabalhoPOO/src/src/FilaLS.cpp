#include "FilaLS.h"

#include <iostream>
using namespace std;
Filals::Filals(int capacidade) : lista(capacidade) {}

bool Filals::enfileirar(elemento* e) {
	if(filaCheia()) {
		cout << "A fila está cheia!\n";
		return false;
	}
	
    return lista.InserirNoFinal(e);
}

elemento* Filals::desenfileirar() {
    if (filaVazia()) {
        cout << "A fila está vazia.\n";
        return NULL;
    }
    
    lista.RemoverPrimeiro();
}

elemento* Filals::consultarFrente() {
    if (filaVazia()) {
    	cout << "A fila está vazia!\n";
        return NULL;
    }
    // primeiro elemento
    return lista.BuscarPeloId(0);
}

bool Filals::filaCheia() const {
    return lista.EstaCheia();
}

bool Filals::filaVazia() const {
    return lista.EstaVazia();
}

void Filals::imprimir() {
    lista.Imprimir();
}
