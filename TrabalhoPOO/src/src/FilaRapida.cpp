#include "FilaRapida.h"
#include <iostream>

using namespace std;

FilaRapida::FilaRapida(int capacidade) : lista(capacidade), frente(NULL), final(NULL) {}

bool FilaRapida::enfileirar(elemento* e) {
    if (filaCheia()) {
        cout << "A fila está cheia!\n";
        return false;
    }
    
    if(filaVazia())
    	frente = e; // primeiro elemento da fila
    else
    	final = e;  // aponta o novo elemento
    
    return lista.InserirNoFinal(e);
}

void FilaRapida::desenfileirar() {
    if (filaVazia()) {
        cout << "A fila está vazia!\n";
    }
    else{
	    elemento* removido = frente;  // remove o primeiro elemento
	    
	    if (lista.GetTamanho() > 1) {
	        frente = lista.BuscarPeloId(1); // próximo elemento
	    } else {
	        frente = NULL;
	        final = NULL;
	    }
	    lista.RemoverPrimeiro();
	}
}

elemento* FilaRapida::consultarFrente() {
    if (filaVazia()) {
    	cout << "A fila está vazia!\n";
        return NULL;
    }
    
    return frente;
}

bool FilaRapida::filaCheia() const {
    return lista.EstaCheia();
}

bool FilaRapida::filaVazia() const {
    return lista.EstaVazia();
}

void FilaRapida::imprimir() {
    lista.Imprimir();
}

