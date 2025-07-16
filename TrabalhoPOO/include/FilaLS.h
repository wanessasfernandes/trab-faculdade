#ifndef FILALS_H
#define FILALS_H

#include "ListaNaoOrdenada.h"

class Filals {

private:
	ListaNaoOrdenada lista;
	
public:
	Filals(int capacidade = 100);   // construtor
	~Filals() = default;  		  // destrutor
	
	bool enfileirar(elemento* e); // O(1)
	elemento* desenfileirar();	  // O(n)
    elemento* consultarFrente();  // O(1)
    
    bool filaCheia() const;
    bool filaVazia() const;
    void imprimir();
	
};

#endif
