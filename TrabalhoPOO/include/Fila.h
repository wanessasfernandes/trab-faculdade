#ifndef FILA_H
#define FILA_H

#include "ListaDuplamenteEncadeadaCircular.h"

class Fila {
private:
    ListaDuplamenteEncadeadaCircular lista;  // Composição

public:
    void enfileirar(elemento* elem);  // O(1)
    void desenfileirar();        // O(1)
    void topo();				// O(1)
    void imprimir();			// O(n)
    bool filaVazia() const;           // O(1)
};

#endif
