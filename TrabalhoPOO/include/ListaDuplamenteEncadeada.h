#ifndef LISTA_DUPLAMENTE_ENCADEADA_H
#define LISTA_DUPLAMENTE_ENCADEADA_H
#include "elemento.h"

class ListaDuplamenteEncadeada {
private:
    class No {
    public:
        elemento* dado;
        No* proximo;
        No* anterior;

        No(elemento* e) : dado(e), proximo(NULL), anterior(NULL) {}
        ~No() { delete dado; }
    };

    No* cabeca;
    No* cauda;

public:
    ListaDuplamenteEncadeada();
    ~ListaDuplamenteEncadeada();

    void inserirNoInicio(elemento* e);       // O(1)
    void inserirNoFim(elemento* e);          // O(1)
    bool removerPeloId(int id);              // O(n)
    elemento* buscarPeloId(int id) const;    // O(n)
    void imprimirListaDireta() const;        // O(n)
    void imprimirListaReversa() const;       // O(n)
    bool vazia() const;                      // O(1)
};

#endif
