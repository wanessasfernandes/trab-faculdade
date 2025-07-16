#ifndef LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H
#define LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H
#include "elemento.h"

class ListaDuplamenteEncadeadaCircular {
private:
    class No {
    public:
        elemento* dado;
        No* proximo;
        No* anterior;

        No(elemento* e) : dado(e), proximo(this), anterior(this) {}
        ~No() { delete dado; }
    };

    No* cabeca;

public:
    ListaDuplamenteEncadeadaCircular();
    ~ListaDuplamenteEncadeadaCircular();

    void inserirNoInicio(elemento* e);       // O(1)
    void inserirNoFim(elemento* e);          // O(1)
    bool removerPeloId(int id);              // O(n)
    elemento* buscarPeloId(int id) const;    // O(n)
    void imprimirListaCircular() const;      // O(n)
    bool vazia() const;                      // O(1)
    void removerInicio();                    // O(1)
    void removerFim();                       // O(1)
    void imprimirtopo();   					// O(1)
    void imprimirultimo();					// O(1)
};

#endif
