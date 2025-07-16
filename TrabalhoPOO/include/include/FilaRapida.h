#ifndef FILA_EFICIENTE_H
#define FILA_EFICIENTE_H

#include "ListaNaoOrdenada.h"

class FilaRapida {

private:
	ListaNaoOrdenada lista;
	elemento* frente;
	elemento* final;
	
public:
	FilaRapida(int capacidade = 100);   // construtor
	~FilaRapida() = default;  	  	    // destrutor
	
	bool enfileirar(elemento* e); // O(1)
	void desenfileirar();	  // O(1)
    elemento* consultarFrente();  // O(1)
    
    bool filaCheia() const;
    bool filaVazia() const;
    void imprimir();
	
};

#endif
