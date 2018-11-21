#include "stdafx.h"
#include "Game.h"


Game::Game()
{
}

void Game::displayMenuTwo(string *comando) {
	cout << "--- Lista de Comandos Fase 2 --- \n" << endl;
	cout << endl;
	cout << "exec <nomeFicheiro>" << endl;
	//Resto dos comandos
	//...
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
