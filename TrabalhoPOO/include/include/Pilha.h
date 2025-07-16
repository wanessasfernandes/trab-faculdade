#ifndef PILHA_H
#define PILHA_H

#include "ListaDuplamenteEncadeadaCircular.h"

class Pilha {
private:
    ListaDuplamenteEncadeadaCircular lista;  

public:
    void empilhar(elemento* elem);  // O(1)
    void desempilhar();        // O(1)
    bool pilhaVazia() const;        // O(1)
    void ultimo();					//O(1)
    void imprimir();
};

#endif
