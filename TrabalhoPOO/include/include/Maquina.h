#ifndef MAQUINA_H
#define MAQUINA_H

#include <iostream>
#include "elemento.h"

using namespace std;
class Maquina : public elemento
{
	public:
		
		Maquina(int IP,string Name, bool atividade);
		~Maquina();
		bool getatividade();
		string getnome();
		void apresentar();
		void alterar_atividade();
	protected:
		string nome;
		bool ativo;
};

#endif
