#ifndef ARVOREB_H
#define ARVOREB_H

#include "elemento.h"

class ArvoreB {
private:
    class no 
    {
    public:    
		no(elemento* elem) : elem(elem), esquerda(NULL), direita(NULL) {
    		valor = new int(elem->getID());
		}
        elemento* elem;
        no* esquerda;
        no* direita;
        int* valor;
        // Destrutor do nó
		~no() {
    		delete valor;
		}

    };
    ArvoreB::no* raiz = NULL;
    ArvoreB::no* inserirNopriv(ArvoreB::no*, elemento* elem);
    ArvoreB::no* buscarNopriv(ArvoreB::no*, int id);
    void Getelementopriv(no* noAtual);
    ArvoreB::no* encontrarMinimo(ArvoreB::no* noAtual);
    ArvoreB::no* removerNopriv(ArvoreB::no* noAtual, int id);
    void imprimirEmOrdempriv(ArvoreB::no* noAtual);
    void imprimirPreOrdempriv(ArvoreB::no* noAtual);
    void imprimirPosOrdempriv(ArvoreB::no* noAtual);
    void destruirArvore(ArvoreB::no* noAtual);
public:
    ArvoreB();
    ~ArvoreB();
    void inserirNo(elemento* elem);
    void buscarNo(int id);
    void Getelemento(int id);
    void removerNo(int id);
    void imprimirEmOrdem();
    void imprimirPreOrdem();
    void imprimirPosOrdem();
};

#endif
