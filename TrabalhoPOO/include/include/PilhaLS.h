#ifndef PILHALS_H
#define PILHALS_H

#include "ListaNaoOrdenada.h"

class Pilhals{

private:
	ListaNaoOrdenada lista;
	
public:
	Pilhals(int capacidade = 100);
	~Pilhals() = default;
	
	bool empilhar(elemento* e);  // O(1)
	void desempilhar();     // O(1)
    void consultarTopo() const; 	 // O(1)
    
    bool pilhaCheia() const;
    bool pilhaVazia() const;
    void Imprimir();
	
};

#endif
