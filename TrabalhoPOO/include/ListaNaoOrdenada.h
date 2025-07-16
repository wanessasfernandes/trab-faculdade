#ifndef LISTA_NAO_ORDENADA_H
#define LISTA_NAO_ORDENADA_H

#include "Elemento.h"

class ListaNaoOrdenada {
private:
    elemento** elementos;
    int capacidade;
    int tamanho;

public:
    ListaNaoOrdenada(int capacidade = 100);
    ~ListaNaoOrdenada();

    bool InserirNoInicio(elemento* e);
    bool InserirNoFinal(elemento* e);
    bool RemoverPrimeiro();
    bool RemoverUltimo();
    bool RemoverPeloId(int id);
    elemento* BuscarPeloId(int id);
    bool AlterarPeloId(int id, elemento* novo);
    void Imprimir();
    bool EstaCheia() const;
    bool EstaVazia() const;
    int GetTamanho() const;
    int GetCapacidade() const;
    void Getinformation (int pos) const;
};

#endif
