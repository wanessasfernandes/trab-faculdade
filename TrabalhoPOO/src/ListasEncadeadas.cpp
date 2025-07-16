
#include "elemento.h"
#include "ListaSimplesmenteEncadeada.h"
#include "ListaDuplamenteEncadeada.h"
#include "ListaDuplamenteEncadeadaCircular.h"


//Lista Simplesmente Encadeada

ListaSimplesmenteEncadeada::ListaSimplesmenteEncadeada() : cabeca(NULL) {}

ListaSimplesmenteEncadeada::~ListaSimplesmenteEncadeada() {
    while (cabeca) {
        No* temp = cabeca;
        cabeca = cabeca->proximo;
        delete temp;
    }
}

void ListaSimplesmenteEncadeada::inserirNoInicio(elemento* e) {
    No* novo = new No(e);
    novo->proximo = cabeca;
    cabeca = novo;
}

void ListaSimplesmenteEncadeada::inserirNoFim(elemento* e) {
    No* novo = new No(e);
    if (!cabeca) {
        cabeca = novo;
        return;
    }
    No* atual = cabeca;
    while (atual->proximo)
        atual = atual->proximo;
    atual->proximo = novo;
}

bool ListaSimplesmenteEncadeada::removerPeloId(int id) {
    No* atual = cabeca;
    No* anterior = NULL;
    while (atual && atual->dado->getID() != id) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (!atual) return false;
    if (!anterior) cabeca = atual->proximo;
    else anterior->proximo = atual->proximo;
    delete atual;
    return true;
}

elemento* ListaSimplesmenteEncadeada::buscarPeloId(int id) const {
    No* atual = cabeca;
    while (atual) {
        if (atual->dado->getID() == id) return atual->dado;
        atual = atual->proximo;
    }
    return NULL;
}

void ListaSimplesmenteEncadeada::imprimirLista() const {
    No* atual = cabeca;
    while (atual) {
        atual->dado->apresentar();
        atual = atual->proximo;
    }
}

bool ListaSimplesmenteEncadeada::vazia() const {
    return cabeca == NULL;
}

// Lista Duplamente Encadeada

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada() : cabeca(NULL), cauda(NULL) {}

ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada() {
    while (cabeca) {
        No* temp = cabeca;
        cabeca = cabeca->proximo;
        delete temp;
    }
}

void ListaDuplamenteEncadeada::inserirNoInicio(elemento* e) {
    No* novo = new No(e);
    novo->proximo = cabeca;
    if (cabeca) cabeca->anterior = novo;
    else cauda = novo;
    cabeca = novo;
}

void ListaDuplamenteEncadeada::inserirNoFim(elemento* e) {
    No* novo = new No(e);
    novo->anterior = cauda;
    if (cauda) cauda->proximo = novo;
    else cabeca = novo;
    cauda = novo;
}

bool ListaDuplamenteEncadeada::removerPeloId(int id) {
    No* atual = cabeca;
    while (atual && atual->dado->getID() != id)
        atual = atual->proximo;
    if (!atual) return false;
    if (atual->anterior) atual->anterior->proximo = atual->proximo;
    else cabeca = atual->proximo;
    if (atual->proximo) atual->proximo->anterior = atual->anterior;
    else cauda = atual->anterior;
    delete atual;
    return true;
}

elemento* ListaDuplamenteEncadeada::buscarPeloId(int id) const {
    No* atual = cabeca;
    while (atual) {
        if (atual->dado->getID() == id) return atual->dado;
        atual = atual->proximo;
    }
    return NULL;
}

void ListaDuplamenteEncadeada::imprimirListaDireta() const {
    No* atual = cabeca;
    while (atual) {
        atual->dado->apresentar();
        atual = atual->proximo;
    }
}

void ListaDuplamenteEncadeada::imprimirListaReversa() const {
    No* atual = cauda;
    while (atual) {
        atual->dado->apresentar();
        atual = atual->anterior;
    }
}

bool ListaDuplamenteEncadeada::vazia() const {
    return cabeca == NULL;
}

// Lista Duplamente Encadeada Circular

ListaDuplamenteEncadeadaCircular::ListaDuplamenteEncadeadaCircular() : cabeca(NULL) {}

ListaDuplamenteEncadeadaCircular::~ListaDuplamenteEncadeadaCircular() {
    if (!cabeca) return;
    No* atual = cabeca->proximo;
    while (atual != cabeca) {
        No* temp = atual;
        atual = atual->proximo;
        delete temp;
    }
    delete cabeca;
}

void ListaDuplamenteEncadeadaCircular::inserirNoInicio(elemento* e) {
    No* novo = new No(e);
    if (!cabeca) {
        cabeca = novo;
    } else {
        No* ultimo = cabeca->anterior;
        novo->proximo = cabeca;
        novo->anterior = ultimo;
        cabeca->anterior = novo;
        ultimo->proximo = novo;
        cabeca = novo;
    }
}

void ListaDuplamenteEncadeadaCircular::inserirNoFim(elemento* e) {
    No* novo = new No(e);
    if (!cabeca) {
        cabeca = novo;
    } else {
        No* ultimo = cabeca->anterior;
        novo->proximo = cabeca;
        novo->anterior = ultimo;
        ultimo->proximo = novo;
        cabeca->anterior = novo;
    }
}

bool ListaDuplamenteEncadeadaCircular::removerPeloId(int id) {
    if (!cabeca) return false;
    No* atual = cabeca;
    do {
        if (atual->dado->getID() == id) {
            if (atual->proximo == atual) {
                delete atual;
                cabeca = NULL;
            } else {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
                if (atual == cabeca) cabeca = atual->proximo;
                delete atual;
            }
            return true;
        }
        atual = atual->proximo;
    } while (atual != cabeca);
    return false;
}

elemento* ListaDuplamenteEncadeadaCircular::buscarPeloId(int id) const {
    if (!cabeca) return NULL;
    No* atual = cabeca;
    do {
        if (atual->dado->getID() == id) return atual->dado;
        atual = atual->proximo;
    } while (atual != cabeca);
    return NULL;
}

void ListaDuplamenteEncadeadaCircular::imprimirListaCircular() const {
    if (!cabeca) return;
    No* atual = cabeca;
    do {
        atual->dado->apresentar();
        atual = atual->proximo;
    } while (atual != cabeca);
}

bool ListaDuplamenteEncadeadaCircular::vazia() const {
    return cabeca == NULL;
}

void ListaDuplamenteEncadeadaCircular::removerInicio() {
    if (!cabeca) return;
    if (cabeca->proximo == cabeca) {
        delete cabeca;
        cabeca = NULL;
    } else {
        No* ultimo = cabeca->anterior;
        No* temp = cabeca;
        cabeca = cabeca->proximo;
        cabeca->anterior = ultimo;
        ultimo->proximo = cabeca;
        delete temp;
    }
}

void ListaDuplamenteEncadeadaCircular::removerFim() {
    if (!cabeca) return;
    if (cabeca->proximo == cabeca) {
        delete cabeca;
        cabeca = NULL;
    } else {
        No* ultimo = cabeca->anterior;
        No* penultimo = ultimo->anterior;
        penultimo->proximo = cabeca;
        cabeca->anterior = penultimo;
        delete ultimo;
    }
}

void ListaDuplamenteEncadeadaCircular::imprimirtopo() {
	cabeca->dado->apresentar();
}

void ListaDuplamenteEncadeadaCircular::imprimirultimo(){
	cabeca->anterior->dado->apresentar();
}
