#include "ListaOrdenada(1).h"
#include <iostream>
using namespace std;

ListaOrdenada::ListaOrdenada() : tamanho(0) {
    for (int i = 0; i < MAX; ++i)
        elementos[i] = NULL;
}

ListaOrdenada::~ListaOrdenada() {
    for (int i = 0; i < tamanho; ++i)
        delete elementos[i];
}

void ListaOrdenada::InserirOrdenado(elemento* e) {
    if (tamanho >= MAX) {
        cout << "Erro: lista cheia.\n";
        return;
    }

    int i = tamanho - 1;
    while (i >= 0 && elementos[i]->getID() > e->getID()) {
        elementos[i + 1] = elementos[i];
        i--;
    }
    elementos[i + 1] = e;
    tamanho++;
}

void ListaOrdenada::RemoverPeloId(int id) {
    int inicio = 0, fim = tamanho - 1, meio;
    bool encontrado = false;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (elementos[meio]->getID() == id) {
            encontrado = true;
            break;
        }
        else if (elementos[meio]->getID() < id)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    if (encontrado) {
        delete elementos[meio];
        for (int i = meio; i < tamanho - 1; ++i)
            elementos[i] = elementos[i + 1];
        tamanho--;
        elementos[tamanho] = NULL;
    } else {
        cout << "Erro: ID nao encontrado.\n";
    }
}

elemento* ListaOrdenada::BuscarPeloId(int id) const {
    int inicio = 0, fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (elementos[meio]->getID() == id)
            return elementos[meio];
        else if (elementos[meio]->getID() < id)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return NULL;
}

void ListaOrdenada::AlterarPeloId(int id, elemento* novo) {
    if (novo == NULL || novo->getID() != id) {
        cout << "Erro: novo elemento inválido.\n";
        return;
    }

    elemento* encontrado = BuscarPeloId(id);
    if (encontrado != NULL) {
        RemoverPeloId(id);
        InserirOrdenado(novo);
    } else {
        cout << "Erro: ID nao encontrado.\n";
    }
}

void ListaOrdenada::RemoverPrimeiro() {
    if (tamanho == 0) {
        cout << "Erro: lista vazia.\n";
        return;
    }
    delete elementos[0];
    for (int i = 1; i < tamanho; ++i)
        elementos[i - 1] = elementos[i];
    tamanho--;
    elementos[tamanho] = NULL;
}

void ListaOrdenada::RemoverUltimo() {
    if (tamanho == 0) {
        cout << "Erro: lista vazia.\n";
        return;
    }
    delete elementos[--tamanho];
    elementos[tamanho] = NULL;
}

void ListaOrdenada::Imprimir() const {
    if (tamanho == 0) {
        cout << "Lista vazia.\n";
        return;
    }
    
    for (int i = 0; i < tamanho; ++i) {
        elementos[i]->apresentar();
    }
}
