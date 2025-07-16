#ifndef LISTA_SIMPLEMENTE_ENCADEADA_H
#define LISTA_SIMPLEMENTE_ENCADEADA_H

#include "elemento.h"

class ListaSimplesmenteEncadeada {
private:
    class No {
    public:
        elemento* dado;
        No* proximo;

        No(elemento* e) : dado(e), proximo(NULL) {}
        ~No() { delete dado; }
    };

    No* cabeca;

public:
    ListaSimplesmenteEncadeada();
    ~ListaSimplesmenteEncadeada();

    void inserirNoInicio(elemento* e);       // O(1)
    void inserirNoFim(elemento* e);          // O(n)
    bool removerPeloId(int id);              // O(n)
    elemento* buscarPeloId(int id) const;    // O(n)
    void imprimirLista() const;              // O(n)
    bool vazia() const;                      // O(1)
};

#endif
