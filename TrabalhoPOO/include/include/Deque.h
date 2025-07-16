#ifndef DEQUE_H
#define DEQUE_H

#include "ListaDuplamenteEncadeadaCircular.h"  // Implemente essa classe seguindo o mesmo padrão

class Deque {
private:
    ListaDuplamenteEncadeadaCircular lista;

public:
    void inserirFrente(elemento* elem);  // O(1)
    void inserirTras(elemento* elem);    // O(1)
    void removerFrente();           // O(1)
    void removerTras();             // O(1)
    bool dequeVazio() const;             // O(1)
    void imprimir_inicio ();
    void imprimir_ultimo();
};

#endif
