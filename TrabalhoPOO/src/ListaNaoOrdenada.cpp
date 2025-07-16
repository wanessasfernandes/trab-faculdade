#include "ListaNaoOrdenada.h"
#include <iostream>
using namespace std;

ListaNaoOrdenada::ListaNaoOrdenada(int capacidade) {
    this->capacidade = capacidade;
    this->tamanho = 0;
    this->elementos = new elemento*[capacidade]();
}

ListaNaoOrdenada::~ListaNaoOrdenada() {
    for (int i = 0; i < tamanho; ++i)
        delete elementos[i];
    delete[] elementos;
}

bool ListaNaoOrdenada::InserirNoInicio(elemento* e) {
    if (tamanho >= capacidade) {
        cout << "Erro: lista cheia.\n";
        return false;
    }
    for (int i = tamanho; i > 0; --i)
        elementos[i] = elementos[i - 1];
    elementos[0] = e;
    tamanho++;
    return true;
}

bool ListaNaoOrdenada::InserirNoFinal(elemento* e) {
    if (tamanho >= capacidade) {
        cout << "Erro: lista cheia.\n";
        return false;
    }
    elementos[tamanho++] = e;
    return true;
}

bool ListaNaoOrdenada::RemoverPrimeiro() {
    if (tamanho == 0) {
        cout << "Erro: lista vazia.\n";
        return false;
    }
    delete elementos[0];
    for (int i = 1; i < tamanho; ++i)
        elementos[i - 1] = elementos[i];
    tamanho--;
    return true;
}

bool ListaNaoOrdenada::RemoverUltimo() {
    if (tamanho == 0) {
        cout << "Erro: lista vazia.\n";
        return false;
    }
    delete elementos[--tamanho];
    return true;
}

bool ListaNaoOrdenada::RemoverPeloId(int id) {
    for (int i = 0; i < tamanho; ++i) {
        if (elementos[i]->getID() == id) {
            delete elementos[i];
            for (int j = i + 1; j < tamanho; ++j)
                elementos[j - 1] = elementos[j];
            tamanho--;
            return true;
        }
    }
    cout << "Erro: ID não encontrado.\n";
    return false;
}

elemento* ListaNaoOrdenada::BuscarPeloId(int id) {
    for (int i = 0; i < tamanho; ++i) {
        if (elementos[i]->getID() == id)
            return elementos[i];
    }
    return NULL;
}

bool ListaNaoOrdenada::AlterarPeloId(int id, elemento* novo) {
    if (novo == NULL || novo->getID() != id) {
        cout << "Erro: novo elemento inválido.\n";
        return false;
    }

    for (int i = 0; i < tamanho; ++i) {
        if (elementos[i]->getID() == id) {
            delete elementos[i];
            elementos[i] = novo;
            return true;
        }
    }
    
    cout << "Erro: ID não encontrado.\n";
    return false;
}

void ListaNaoOrdenada::Imprimir() {
    if (tamanho == 0) {
        cout << "Lista vazia.\n";
        return;
    }
    
    for (int i = 0; i < tamanho; ++i) {
        elementos[i]->apresentar();
    }
}

bool ListaNaoOrdenada::EstaCheia() const {
    return tamanho >= capacidade;
}

bool ListaNaoOrdenada::EstaVazia() const {
    return tamanho == 0;
}

int ListaNaoOrdenada::GetTamanho() const {
    return tamanho;
}

int ListaNaoOrdenada::GetCapacidade() const {
    return capacidade;
}

void ListaNaoOrdenada::Getinformation(int pos) const{
	elementos[pos]->apresentar();
}
