#include "PilhaLS.h"
#include <iostream>

 using namespace std;
 
Pilhals::Pilhals(int capacidade) : lista(capacidade) {}

bool Pilhals::empilhar(elemento* e) {
	if(pilhaCheia()) {
		cout << "A pilha está cheia!\n";
		return false;
	}
	
    return lista.InserirNoFinal(e);
}

void Pilhals::desempilhar() {
	if(pilhaVazia()) {
		cout << "A pilha está vazia!\n";
	}
	else{
	 lista.RemoverUltimo();
	}
}

void Pilhals::consultarTopo() const {
    if (pilhaVazia()) {
		cout << "A pilha está vazia!\n";
	}
    else{
    	lista.Getinformation(lista.GetTamanho() - 1);
	}
}

bool Pilhals::pilhaCheia() const {
    return lista.EstaCheia();
}

bool Pilhals::pilhaVazia() const {
    return lista.EstaVazia();
}

void Pilhals::Imprimir(){
    lista.Imprimir();
}

