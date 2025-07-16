#ifndef PESSOA_H
#define PESSOA_H

#include "elemento.h"
#include <iostream>

using namespace std;

class Pessoa : public elemento
{
	public:
		Pessoa(int id,string nome, float salario);
		void deposito(float acressimo);
		void saque(float decressimo);
		float getSalario();
		string getNome();
		void apresentar();
		~Pessoa();
		
	protected:
		string nome;
		float salario;
};

#endif
