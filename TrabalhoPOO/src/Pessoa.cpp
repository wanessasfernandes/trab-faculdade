#include "Pessoa.h"
#include <iostream>

using namespace std;

Pessoa::Pessoa(int id,string NOME, float salar)
{
	ID = id;
	nome = NOME;
	salario = salar;
}


void Pessoa::deposito(float acressimo){
	salario = salario+acressimo;
}

void Pessoa::saque(float decressimo){
	salario = salario-decressimo;
}

float Pessoa::getSalario(){
	return salario;
}

string Pessoa::getNome(){
	return nome;
}

void Pessoa::apresentar(){
	cout << "Prazer meu nome e: " << getNome() << " ID: " << getID() << " Ganho: " << getSalario() << "R$" << endl;
}


Pessoa::~Pessoa()
{
}
