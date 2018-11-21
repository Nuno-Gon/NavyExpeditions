#include "stdafx.h"
#include "Game.h"


Game::Game()
{
}

void Game::displayMenuTwo(string *comando) {
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
	getline(cin, *comando);
}

void Game::getFileCommands(bool *val, string fich) {
	string cmd;
	fstream file;
	file.open(fich);

	if (file.fail()) {
		cerr << "Erro ao abrir ficheiro!" << endl;
		cout << "Press enter to continue..." << endl;
		cin.get();
	}
	else {
		while (!file.eof()) {
			getline(file, cmd);
			//resolveCommands(*val, cmd);
		}
	}
}

Game::~Game()
{
}
