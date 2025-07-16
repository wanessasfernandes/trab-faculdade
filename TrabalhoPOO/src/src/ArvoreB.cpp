// ArvoreB.cpp
#include "ArvoreB.h"
#include <iostream>

using namespace std;

ArvoreB::no* ArvoreB::inserirNopriv(ArvoreB::no* noAtual, elemento* elem) {
    if (elem == NULL){
	
        cout<<"Elemento nulo"<< endl;
		return NULL;
	}
    if (noAtual == NULL) 
        return new no(elem); 
    

    int idNovo = elem->getID();
    int idAtual = *(noAtual->valor);

    if (idNovo < idAtual) {
        noAtual->esquerda = inserirNopriv(noAtual->esquerda, elem);
    } 
    else if (idNovo > idAtual) {
        noAtual->direita = inserirNopriv(noAtual->direita, elem);
    }
    
    return noAtual;
}
void ArvoreB::Getelementopriv(ArvoreB::no* atual){
	if(atual == NULL){
		cout << "Elemento nao encontrado" << endl;
	}
	else{
		atual->elem->apresentar();
	}
}
ArvoreB::no* ArvoreB::buscarNopriv(ArvoreB::no* noAtual, int id) {
    if (noAtual == NULL || *(noAtual->valor) == id) {
        return noAtual;
    }

    if (id < *(noAtual->valor)) {
        return buscarNopriv(noAtual->esquerda, id);
    }
    return buscarNopriv(noAtual->direita, id);
}
ArvoreB::no* ArvoreB::encontrarMinimo(no* noAtual) {
    if (noAtual ==NULL) 
        return NULL;
    while (noAtual->esquerda != NULL) {
        noAtual = noAtual->esquerda;
    }
    return noAtual;
}

ArvoreB::no* ArvoreB::removerNopriv(ArvoreB::no* noAtual, int id) {
    if (noAtual ==NULL) {
		cout << "Arvore vazia ou elemento não encontrado" << endl;
        return NULL;
	}
    if (id < *(noAtual->valor)) {
        noAtual->esquerda = removerNopriv(noAtual->esquerda, id);
    } 
    else if (id > *(noAtual->valor)) {
        noAtual->direita = removerNopriv(noAtual->direita, id);
    } 
    else {
        if (noAtual->esquerda == NULL) {
            no* temp = noAtual->direita;
            delete noAtual;
            return temp;
        } 
        else if (noAtual->direita == NULL) {
            no* temp = noAtual->esquerda;
            delete noAtual;
            return temp;
        }
        
        no* temp = encontrarMinimo(noAtual->direita);
        *(noAtual->valor) = *(temp->valor);
        noAtual->direita = removerNopriv(noAtual->direita, *(temp->valor));
    }
    return noAtual;
}

void ArvoreB::imprimirEmOrdempriv(ArvoreB::no* noAtual) {
    if (noAtual != NULL) {
        imprimirEmOrdempriv(noAtual->esquerda);
        noAtual->elem->apresentar();
        imprimirEmOrdempriv(noAtual->direita);
    }
}

void ArvoreB::imprimirPreOrdempriv(ArvoreB::no* noAtual) {
    if (noAtual != NULL) {
        noAtual->elem->apresentar();
        imprimirPreOrdempriv(noAtual->esquerda);
        imprimirPreOrdempriv(noAtual->direita);
    }
}

void ArvoreB::imprimirPosOrdempriv(ArvoreB::no* noAtual) {
    if (noAtual != NULL) {
        imprimirPosOrdempriv(noAtual->esquerda);
        imprimirPosOrdempriv(noAtual->direita);
        noAtual->elem->apresentar();
    }
}
void ArvoreB::destruirArvore(ArvoreB::no* noAtual) {
    if (noAtual != NULL) {
        destruirArvore(noAtual->esquerda);
        destruirArvore(noAtual->direita);
        delete noAtual;
    }
}
ArvoreB::~ArvoreB() {
    destruirArvore(raiz);
}

void ArvoreB::inserirNo(elemento* elem){
	raiz = inserirNopriv(raiz,elem);
}

void ArvoreB::removerNo(int id){
	raiz = removerNopriv(raiz,id);
}

void ArvoreB::buscarNo(int id){
	buscarNopriv(raiz,id);
}

void ArvoreB::Getelemento(int id){
	Getelementopriv(buscarNopriv( raiz ,id));
}

void ArvoreB::imprimirEmOrdem(){
	imprimirEmOrdempriv(raiz);
}

void ArvoreB::imprimirPosOrdem(){
	imprimirPosOrdempriv(raiz);
}

void ArvoreB::imprimirPreOrdem(){
	imprimirPreOrdempriv(raiz);
}

ArvoreB::ArvoreB(){
	
}

