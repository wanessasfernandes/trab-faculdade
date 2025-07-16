#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include "Elemento.h"

class ListaOrdenada {
private:
    static const int MAX = 100;
    elemento* elementos[MAX];
    int tamanho;

public:
    ListaOrdenada();
    ~ListaOrdenada();

    void InserirOrdenado(elemento* e);       // O(n)
    void RemoverPeloId(int id);              // O(n)
    elemento* BuscarPeloId(int id) const;    // O(log n)
    void AlterarPeloId(int id, elemento* novo); // O(n)
    void RemoverPrimeiro();                  // O(n)
    void RemoverUltimo();                    // O(1)
    void Imprimir() const;
};

#endif
