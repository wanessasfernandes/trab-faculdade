#include "Maquina.h"
#include <iostream>

using namespace std;

Maquina::Maquina(int IP, string Name, bool atividade)
{
	ID = IP;
	nome = Name;
	ativo = atividade;
}

Maquina::~Maquina()
{
}

string Maquina::getnome(){
	return nome;
}

bool Maquina::getatividade(){
	return ativo;
}

void Maquina::alterar_atividade(){
	ativo = !ativo;
}

void Maquina::apresentar(){
	string atividade;
	if(ativo == true){
		atividade = "Ativo";
	}
	else{
		atividade = "Desativado";
	}
	cout << getnome() << " de IP: " << getID() << " Se encontra " << atividade << endl;
}

