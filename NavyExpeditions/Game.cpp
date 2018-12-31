#include "stdafx.h"
#include "Game.h"
#include "Navio.h"
#include "Veleiro.h"
#include "Escuna.h"
#include "Fragata.h"
#include "Galeao.h"
#include "Porto.h"
#include "Jogador.h"
#include "Consola.h"
#include <vector>
#include <ctime>

Game::Game(Configuration config) {
	this->config = config;
}

void Game::run() {
	string comando;
	bool val = false;
	setGrelha();

	do {
		//Fases
		//Comandos:
		Consola::clrscr();
		displayMap(); //Aparecer 2x2 com cores
		displayShips();
		Consola::setBackgroundColor(Consola::PRETO);

		//Execucao de comandos pendentes / comportamento auto:
		displayMenuTwo();
		Consola::gotoxy(0, 21);
		system("pause");

		//Combates:

		//Eventos:

		//Piratas:

	} while (val != true);
}
void Game::setGrelha() {
	/*passar o mapa de um Vetor de Strings (primeira meta)
	* para um vetor 2D de Celulas
	* cada Celula têm um Ponteiro *t para o tipo
	* de Terreno -> (Mar,Terra,Porto)
	*/
	for (int i = 0; i < config.getLinhas(); i++) {
		grelha.push_back(vector<Celula>());
		for (int j = 0; j < config.getColunas(); j++) {
			grelha[i].push_back(Celula(config.map[i][j]));
		}
	}
}

void Game::displayMap() {
	int x = 1, y = 1, change = 0;

	for (unsigned int i = 0; i < grelha.size(); i++) {
		for (unsigned int j = 0; j < grelha[i].size(); j++) {
			Consola::gotoxy(x, y);
			//BACKGROUND COLORS AO XADREZ

			cout << grelha[i][j];
			x += 2;
		}
		x = 1;
		y += 2;
		cout << endl;
	}
}
void Game::displayShips() {
	int x, y;
	char c;
	auto i = jog.getVectorNavios();

	for (unsigned int j = 0; j < jog.getVectorNavios().size(); j++) {
		x = i[j].getX();
		y = i[j].getY();
		c = i[j].getIcon();

		Consola::gotoxy(x, y);
		cout << c;
	}
}
void Game::displayLista() {
//	Consola::gotoxy(45, 0);
	cout << endl;
	cout << "--- Lista de Precos --- " << endl;
	cout << "Comprar 1 navio - 100 moedas" << endl;
	cout << "Comprar soldados 1 - 1 moeda" << endl; // receber valor da quantidade de soldados
	cout << "Comprar Mercadoria - X" << endl;
	//lista varia valor entre portos?
}

void Game::displayMenuTwo() {
	string comando;
	//system("cls");
	//cout << endl;
	Consola::gotoxy(45, 0);
	cout << "--- Lista de Comandos Fase 2 --- \n" << endl;
	Consola::gotoxy(45, 1);
	cout << "exec <nomeFicheiro>" << endl;
	Consola::gotoxy(45, 2);
	cout << "prox" << endl;
	Consola::gotoxy(45, 3);
	cout << "compranav <T>" << endl;
	Consola::gotoxy(45, 4);
	cout << "vendenav <T>" << endl;
	Consola::gotoxy(45, 5);
	cout << "lista" << endl;
	Consola::gotoxy(45, 6);
	cout << "compra <N><M>" << endl;
	Consola::gotoxy(45, 7);
	cout << "vende <N>" << endl;
	Consola::gotoxy(45, 8);
	cout << "move <N><X>" << endl;
	Consola::gotoxy(45, 9);
	cout << "auto <N>" << endl;
	Consola::gotoxy(45, 10);
	cout << "stop <N>" << endl;
	Consola::gotoxy(45, 11);
	cout << "pirata <X><Y><T>" << endl;
	Consola::gotoxy(45, 12);
	cout << "evpos <E><X><Y>" << endl;
	Consola::gotoxy(45, 13);
	cout << "evnav <E><N>" << endl;
	Consola::gotoxy(45, 14);
	cout << "moedas <N>" << endl;
	Consola::gotoxy(45, 15);
	cout << "vaipara <N><X><Y>" << endl;
	Consola::gotoxy(45, 16);
	cout << "comprasold <N><S>" << endl;
	Consola::gotoxy(45, 17);
	cout << "saveg <nome>" << endl;
	Consola::gotoxy(45, 18);
	cout << "loadg <nome>" << endl;
	Consola::gotoxy(45, 19);
	cout << "delg <nome>" << endl;
	Consola::gotoxy(45, 20);
	cout << "sair" << endl;
	cout << endl;
	Consola::gotoxy(45, 21);
	cout << "Comando: ";
	getline(cin, comando);

	resolveCommand(comando);
}
void Game::resolveCommand(string comando) {
	string cmd;
	istringstream iss(comando);
	iss >> cmd;
	
	// Ver qual é o comando
	if (cmd == "exec") {
		iss >> cmd; //fica com o nome do ficheiro guardado
		getFileCommands(cmd);
	}
	else if (cmd == "prox") {
		//... gravar os comandos numa string e só depois executar
		// ou fazer um do{ displaymenuTwo }whilte(prox) e depois correr os comandos
		// dunno...
	}
	else if (cmd == "compranav") { 
			iss >> cmd; // fica com o tipo de navio a ser comprado
			jog.compraNav(cmd);	
	}
	else if (cmd == "vendenav") {
		iss >> cmd; //<N>
	}
	else if (cmd == "lista") {
		displayLista();
	} 
	else if (cmd == "compra") {
		iss >> cmd; //<N><M>
	}
	else if (cmd == "vende") {
		iss >> cmd; //<N>
	}
	else if (cmd == "move") {
		iss >> cmd; //<N><X>
	}
	else if (cmd == "auto") {
		iss >> cmd; //<N>
	}
	else if (cmd == "stop") {
		iss >> cmd; //<N>
	}
	else if (cmd == "pirata") {
		iss >> cmd; //<x><y><t>
	}
	else if (cmd == "evpos") {
		iss >> cmd; //<E><x><y>
	}
	else if (cmd == "evnav") {
		iss >> cmd; //<E><N>
	}
	else if (cmd == "moedas") {
		iss >> cmd; //<N>
	}
	else if (cmd == "vaipara") { //Corresponde a 2 comandos difrentes dependendo dos valores a seguir
		//<N><x><y>
		//<N><P>
	}
	else if (cmd == "comprasold") {
		iss >> cmd; //<N><S>
	}
	else if (cmd == "saveg") {
		iss >> cmd; //<nome>
		save(cmd);
	}
	else if (cmd == "loadg") {
		iss >> cmd; //<nome>
	}
	else if (cmd == "delg") {
		iss >> cmd; //<nome>
	}
	else if (cmd == "sair") {
		exit(0);
	}

	//Jogador::moedas = Jogador::moedas - 100;
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
			string cmd;
			istringstream iss(line);
			resolveCommand(line);
		}
	}
}

void Game::save(string nome) {
	//Precisa de construtor por copia, mas depois como o vetor 2d de Celulas têm ponteiros têm que se criar algo para copiar lá, still searching
	
	/*There are 2 types of copying: copy constructor when you create object on a non initialized space and copy operator where you need to release the old state of the object before setting new state.*/
	
	ofstream file_obj;
	file_obj.open(nome, ios::app);
//https://stackoverflow.com/questions/12902751/how-to-clone-object-in-c-or-is-there-another-solution
	//Game *g = this;
	/*g.config = this->config;
	g.jog = this->jog;
	g.grelha = this->grelha;*/
	//file_obj.write((char*)&g, sizeof(g));
	file_obj.close();
}
/* Game::load(string nome) {
	ifstream file_obj;
	file_obj.open(nome, ios::in);
	Game game;
	file_obj.read((char*)&game, sizeof(game));
}

void Game::del(string nome) {}*/

Game::~Game(){}