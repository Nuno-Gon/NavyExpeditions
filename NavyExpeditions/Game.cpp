#include "stdafx.h"
#include "Game.h"
#include "Configuration.h"
#include "Navio.h"
#include "Veleiro.h"
#include "Escuna.h"
#include "Fragata.h"
#include "Galeao.h"
#include "Porto.h"
#include "Jogador.h"
#include <vector>

Game::Game(Configuration config) {
	this->config = config;
}

void Game::displayMenuTwo(/*string *comando*/) {
	string comando;
	cout << "--- Lista de Comandos Fase 2 --- \n" << endl;
	cout << endl;
	cout << "exec <nomeFicheiro>" << endl;
	cout << "prox" << endl;
	cout << "compranav <T>" << endl;
	cout << "vendenav <T>" << endl;
	cout << "lista" << endl;
	cout << "compra <N><M>" << endl;
	cout << "vende <N>" << endl;
	cout << "move <N><X>" << endl;
	cout << "auto <N>" << endl;
	cout << "stop <N>" << endl;
	cout << "pirata <X><Y><T>" << endl;
	cout << "evpos <E><X><Y>" << endl;
	cout << "evnav <E><N>" << endl;
	cout << "moedas <N>" << endl;
	cout << "vaipara <N><X><Y>" << endl;
	cout << "comprasold <N><S>" << endl;
	cout << "saveg <nome>" << endl;
	cout << "loadg <nome>" << endl;
	cout << "delg <nome>" << endl;
	cout << "sair" << endl;
	cout << endl;
	cout << "Comando: " << endl;
	getline(cin, comando);
	getCommand(comando);
}

void Game::getCommand(string comando) {
	string cmd;
	istringstream iss(comando);
	iss >> cmd;

	// Ver qual é o comando
	if (cmd == "exec") {
		iss >> cmd; //fica com o nome do ficheiro guardado
		getFileCommands(cmd);
	}
	else {
		if (cmd == "compranav") {
			int i=0;
			iss >> cmd; // fica com o tipo de navio a ser comprado
			//for (i = 0; !Jogador::navios.empty(); i++);
			if (cmd == "v") {
				Veleiro v(i);
				cout << "Comprou um navio do tipo Veleiro" << endl;
			}
			else if (cmd == "e") {
				Escuna e(i);
				cout << "Comprou um navio do tipo Escuna" << endl;
			}
			else if (cmd == "g") {
				Galeao g(i);
				cout << "Comprou um navio do tipo Galeao" << endl;
			}
			else if (cmd == "f") {
				Fragata f(i);
				cout << "Comprou um navio do tipo Fragata" << endl;
			}
			else {
				cout << "Tipo de navio inexistente!" << endl;
				return;
			}

			//Jogador::moedas = Jogador::moedas - 100;
		}
	}
}
void Game::getFileCommands(string fich) {
	string cmd;
	string line;
	fstream file;
	file.open(fich);

	if (file.fail()) {
		cerr << "Erro ao abrir ficheiro!" << endl;
		cout << "Press enter to continue..." << endl;
		cin.get();
	}
	else {
		while (!file.eof()) {
			getline(file, line);
			// interpreta o comando e executa
		}
	}
}

Game::~Game()
{
}
