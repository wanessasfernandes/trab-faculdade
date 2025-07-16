#include <iostream>
#include <string.h>
#include <limits>
#include <locale.h>
#include "elemento.h"
#include "Pessoa.h"
#include "Maquina.h"
#include "ListaSimplesmenteEncadeada.h"
#include "ListaDuplamenteEncadeada.h"
#include "ListaDuplamenteEncadeadaCircular.h"
#include "ListaOrdenada(1).h"
#include "ListaNaoOrdenada.h"
#include "FilaLS.h"
#include "FilaRapida.h"
#include "PilhaLS.h"
#include "Fila.h"
#include "Pilha.h"
#include "Deque.h"
#include "ArvoreB.h"

using namespace std;

int main(){
	setlocale(LC_ALL, "pt_BR.utf8");
	int option = 0;
	MENU:
		while (option != 4){
			cout << "Escolha qual estrutura de dados você quer operar" << endl;
			cout << "Digite 1: Para operar em listas de alocação dinamica" << endl;
			cout << "Digite 2: Para operar em listas de alocação estatica" << endl;
			cout << "Digite 3: Para operar pilas, filas e deques" << endl;
			cout << "Digite 4: Para finalizar as operações" << endl;
			cin >> option;
			switch (option){
				case 1:
					goto DINAMICA;
					break;
				case 2:
					goto ESTATICA;
					break;
				case 3:
					goto FPD;
					break;
				case 4: {
					return 0;
					break;
				}
				default:
					cout << "Valor fora do menu" << endl;			
					break;
			}
		}
	DINAMICA:{
		int select = 0;
		while(select != -1){
			cout << endl;
			cout << "Escolha qual tipo de lista utilizar" << endl;
			cout << "Digite 1: Simplesmente encadeada" << endl;
			cout << "Digite 2: Duplamente encadeada" << endl;
			cout << "Digite 3: Duplamente encadeada circular" << endl;
			cout << "Digite 4: arvore de busca" << endl;
			cout << "Digite 5: Para Retornar ao menu de estruturas" << endl;
			cin >> select;
			switch (select){
				case 1:
					goto LSE;
					break;
				case 2:
					goto LDE;
					break;
					
				case 3:
					goto LDEC;
					break;
				
				case 4:
					goto AB;
					break;
				case 5:
					goto MENU;
					break;
				default:
					cout << "Valor fora do menu" << endl;			
			}	
		}
		
    }		
	LSE:{
		option = 0;
		ListaSimplesmenteEncadeada lista;
		while(option != -1){
			cout << endl;
			cout << "Lista de Operações" << endl;
			cout << "1: Inserir no inicio" << endl;
			cout << "2: Inserir no final" << endl;
			cout << "3: Remover" << endl;
			cout << "4: Busca e alteração" << endl;
			cout << "5: Imprimir lista" << endl;
			cout << "6: Exit" << endl;        
			cin >> option;
			switch (option){
				case 1:
				{
					int pm;
					cout << "Tipo do elemento" << endl;
					cout << "1: Pessoa" << endl;
					cout << "2: Máquina" << endl;
					cin >> pm;
					if( pm == 1){
						int ID;
						string Nome;
						float salario;
						cout << "Digite o ID" << endl;
						cin >> ID;
						cout << "Digite o salario" << endl;
						cin >> salario;
						cout << "Digite o Nome" << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						getline(cin,Nome);
						Pessoa* P = new Pessoa(ID, Nome, salario);
						lista.inserirNoInicio(P);
					}
					else{
						int IP;
						string nome;
						bool atividade;
						int situation;
						cout << "Digite o Ip da maquina" << endl;
						cin >> IP;
						cout << " Digite o nome da maquina" << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						getline(cin,nome);	
						cout << "Digite 1 se a maquina estiver ativa e 2 caso a maquina esteja desativada" << endl;
						cin >> situation;
						if(situation == 1){
							atividade = true;
						}
						else{
							atividade = false;
						}
						Maquina* CPU = new Maquina(IP,nome,atividade);
						lista.inserirNoInicio(CPU);
					}
					break;
				}
					
				case 2:
				{
					int pm2;
					cout << "Tipo do elemento" << endl;
					cout << "1: Pessoa" << endl;
					cout << "2: Máquina" << endl;
					cin >> pm2;
					if( pm2 == 1){
						int ID;
						string Nome;
						float salario;
						cout << "Digite o ID" << endl;
						cin >> ID;
						cout << "Digite o salario" << endl;
						cin >> salario;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						getline(cin,Nome);
						Pessoa* P = new Pessoa(ID, Nome, salario);
						lista.inserirNoFim(P);
					}
					else{
						int IP;
						string nome;
						bool atividade;
						int situation;
						cout << "Digite o Ip da maquina" << endl;
						cin >> IP;
						cout << " Digite o nome da maquina" << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						getline(cin,nome);	
						cout << "Digite 1 se a maquina estiver ativa e 2 caso a maquina esteja desativada" << endl;
						cin >> situation;
						if(situation == 1){
							atividade = true;
						}
						else{
							atividade = false;
						}
						Maquina* CPU = new Maquina(IP,nome,atividade);
						lista.inserirNoFim(CPU);
					}
					break;
				}
				
				case 3:
				{
					int id;
					cout << "Digite o ID a ser removido" << endl;
					cin >> id;
					lista.removerPeloId(id);
					break;
				}
				
				case 4:
				{
					int id2;
					cout << "Digite o ID a ser buscado" << endl;
					cin >> id2;
					elemento* busca = lista.buscarPeloId(id2);
					cout << &busca;
					break;
				}
				
				case 5:
				{	
					lista.imprimirLista();
					break;
				}
				
				case 6:
				{	
					int select = 0;
					cout << "CUIDADO: Ao sair a lista será destruida, deseja prosseguir?" << endl;
					cout << "1: sim" << endl;
					cout << "2: Não" << endl;
					cin >> select;
					if(select == 1){
						goto MENU;
					}
					break;
				}										
			}
		}
	}
	LDE:{
		option = 0;
		ListaDuplamenteEncadeada listade;
		while(option != -1){
			cout << endl;
			cout << "Lista de Operações" << endl;
			cout << "1: Inserir no inicio" << endl;
			cout << "2: Inserir no final" << endl;
			cout << "3: Remover" << endl;
			cout << "4: Busca e alteração" << endl;
			cout << "5: Imprimir lista do primeiro ao ultimo" << endl;
			cout << "6: Imprimir lista de trás pra frente" << endl;
			cout << "7: Exit" << endl;        
			cin >> option;
			switch (option){
				case 1:
				{
					int pm;
					cout << "Tipo do elemento" << endl;
					cout << "1: Pessoa" << endl;
					cout << "2: Máquina" << endl;
					cin >> pm;
					if( pm == 1){
						int ID;
						string Nome;
						float salario;
						cout << "Digite o ID" << endl;
						cin >> ID;
						cout << "Digite o salario" << endl;
						cin >> salario;
						cout << "Digite o Nome" << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						getline(cin,Nome);
						Pessoa* P = new Pessoa(ID, Nome, salario);
						listade.inserirNoInicio(P);
					}
					else{
						int IP;
						string nome;
						bool atividade;
						int situation;
						cout << "Digite o Ip da maquina" << endl;
						cin >> IP;
						cout << " Digite o nome da maquina" << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						getline(cin,nome);	
						cout << "Digite 1 se a maquina estiver ativa e 2 caso a maquina esteja desativada" << endl;
						cin >> situation;
						if(situation == 1){
							atividade = true;
						}
						else{
							atividade = false;
						}
						Maquina* CPU = new Maquina(IP,nome,atividade);
						listade.inserirNoInicio(CPU);
					}
					break;
				}
					
				case 2:
				{
					int pm2;
					cout << "Tipo do elemento" << endl;
					cout << "1: Pessoa" << endl;
					cout << "2: Máquina" << endl;
					cin >> pm2;
					if( pm2 == 1){
						int ID;
						string Nome;
						float salario;
						cout << "Digite o ID" << endl;
						cin >> ID;
						cout << "Digite o salario" << endl;
						cin >> salario;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						getline(cin,Nome);
						Pessoa* P = new Pessoa(ID, Nome, salario);
						listade.inserirNoFim(P);
					}
					else{
						int IP;
						string nome;
						bool atividade;
						int situation;
						cout << "Digite o Ip da maquina" << endl;
						cin >> IP;
						cout << " Digite o nome da maquina" << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						getline(cin,nome);	
						cout << "Digite 1 se a maquina estiver ativa e 2 caso a maquina esteja desativada" << endl;
						cin >> situation;
						if(situation == 1){
							atividade = true;
						}
						else{
							atividade = false;
						}
						Maquina* CPU = new Maquina(IP,nome,atividade);
						listade.inserirNoFim(CPU);
					}
					break;
				}
				
				case 3:
				{
					int id;
					cout << "Digite o ID a ser removido" << endl;
					cin >> id;
					listade.removerPeloId(id);
					break;
				}
				
				case 4:
				{
					int id2;
					cout << "Digite o ID a ser buscado" << endl;
					cin >> id2;
					elemento* busca = listade.buscarPeloId(id2);
					cout << &busca;
					break;
				}
				
				case 5:
				{	
					listade.imprimirListaDireta();
					break;
				}
				
				case 6:{
					listade.imprimirListaReversa();
					break;
				}
				
				
				case 7:
				{
					int select = 0;
					cout << "CUIDADO: Ao sair a lista será destruida, deseja prosseguir?" << endl;
					cout << "1: sim" << endl;
					cout << "2: Não" << endl;
					cin >> select;
					if(select == 1){
						goto MENU;
					}
					break;
				}			
				default:{
					cout << "Valor fora do menu";
					break;
				}							
			}
		}
	}
	LDEC:{
		option = 0;
		ListaDuplamenteEncadeadaCircular listadec;
		while(option != -1){
			cout << endl;
			cout << "Lista de Operações" << endl;
			cout << "1: Inserir no inicio" << endl;
			cout << "2: Inserir no final" << endl;
			cout << "3: Remover" << endl;
			cout << "4: Busca e alteração" << endl;
			cout << "5: Imprimir lista" << endl;
			cout << "6: Exit" << endl;        
			cin >> option;
			switch (option){
				case 1:
				{
					int pm;
					cout << "Tipo do elemento" << endl;
					cout << "1: Pessoa" << endl;
					cout << "2: Máquina" << endl;
					cin >> pm;
					if( pm == 1){
						int ID;
						string Nome;
						float salario;
						cout << "Digite o ID" << endl;
						cin >> ID;
						cout << "Digite o salario" << endl;
						cin >> salario;
						cout << "Digite o Nome" << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						getline(cin,Nome);
						Pessoa* P  = new Pessoa(ID, Nome, salario);
						listadec.inserirNoInicio(P);
					}
					else{
						int IP;
						string nome;
						bool atividade;
						int situation;
						cout << "Digite o Ip da maquina" << endl;
						cin >> IP;
						cout << " Digite o nome da maquina" << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						getline(cin,nome);	
						cout << "Digite 1 se a maquina estiver ativa e 2 caso a maquina esteja desativada" << endl;
						cin >> situation;
						if(situation == 1){
							atividade = true;
						}
						else{
							atividade = false;
						}
						Maquina* CPU= new Maquina(IP,nome,atividade);
						listadec.inserirNoInicio(CPU);
					}
					break;
				}
					
				case 2:
				{
					int pm2;
					cout << "Tipo do elemento" << endl;
					cout << "1: Pessoa" << endl;
					cout << "2: Máquina" << endl;
					cin >> pm2;
					if( pm2 == 1){
						int ID;
						string Nome;
						float salario;
						cout << "Digite o ID" << endl;
						cin >> ID;
						cout << "Digite o salario" << endl;
						cin >> salario;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						getline(cin,Nome);
						Pessoa* P  = new Pessoa(ID, Nome, salario);
						listadec.inserirNoInicio(P);
					}
					else{
						int IP;
						string nome;
						bool atividade;
						int situation;
						cout << "Digite o Ip da maquina" << endl;
						cin >> IP;
						cout << " Digite o nome da maquina" << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						getline(cin,nome);	
						cout << "Digite 1 se a maquina estiver ativa e 2 caso a maquina esteja desativada" << endl;
						cin >> situation;
						if(situation == 1){
							atividade = true;
						}
						else{
							atividade = false;
						}
						Maquina* CPU= new Maquina(IP,nome,atividade);
						listadec.inserirNoInicio(CPU);
					}
					break;
				}
				
				case 3:
				{
					int id;
					cout << "Digite o ID a ser removido" << endl;
					cin >> id;
					listadec.removerPeloId(id);
					break;
				}
				
				case 4:
				{
					int id2;
					cout << "Digite o ID a ser buscado" << endl;
					cin >> id2;
					elemento* busca = listadec.buscarPeloId(id2);
					cout << &busca;
					break;
				}
				
				case 5:
				{	
					listadec.imprimirListaCircular();
					break;
				}
				
				case 6:{
					int select = 0;
					cout << "CUIDADO: Ao sair a lista será destruida, deseja prosseguir?" << endl;
					cout << "1: sim" << endl;
					cout << "2: Não" << endl;
					cin >> select;
					if(select == 1){
						goto MENU;
					}
					break;
				}			
				default:{
					cout << "Valor fora do menu";
					break;
				}							
			}
		}
	}
	
	AB:{
		int option = 0;
		ArvoreB Arvore;
		while(option != -1){
			cout << "MENU DE OPERACAO" << endl;
			cout << "1: Inserir" << endl;
			cout << "2: Remover no" << endl;
			cout << "3: Buscar no" << endl;
			cout << "4: Percurso Pre_ordem" << endl;
			cout << "5: Percurso Pos_ordem" << endl;
			cout << "6: Percurso em_ordem" << endl;
			cout << "7: Sair" << endl;
			cin >> option;
			switch (option){				
				case 1:{
					int select = 0;
					cout << "Deseja criar um objeto pessoa ou maquina" << endl;
					cout << "1: Pessoa" << endl;
					cout << "2: Maquina" << endl;
					cin >> select;
					if(select == 1){
						int ID;
						string Nome;
						float salario;
						cout << "Digite o ID" << endl;
						cin >> ID;
						cout << "Digite o salario" << endl;
						cin >> salario;
						cout << "Digite o Nome" << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						getline(cin,Nome);
						Pessoa* P  = new Pessoa(ID, Nome, salario);
						Arvore.inserirNo(P);					
					}
					else{
						int IP;
						string nome;
						bool atividade;
						int situation;
						cout << "Digite o Ip da maquina" << endl;
						cin >> IP;
						cout << " Digite o nome da maquina" << endl;
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						getline(cin,nome);	
						cout << "Digite 1 se a maquina estiver ativa e 2 caso a maquina esteja desativada" << endl;
						cin >> situation;
						if(situation == 1){
							atividade = true;
						}
						else{
							atividade = false;
						}
						Maquina* CPU= new Maquina(IP,nome,atividade);
						Arvore.inserirNo(CPU);					
					}
					break;
				}
				case 2: {
					int id;
					cout << "Digite o ID a ser removido" << endl;
					cin >> id;
					Arvore.removerNo(id);
					break;
				}
				case 3: {
					int id;
					cout << "Digite o ID a ser buscado" << endl;
					cin >> id;
					Arvore.Getelemento(id);
					break;
				}
				case 4:{
					Arvore.imprimirPosOrdem();
					break;
				}
				case 5: {
					Arvore.imprimirPreOrdem();
					break;
				}
				case 6: {
					Arvore.imprimirPreOrdem();
					break;
				}
				case 7: {
					int select = 0;
					cout << "CUIDADO: Ao sair a lista será destruida, deseja prosseguir?" << endl;
					cout << "1: sim" << endl;
					cout << "2: Não" << endl;
					cin >> select;
					if(select == 1){
						goto MENU;
					}
					break;
			}
		}
	}
}
	
	
	ESTATICA:{
		option = 0;
		while(option != -1){
			cout << "Escolha qual tipo de lista usar" << endl;
			cout << "Digite 1: Para listas ordenadas" << endl;
			cout << "Digite 2: Para listas nao ordenadas" << endl;
			cout << "Digite 3: Para voltar ao menu de listas" << endl;
			cin >> option;
			switch (option){
				case 1:
					goto LO;
					break;
				case 2:
					goto LNO;
					break;
				case 3:
					goto MENU;
					break;
				default:
					cout << "Valor fora do menu" << endl;
					break;
			}
		}
		
		LO:{
			int select = 0;
			ListaOrdenada listao;
		    int opcao;
		    
		    do {
		        cout << "\n=== MENU LISTA ORDENADA ===" << endl;
		        cout << "1. Inserir Pessoa" << endl;
		        cout << "2. Inserir Maquina" << endl;
		        cout << "3. Remover primeiro" << endl;
		        cout << "4. Remover ultimo" << endl;
		        cout << "5. Remover por ID" << endl;
		        cout << "6. Buscar por ID" << endl;
		        cout << "7. Alterar por ID" << endl;
		        cout << "8. Imprimir lista" << endl;
		        cout << "0. Sair" << endl;
		        cout << "Opcao: ";
		        cin >> opcao;
		        
		        if (opcao == 1) {
		            int id;
		            string nome;
		            float salario;
		            cout << "ID: ";
		            cin >> id;
		            cout << "Nome: ";
		            cin.ignore();
		            getline(cin, nome);
		            cout << "Salario: ";
		            cin >> salario;
		            
		            listao.InserirOrdenado(new Pessoa(id, nome, salario));
		        }
		        else if (opcao == 2) {
		            int id, ativo;
		            string nome;
		            cout << "ID: ";
		            cin >> id;
		            cout << "Nome: ";
		            cin.ignore();
		            getline(cin, nome);
		            cout << "Ativa (1-Sim/0-Nao): ";
		            cin >> ativo;
		            
		            listao.InserirOrdenado(new Maquina(id, nome, ativo == 1));
		        }
		        else if (opcao == 3) {
		            listao.RemoverPrimeiro();
		        }
		        else if (opcao == 4) {
		            listao.RemoverUltimo();
		        }
		        else if (opcao == 5) {
		            int id;
		            cout << "ID para remover: ";
		            cin >> id;
		            listao.RemoverPeloId(id);
		        }
		        else if (opcao == 6) {
		            int id;
		            cout << "ID para buscar: ";
		            cin >> id;
		            elemento* e = listao.BuscarPeloId(id);
		            if (e) {
		                e->apresentar();
		            }
		        }
		        else if (opcao == 7) {
		            int id, tipo;
		            cout << "ID para alterar: ";
		            cin >> id;
		            elemento* atual = listao.BuscarPeloId(id);
		            if (!atual) continue;
		            
		            cout << "Novo tipo (1-Pessoa, 2-Maquina): ";
		            cin >> tipo;
		            if (tipo == 1) {
		                string nome;
		                float salario;
		                cout << "Novo nome: ";
		                cin.ignore();
		                getline(cin, nome);
		                cout << "Novo salario: ";
		                cin >> salario;
		                listao.AlterarPeloId(id, new Pessoa(id, nome, salario));
		            }
		            else {
		                string nome;
		                int ativo;
		                cout << "Novo nome: ";
		                cin.ignore();
		                getline(cin, nome);
		                cout << "Ativa (1-Sim/0-Nao): ";
		                cin >> ativo;
		                listao.AlterarPeloId(id, new Maquina(id, nome, ativo == 1));
		            }
		        }
		        else if (opcao == 8) {
		            listao.Imprimir();
		        }
		        else if(opcao == 0){
					int select = 0;
					cout << "CUIDADO: Ao sair a lista será destruida, deseja prosseguir?" << endl;
					cout << "1: sim" << endl;
					cout << "2: Não" << endl;
					cin >> select;
					if(select == 1){
						goto MENU;
					}		        	
				}
		    } while (opcao != -1);
		}
		
		LNO:{
			ListaNaoOrdenada listano;	
			int opcao;
		    do {
		        cout << "\n=== MENU LISTA NAO ORDENADA ===" << endl;
		        cout << "1. Inserir Pessoa no inicio" << endl;
		        cout << "2. Inserir Maquina no inicio" << endl;
		        cout << "3. Inserir Pessoa no final" << endl;
		        cout << "4. Inserir Maquina no final" << endl;
		        cout << "5. Remover primeiro" << endl;
		        cout << "6. Remover ultimo" << endl;
		        cout << "7. Remover por ID" << endl;
		        cout << "8. Buscar por ID" << endl;
		        cout << "9. Alterar por ID" << endl;
		        cout << "10. Imprimir lista" << endl;
		        cout << "0. Sair" << endl;
		        cout << "Opcao: ";
		        cin >> opcao;
		        
		        if (opcao == 1 || opcao == 3) {
		            int id;
		            string nome;
		            float salario;
		            cout << "ID: ";
		            cin >> id;
		            cout << "Nome: ";
		            cin.ignore();
		            getline(cin, nome);
		            cout << "Salario: ";
		            cin >> salario;
		            
		            Pessoa* p = new Pessoa(id, nome, salario);
		            if (opcao == 1) listano.InserirNoInicio(p);
		            else listano.InserirNoFinal(p);
		        }
		        else if (opcao == 2 || opcao == 4) {
		            int id, ativo;
		            string nome;
		            cout << "ID: ";
		            cin >> id;
		            cout << "Nome: ";
		            cin.ignore();
		            getline(cin, nome);
		            cout << "Ativa (1-Sim/0-Nao): ";
		            cin >> ativo;
		            
		            Maquina* m = new Maquina(id, nome, ativo == 1);
		            if (opcao == 2) listano.InserirNoInicio(m);
		            else listano.InserirNoFinal(m);
		        }
		        else if (opcao == 5) {
		            listano.RemoverPrimeiro();
		        }
		        else if (opcao == 6) {
		            listano.RemoverUltimo();
		        }
		        else if (opcao == 7) {
		            int id;
		            cout << "ID para remover: ";
		            cin >> id;
		            listano.RemoverPeloId(id);
		        }
		        else if (opcao == 8) {
		            int id;
		            cout << "ID para buscar: ";
		            cin >> id;
		            elemento* e = listano.BuscarPeloId(id);
		            if (e) {
		                e->apresentar();
		            }
		        }
		        else if (opcao == 9) {
		            int id, tipo;
		            cout << "ID para alterar: ";
		            cin >> id;
		            elemento* atual = listano.BuscarPeloId(id);
		            if (!atual) continue;
		            
		            cout << "Novo tipo (1-Pessoa, 2-Maquina): ";
		            cin >> tipo;
		            if (tipo == 1) {
		                string nome;
		                float salario;
		                cout << "Novo nome: ";
		                cin.ignore();
		                getline(cin, nome);
		                cout << "Novo salario: ";
		                cin >> salario;
		                listano.AlterarPeloId(id, new Pessoa(id, nome, salario));
		            }
		            else {
		                string nome;
		                int ativo;
		                cout << "Novo nome: ";
		                cin.ignore();
		                getline(cin, nome);
		                cout << "Ativa (1-Sim/0-Nao): ";
		                cin >> ativo;
		                listano.AlterarPeloId(id, new Maquina(id, nome, ativo == 1));
		            }
		        }
		        else if (opcao == 10) {
		            listano.Imprimir();
		        }
		        else if (opcao == 0){
					int select = 0;
					cout << "CUIDADO: Ao sair a lista será destruida, deseja prosseguir?" << endl;
					cout << "1: sim" << endl;
					cout << "2: Não" << endl;
					cin >> select;
					if(select == 1){
						goto MENU;
					}
				}
		    } while (opcao != -1);
		}
	}
		
	FPD:{
		int option = 0;
		int select = 0;
		cout<< "MENU DE ESTRUTURAS" << endl;
		cout << "1: Filas" << endl;
		cout << "2: Pilhas" << endl;
		cout << "3: Deques" << endl;
		while (option != -1){
			cin >> option;
			switch (option){
				case 1:
					cout << "Operar em Alocação Sequencial ou em Alocação Dinamica" << endl;
					cout << "1: Alocação Sequencial" << endl;
					cout << "2: Alocação Dinamica" << endl;
					while(select != -1){
						cin >> select;
						if(select == 1){
							goto FLS;
						}
						else{
							if(select == 2){
								goto FLD;
							}
						}
					}
					break;
					case 2:
					cout << "Operar em Alocação Sequencial ou em Alocação Dinamica" << endl;
					cout << "1: Alocação Sequencial" << endl;
					cout << "2: Alocação Dinamica" << endl;
					while(select != -1){
						cin >> select;
						if(select == 1){
							goto PLS;
						}
					 	else{
							if(select == 2){
								goto PLD;
							}
						} 
						cout<< "Valor fora do menu" << endl;
					}
					break;
				case 3:
					goto DEQUE;
					break;
				default:
					cout << "Valor fora do menu" << endl;
					break; 
			}
		}
		
		FLS:
		{
			option = 0;
			cout << "1: Operar com Fila com duplo controle (mais eficiente)" << endl;
			cout << "2: Operar com Fila de controle unico" << endl;
			cout << "Opção: ";
			while(option != -1){
				cin >> option;
				if(select == 1){
					goto FR;
				}
				else{
					if(select == 2){
						goto F;
					}
				}
			}
			
			FR:{
				option = 0;
				FilaRapida Filas;
				while(option != -1){
					cout << "MENU DE OPERAÇÔES" << endl;
					cout << "1: Enfileirar" << endl;
					cout << "2: Desinfileirar" << endl;
					cout << "3: Consultar frente" <<  endl;
					cout << "4: Imprimir a lista"<< endl;
					cout << "Opção: ";
					cin >> option;
					switch (option){
						case 1:{
							select = 0;
							cout << "Você deseja enfileirar objeto maquina ou pessoa?" << endl;
							cout << "1: Maquina" << endl;
							cout << "2: Pessoa" << endl;
							cin >> select;
							if(select == 2){
					            int id;
					            string nome;
					            float salario;
					            cout << "ID: ";
					            cin >> id;
					            cout << "Nome: ";
					            cin.ignore();
					            getline(cin, nome);
					            cout << "Salario: ";
					            cin >> salario;
								Pessoa* P = new Pessoa(id,nome,salario);
								Filas.enfileirar(P);
							}
							else{
					            int id, ativo;
					            string nome;
					            bool atividade;
					            cout << "ID: ";
					            cin >> id;
					            cout << "Nome: ";
					            cin.ignore();
					            getline(cin, nome);
					            cout << "Ativa (1-Sim/0-Nao): ";
					            cin >> ativo;
					            if(ativo == 1){
					            	atividade = true;
								}
								else{
									atividade = false;
								}
					            Maquina* m = new Maquina(id, nome, atividade);								
					            Filas.enfileirar(m);
							}
							break;
						}
						case 2: {
							cout << "O elemento a seguir foi desinfileirado" << endl;
							elemento* busca = Filas.consultarFrente();
							busca->apresentar();
							cout << endl;
							Filas.desenfileirar();
							break;
						}
						case 3:{
							elemento* busca = Filas.consultarFrente();
							busca->apresentar();							
							break;
						}
						
						case 4:{
							Filas.imprimir();
							break;
						}
						
						case 5:{
							int exit = 0;
							cout << "Isto destruirá a lista, deseja proseguir?" << endl;
							cout << "1: Sim" << endl;
							cout << "2: Não" << endl;
							cin >> exit;
							if(exit == 1){
								goto MENU;
							}
							break;
						}
						
						default:{
							cout << "Valor fora do menu" << endl;
							break;
						}
					}
				}
			}
			
			F: {
				option = 0;
				Filals Fila;
				while(option != -1){
					cout << "MENU DE OPERAÇÔES" << endl;
					cout << "1: Enfileirar" << endl;
					cout << "2: Desinfileirar" << endl;
					cout << "3: Consultar frente" << endl;
					cout << "4: Imprimir a lista" << endl;
					cout << "5: Sair" << endl;
					cout << "Opção: ";
					cin >> option;
					switch (option){
						case 1:{
							select = 0;
							cout << "Você deseja enfileirar objeto maquina ou pessoa?" << endl;
							cout << "1: Maquina" << endl;
							cout << "2: Pessoa" << endl;
							cin >> select;
							if(select == 2){
					            int id;
					            string nome;
					            float salario;
					            cout << "ID: ";
					            cin >> id;
					            cout << "Nome: ";
					            cin.ignore();
					            getline(cin, nome);
					            cout << "Salario: ";
					            cin >> salario;
								Pessoa* P = new Pessoa(id,nome,salario);
								Fila.enfileirar(P);
								cout << endl;
							}
							else{
					            int id, ativo;
					            string nome;
					            bool atividade;
					            cout << "ID: ";
					            cin >> id;
					            cout << "Nome: ";
					            cin.ignore();
					            getline(cin, nome);
					            cout << "Ativa (1-Sim/0-Nao): ";
					            cin >> ativo;
					            if(ativo == 1){
					            	atividade = true;
								}
								else{
									atividade = false;
								}
					            Maquina* m = new Maquina(id, nome, atividade);								
					            Fila.enfileirar(m);
					            cout << endl;
							}
							break;
						}
						case 2: {
							cout << "O elemento a seguir foi desinfileirado" << endl;
							elemento* busca = Fila.consultarFrente();
							busca->apresentar();
							cout << endl;
							Fila.desenfileirar();
							break;
						}
						case 3:{
							elemento* busca = Fila.consultarFrente();
							busca->apresentar();							
							break;
						}
						
						case 4:{
							Fila.imprimir();
							break;
						}
						
						case 5:{
							int exit = 0;
							cout << "Isto destruirá a lista, deseja proseguir?" << endl;
							cout << "1: Sim" << endl;
							cout << "2: Não" << endl;
							cin >> exit;
							if(exit == 1){
								goto MENU;
							}
							break;
						}
						
						default:{
							cout << "Valor fora do menu" << endl;
							break;
						}
					}
				}	
			}	
		} 		
		FLD:
		{
				option = 0;
				Fila Filad;
				while(option != -1){
					cout << "MENU DE OPERAÇÔES" << endl;
					cout << "1: Enfileirar" << endl;
					cout << "2: Desinfileirar" << endl;
					cout << "3: Consultar frente" <<  endl;
					cout << "4: Imprimir a lista"<< endl;
					cout << "Opção: ";
					cin >> option;
					switch (option){
						case 1:{
							select = 0;
							cout << "Você deseja enfileirar objeto maquina ou pessoa?" << endl;
							cout << "1: Maquina" << endl;
							cout << "2: Pessoa" << endl;
							cin >> select;
							if(select == 2){
					            int id;
					            string nome;
					            float salario;
					            cout << "ID: ";
					            cin >> id;
					            cout << "Nome: ";
					            cin.ignore();
					            getline(cin, nome);
					            cout << "Salario: ";
					            cin >> salario;
								Pessoa* P = new Pessoa(id,nome,salario);
								Filad.enfileirar(P);
							}
							else{
					            int id, ativo;
					            string nome;
					            bool atividade;
					            cout << "ID: ";
					            cin >> id;
					            cout << "Nome: ";
					            cin.ignore();
					            getline(cin, nome);
					            cout << "Ativa (1-Sim/0-Nao): ";
					            cin >> ativo;
					            if(ativo == 1){
					            	atividade = true;
								}
								else{
									atividade = false;
								}
					            Maquina* m = new Maquina(id, nome, atividade);								
					            Filad.enfileirar(m);
							}
							break;
						}
						case 2: {
							cout << "O elemento a seguir foi desinfileirado" << endl;
							Filad.topo();
							cout << endl;
							Filad.desenfileirar();
							break;
						}
						case 3:{
							Filad.topo();							
							break;
						}
						
						case 4:{
							Filad.imprimir();
							break;
						}
						
						case 5:{
							int exit = 0;
							cout << "Isto destruirá a lista, deseja proseguir?" << endl;
							cout << "1: Sim" << endl;
							cout << "2: Não" << endl;
							cin >> exit;
							if(exit == 1){
								goto MENU;
							}
							break;
						}
						
						default:{
							cout << "Valor fora do menu" << endl;
							break;
						}
					}	
				}
			}
	
		PLS:
		{
				option = 0;
				Pilhals Pilha;
				while(option != -1){
					cout << "MENU DE OPERAÇÔES" << endl;
					cout << "1: Empilhar" << endl;
					cout << "2: Desimpilheirar" << endl;
					cout << "3: Consultar topo" <<  endl;
					cout << "4: Imprimir a lista"<< endl;
					cout << "Opção: ";
					cin >> option;
					switch (option){
						case 1:{
							select = 0;
							cout << "Você deseja enfileirar objeto maquina ou pessoa?" << endl;
							cout << "1: Maquina" << endl;
							cout << "2: Pessoa" << endl;
							cin >> select;
							if(select == 2){
					            int id;
					            string nome;
					            float salario;
					            cout << "ID: ";
					            cin >> id;
					            cout << "Nome: ";
					            cin.ignore();
					            getline(cin, nome);
					            cout << "Salario: ";
					            cin >> salario;
								Pessoa* P = new Pessoa(id,nome,salario);
								Pilha.empilhar(P);
							}
							else{
					            int id, ativo;
					            string nome;
					            bool atividade;
					            cout << "ID: ";
					            cin >> id;
					            cout << "Nome: ";
					            cin.ignore();
					            getline(cin, nome);
					            cout << "Ativa (1-Sim/0-Nao): ";
					            cin >> ativo;
					            if(ativo == 1){
					            	atividade = true;
								}
								else{
									atividade = false;
								}
					            Maquina* m = new Maquina(id, nome, atividade);								
					            Pilha.empilhar(m);
							}
							break;
						}
						case 2: {
							cout << "O elemento a seguir foi desempilhado" << endl;
							Pilha.consultarTopo();
							cout << endl;
							Pilha.desempilhar();
							break;
						}
						case 3:{
							Pilha.consultarTopo();				
							break;
						}
						
						case 4:{
							Pilha.Imprimir();
							break;
						}
						
						case 5:{
							int exit = 0;
							cout << "Isto destruirá a lista, deseja proseguir?" << endl;
							cout << "1: Sim" << endl;
							cout << "2: Não" << endl;
							cin >> exit;
							if(exit == 1){
								goto MENU;
							}
							break;
						}
						
						default:{
							cout << "Valor fora do menu" << endl;
							break;
						}
					}
				}			
		}
		
		PLD:{
			option = 0;
			Pilha Pilhad;
			while(option != -1){
				cout << "MENU DE OPERAÇÔES" << endl;
				cout << "1: Empilhar" << endl;
				cout << "2: Desimpilheirar" << endl;
				cout << "3: Consultar topo" <<  endl;
				cout << "4: Imprimir a lista"<< endl;
				cout << "5: Sair" << endl;
				cout << "Opção: ";
				cin >> option;
				switch (option){
				case 1:{
					select = 0;
					cout << "Você deseja enfileirar objeto maquina ou pessoa?" << endl;
					cout << "1: Maquina" << endl;
					cout << "2: Pessoa" << endl;
					cin >> select;
					if(select == 2){
					    int id;
					    string nome;
					    float salario;
					    cout << "ID: ";
					    cin >> id;
					    cout << "Nome: ";
					    cin.ignore();
					    getline(cin, nome);
					    cout << "Salario: ";
					    cin >> salario;
						Pessoa* P = new Pessoa(id,nome,salario);
						Pilhad.empilhar(P);
					}
					else{
					    int id, ativo;
					    string nome;
					    bool atividade;
					    cout << "ID: ";
					    cin >> id;
					    cout << "Nome: ";
					    cin.ignore();
					    getline(cin, nome);
					    cout << "Ativa (1-Sim/0-Nao): ";
					    cin >> ativo;
					    if(ativo == 1){
					        atividade = true;
						}
						else{
							atividade = false;
						}
					    Maquina* m = new Maquina(id, nome, atividade);								
						Pilhad.empilhar(m);
					}
					break;
				}
				case 2: {
					cout << "O elemento a seguir foi desempilhado" << endl;
					Pilhad.ultimo();
					cout << endl;
					Pilhad.desempilhar();
					break;
				}
				case 3:{
					Pilhad.ultimo();				
					break;
				}
						
				case 4:{
					Pilhad.imprimir();
					break;
				}
						
				case 5:{
					int exit = 0;
					cout << "Isto destruirá a lista, deseja proseguir?" << endl;
					cout << "1: Sim" << endl;
					cout << "2: Não" << endl;
					cin >> exit;
					if(exit == 1){
						goto MENU;
					}
					break;
				}
						
				default:{
					cout << "Valor fora do menu" << endl;
					break;
				}
			}
			}
		}
		
		DEQUE:{
			option = 0;
			Deque Deck;
			while(option = -1){
				cout << "MENU DE OPERACAO" << endl;
				cout << "1: Inserir na primeira parte" << endl;
				cout << "2: Inserir na ultima parte" << endl;
				cout << "3: Remover da primeira parte" << endl;
				cout << "4: Remover da ultima parte" << endl;
				cout << "5: Imprimir topo da primeira parte" << endl;
				cout << "6: Imprimir topo da ultima parte" << endl;
				cout << "7: sair";
				cout << "Opção: ";
				cin >> option;
				switch (option){
					case 1:{
						select = 0;
						cout << "Você deseja enfileirar objeto maquina ou pessoa?" << endl;
						cout << "1: Maquina" << endl;
						cout << "2: Pessoa" << endl;
						cin >> select;
						if(select == 2){
					        int id;
					        string nome;
					        float salario;
					        cout << "ID: ";
					        cin >> id;
					        cout << "Nome: ";
					        cin.ignore();
					        getline(cin, nome);
					        cout << "Salario: ";
					        cin >> salario;
							Pessoa* P = new Pessoa(id,nome,salario);
							Deck.inserirFrente(P);
						}
						else{
					        int id, ativo;
					        string nome;
					        bool atividade;
					        cout << "ID: ";
					        cin >> id;
					        cout << "Nome: ";
					        cin.ignore();
					        getline(cin, nome);
					        cout << "Ativa (1-Sim/0-Nao): ";
					        cin >> ativo;
					        if(ativo == 1){
					            atividade = true;
							}
							else{
								atividade = false;
							}
					        Maquina* m = new Maquina(id, nome, atividade);								
					        Deck.inserirFrente(m);
						}
					break;
					}
					case 2:{
						select = 0;
						cout << "Você deseja enfileirar objeto maquina ou pessoa?" << endl;
						cout << "1: Maquina" << endl;
						cout << "2: Pessoa" << endl;
						cin >> select;
						if(select == 2){
					        int id;
					        string nome;
					        float salario;
					        cout << "ID: ";
					        cin >> id;
					        cout << "Nome: ";
					        cin.ignore();
					        getline(cin, nome);
					        cout << "Salario: ";
					        cin >> salario;
							Pessoa* P = new Pessoa(id,nome,salario);
							Deck.inserirTras(P);
						}
						else{
					        int id, ativo;
					        string nome;
					        bool atividade;
					        cout << "ID: ";
					        cin >> id;
					        cout << "Nome: ";
					        cin.ignore();
					        getline(cin, nome);
					        cout << "Ativa (1-Sim/0-Nao): ";
					        cin >> ativo;
					        if(ativo == 1){
					            atividade = true;
							}
							else{
								atividade = false;
							}
					        Maquina* m = new Maquina(id, nome, atividade);								
					        Deck.inserirTras(m);
						}
					break;
					}
					case 3:
						cout << "O elemento a seguir sera removido" << endl;
						Deck.imprimir_inicio();
						Deck.removerFrente();
						break;
						
					case 4: 
						cout << "O elemento a seguir sera removido" << endl;
						Deck.imprimir_ultimo();
						Deck.removerTras();
						break;
					
					case 5:
						Deck.imprimir_inicio();
						break;
						
					case 6:
						Deck.imprimir_ultimo();
						break;
						
					case 7: {
						int select = 0;
						cout << "Sair vai destruir a lista, deseja proseguir?" << endl;
						cout << "1: Sim" << endl;
						cout << "2: Não" << endl;
						cin >> select;
						if(select == 1){
							goto MENU;
						}
						goto MENU;
						break;
					}
			}
		}
	
	}	
	}		
	return 0;
}	
