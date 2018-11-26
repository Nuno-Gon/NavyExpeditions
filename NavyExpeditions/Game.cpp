#include "stdafx.h"
#include "Game.h"
#include "Navio.h"
#include "Veleiro.h"
#include "Escuna.h"
#include "Fragata.h"
#include "Galeao.h"
#include "Porto.h"
#include "Jogador.h"
#include <vector>
#include <ctime>

Game::Game(Configuration config) {
	this->config = config;
}

void Game::run() {
	string comando;
	bool val = false;

	do {
		system("cls");
		displayMap();
		displayMenuTwo();	
		resolveCommand(comando);

		auto i = config.map.begin();
		cout << i[2][10] << endl;

		cout << endl;
		system("pause");
	} while (val != true);
}

void Game::displayMap() {
	for (auto i = config.map.begin(); i != config.map.end(); ++i) {
		cout << *i << endl;
	}
	cout << endl;
	cin.get();
}

void Game::displayMenuTwo() {
	string comando;
	system("cls");
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
	resolveCommand(comando);
}

void Game::resolveCommand(string comando) {
	string cmd;
	istringstream iss(comando);
	iss >> cmd;
	srand((unsigned int)time(NULL));

	// Ver qual é o comando
	if (cmd == "exec") {
		iss >> cmd; //fica com o nome do ficheiro guardado
		getFileCommands(cmd);
	}
	else {
		if (cmd == "compranav") {
			iss >> cmd; // fica com o tipo de navio a ser comprado
			if (cmd == "v") {
				Veleiro v;
				v.setX(rand() % 20);
				v.setY(rand() % 10);
				jog.setVeleiro(v);
				cout << "Comprou um navio do tipo Veleiro" << endl;
			}
			else if (cmd == "e") {
				Escuna e;
				cout << "Comprou um navio do tipo Escuna" << endl;
			}
			else if (cmd == "g") {
				Galeao g;
				cout << "Comprou um navio do tipo Galeao" << endl;
			}
			else if (cmd == "f") {
				Fragata f;
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
