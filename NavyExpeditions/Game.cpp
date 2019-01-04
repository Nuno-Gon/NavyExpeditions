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
#include "Evento.h"
#include <vector>
#include <ctime>

Game::Game(Configuration config) {
	this->config = config;
}

void Game::run() {
	string comando;
	vector<string> cmds;
	bool val = false;
	setGrelha();
	setPortos();
	jog.setMoney(config.getMoedas());

	do {
		//Fases
		//Comandos:
		do {
			Consola::clrscr();
			displayMap(); //Aparecer 2x2 com cores
			displayShips();
			displayShipsP();
			Consola::setBackgroundColor(Consola::PRETO);
			displayMenuTwo();
		
			getline(cin, comando);
			if (comando == "prox") {
		//Execucao de comandos pendentes / comportamento auto:
				for (unsigned int i = 0; i < cmds.size(); i++){
					resolveCommand(cmds[i]);
					cin.get();
				}
				//myvector.clear() para limpar para o proximo prox
				cmds.clear();
			}
			else if (confirmaComando(comando) == true) {
				//colocar no vetor de comandos a ser executados
				cmds.push_back(comando);
			}

		} while (comando != "prox");
		
		autoPhase();
		//Combates:
		combatPhase();
		
		//Eventos:
		eventPhase();
		//Piratas:

	} while (val != true);
}
void Game::eventPhase() {
	srand((unsigned int)time(NULL));
	bool r = (rand() % 100) < config.getProbEvento();
	//bool r = true;
	if (r == true) {
		Evento ev(config.getProbCalmaria(), config.getProbMotim(), config.getProbSereias(), config.getProbTempestade());
	}
	else
		cout << "Nao ocorreu evento!" << endl;
	cin.get();
}
void Game::autoPhase() {
	jog.autoEscuna(grelha);
	jog.verifcaEscuna();
	jog.moverFragataAut(pir.getVectorNavios());
}
void Game::combatPhase() {
	jog.combateNavios(pir.getVectorNavios());
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
void Game::setPortos() {
	char c;
	for (unsigned int i = 0; i < grelha.size(); i++) {
		for (unsigned int j = 0; j < grelha[i].size(); j++) {
			c = grelha[i][j].getImg();
			if (isupper(c))
				jog.setPorto(Porto(i, j));
			else if (islower(c))
				pir.setPorto(Porto(i, j));
		}
	}
}
void Game::displayMap() {
	int x = 1, y = 1, change = 0;

	for (unsigned int i = 0; i < grelha.size(); i++) {
		for (unsigned int j = 0; j < grelha[i].size(); j++) {
			Consola::gotoxy(x, y);
			if (i % 2 != 0) {
				if (j % 2 != 0) {
					Consola::setBackgroundColor(Consola::AMARELO_CLARO);
					Consola::gotoxy(x + 1, y);
					cout << " ";
					Consola::setBackgroundColor(Consola::AMARELO_CLARO);
					Consola::gotoxy(x + 1, y + 1);
					cout << " ";
					Consola::setBackgroundColor(Consola::AMARELO_CLARO);
					Consola::gotoxy(x, y + 1);
					cout << " ";
					Consola::setBackgroundColor(Consola::AMARELO_CLARO);
					Consola::gotoxy(x, y);
					cout << " ";
					Consola::setTextColor(Consola::PRETO);
					cout << grelha[i][j];
					x += 2;
				}
				else {
					Consola::setBackgroundColor(Consola::AZUL);
					Consola::gotoxy(x + 1, y);
					cout << " ";
					Consola::setBackgroundColor(Consola::AZUL);
					Consola::gotoxy(x + 1, y + 1);
					cout << " ";
					Consola::setBackgroundColor(Consola::AZUL);
					Consola::gotoxy(x, y + 1);
					cout << " ";
					Consola::setBackgroundColor(Consola::AZUL);
					Consola::gotoxy(x, y);
					cout << " ";
					Consola::setTextColor(Consola::BRANCO);
					cout << grelha[i][j];
					x += 2;
				}
			}
			else {
				if (j % 2 == 0) {
					Consola::setBackgroundColor(Consola::AMARELO_CLARO);
					Consola::gotoxy(x + 1, y);
					cout << " ";
					Consola::setBackgroundColor(Consola::AMARELO_CLARO);
					Consola::gotoxy(x + 1, y + 1);
					cout << " ";
					Consola::setBackgroundColor(Consola::AMARELO_CLARO);
					Consola::gotoxy(x, y + 1);
					cout << " ";
					Consola::setBackgroundColor(Consola::AMARELO_CLARO);
					Consola::gotoxy(x, y);
					cout << " ";
					Consola::setTextColor(Consola::PRETO);
					cout << grelha[i][j];
					x += 2;
				}
				else {
					Consola::setBackgroundColor(Consola::AZUL);
					Consola::gotoxy(x + 1, y);
					cout << " ";
					Consola::setBackgroundColor(Consola::AZUL);
					Consola::gotoxy(x + 1, y + 1);
					cout << " ";
					Consola::setBackgroundColor(Consola::AZUL);
					Consola::gotoxy(x, y + 1);
					cout << " ";
					Consola::setBackgroundColor(Consola::AZUL);
					Consola::gotoxy(x, y);
					cout << " ";
					Consola::setTextColor(Consola::BRANCO);
					cout << grelha[i][j];
					x += 2;
				}
			}
		}
		x = 1;
		y += 2;
		cout << endl;
	}

	Consola::setTextColor(Consola::BRANCO);
}
void Game::displayShips() {
	int x, y;
	char c;
	auto i = jog.getVectorNavios();

	for (unsigned int j = 0; j < jog.getVectorNavios().size(); j++) {
		x = (i[j].getY() * 2) + 2;
		y = (i[j].getX() * 2) + 1;
		c = i[j].getIcon();

		Consola::gotoxy(x, y);
		Consola::setBackgroundColor(Consola::BRANCO);
		Consola::setTextColor(Consola::VERDE);
		cout << c;
		Consola::setTextColor(Consola::BRANCO);
		Consola::setBackgroundColor(Consola::PRETO);
	}
}

void Game::displayShipsP() {
	int x, y;
	char c;
	auto i = pir.getVectorNavios();

	for (unsigned int j = 0; j < pir.getVectorNavios().size(); j++) {
		x = (i[j].getY() * 2) + 2;
		y = (i[j].getX() * 2) + 1;
		c = i[j].getIcon();

		Consola::gotoxy(x, y);
		Consola::setBackgroundColor(Consola::BRANCO);
		Consola::setTextColor(Consola::VERMELHO);
		cout << c;
		Consola::setTextColor(Consola::BRANCO);
		Consola::setBackgroundColor(Consola::PRETO);
	}
}

void Game::displayLista() {
//	Consola::gotoxy(45, 0);
	cout << endl;
	cout << "--- Lista de Precos --- " << endl;
	cout << "Navio - " << config.getPrecoNavio() <<  " moedas" << endl;
	cout << "Soldado - " << config.getPrecoSoldado() << " moeda" << endl; // receber valor da quantidade de soldados
	cout << "Venda de peixe - " << config.getPrecoVendPeixe() << " moedas" << endl;
	cout << "Venda de mercadoria - " << config.getPrecoVendMercad() << " moedas" << endl;
	cout << "Compra de mercadoria - " << config.getPrecoCompMercad() << " moedas" << endl;
	cout << "\nDinheiro disponivel - " << jog.getMoney() << " moedas" << endl;
}
void Game::displayInfoShips() {
	int n = 0;
	auto i = jog.getVectorNavios();
	Consola::gotoxy(78, 0);
	cout << "Info dos Navios --- \n" << endl;
	if (jog.getVectorNavios().empty()) {
		Consola::gotoxy(78, 1);
		cout << "Nao existem Navios" << endl;
		return;
	}
	for (unsigned int j = 0; j < i.size(); j++) {
		Consola::gotoxy(78, n+j+1);
		cout << "Nr: " << i[j].getId() << " - Tipo: " << i[j].getIcon() << endl;
		Consola::gotoxy(78, n+j+2);
		cout << "Coordenadas: " << "(" << i[j].getX() << "," << i[j].getY() << ")" << endl;
		Consola::gotoxy(78, n + j + 3);
		cout << "Solados: " << i[j].getSoldados() << endl;
		Consola::gotoxy(78, n + j + 4);
		cout << "Mercadorias: " << i[j].getMercadoria() << " - Peixe: " << i[j].getPeixe() << endl;
		Consola::gotoxy(78, n + j + 5);
		cout << "Agua: " << i[j].getAgua() << endl;

		n += 5;
	}
}
void Game::displayMenuTwo() {
	string comando;
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
	cout << "infonavios" << endl;
	Consola::gotoxy(45, 21);
	cout << "sair" << endl;
	cout << endl;
	Consola::gotoxy(45, 22);
	cout << "Comando: ";
}
bool Game::confirmaComando(string comando) {
	string c;
	istringstream iss(comando);
	iss >> c;
	if (c == "compranav" || c == "vendenav" || c == "compra" || c == "vende" || c == "move" || c == "auto" || c == "stop" || c == "pirata" || c == "vaipara" || c == "comprasold") {
		return true;
	}
	else if (c == "sair" || c == "exec" || c == "lista" || c == "moedas" || c == "infonavios" || c == "evpos" || c == "evnav" || c == "saveg" || c == "loadg" || c == "delg") {
		resolveCommand(comando);
		cin.get();
		return false;
	}	
	else{
		cout << "Comando: '" << comando << "' inexistente!!" << endl;
		cin.get();
		return false;
	}
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
		//feito fora
	}
	else if (cmd == "compranav") {
		iss >> cmd; // fica com o tipo de navio a ser comprado
		jog.compraNav(cmd, config.getPrecoNavio());
	}
	else if (cmd == "vendenav") {
		iss >> cmd; //<N>
		jog.vendeNavio(cmd, config.getPrecoVendMercad(), config.getPrecoVendPeixe(), config.getPrecoNavio());
	}
	else if (cmd == "lista") {
		displayLista();
	}
	else if (cmd == "compra") {
		int i;
		int q;
		iss >> i; //<N><M>
		iss >> q;
		jog.compraMercadorias(i, q, config.getPrecoCompMercad());
	}
	else if (cmd == "vende") {
		int i;
		iss >> i; //<N>
		jog.vendeMercadorias(i, config.getPrecoVendMercad(), config.getPrecoVendPeixe());
	}
	else if (cmd == "move") {
		int n;
		string x;//<N><X>
		iss >> n;
		iss >> x;
		jog.moveNavios(n, x, grelha);
	}
	else if (cmd == "auto") {
		int i;
		iss >> i; //<N>
		jog.ativarMovimentoAuto(i);
	}
	else if (cmd == "stop") {
		int i;
		iss >> i; //<N>
		jog.movimentoStop(i);
	}
	else if (cmd == "pirata") {
		int i;
		int j;
		iss >> i;
		iss >> j;
		iss >> cmd; //<x><y><t>
		pir.inserePirata(i, j, cmd);
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
		int i;
		int s;
		iss >> i; //<N><S>
		iss >> s;
		jog.compraSoldados(i, s, config.getPrecoSoldado());
	}
	else if (cmd == "saveg") {
		iss >> cmd; //<nome>
		save(cmd);
	}
	else if (cmd == "loadg") {
		iss >> cmd; //<nome>
		load(cmd);
	}
	else if (cmd == "delg") {
		iss >> cmd; //<nome>
		del(cmd);
	}
	else if (cmd == "sair") {
		char op;
		cout << "Deseja sair? (S/N) ";
		cin.get(op);
		if(op == 's' || op == 'S')
			exit(0);
	}
	else if (cmd == "infonavios") {
		displayInfoShips();
	}
	else
		cout << "Comando: '" << comando << "' inexistente!" << endl;
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
	ofstream myfile;
	myfile.open(nome);

	if (!myfile.is_open()) {
		cout << "Erro a abrir o ficheiro para escrita!" << endl;
		return;
	}

	Configuration c;
	c = this->config;
	myfile << c.getLinhas() << endl;
	myfile << c.getColunas() << endl;
	myfile << c.getMoedas() << endl;
	myfile << c.getProbPirata() << endl;
	myfile << c.getPrecoNavio() << endl;
	myfile << c.getPrecoSoldado() << endl;
	myfile << c.getPrecoVendPeixe() << endl;
	myfile << c.getPrecoCompMercad() << endl;
	myfile << c.getPrecoVendMercad() << endl;
	myfile << c.getSoldadosPorto() << endl;
	myfile << c.getProbEvento() << endl;
	myfile << c.getProbTempestade() << endl;
	myfile << c.getProbSereias() << endl;
	myfile << c.getProbCalmaria() << endl;
	myfile << c.getProbMotim() << endl;
	for (int i = 0; i < c.getLinhas(); i++) {
		for (int j = 0; j < c.getColunas(); j++) {
			myfile << c.map[i][j];
		}
		myfile << endl;
	}


	Jogador j;
	j = this->jog;
	vector<Navio> n = this->jog.getVectorNavios();

	myfile << j.getMoney() << endl;
	for (unsigned int i = 0; i < n.size(); i++) {
		myfile << n[i].getId() << endl;
		myfile << n[i].getSoldados() << endl;
		myfile << n[i].getMercadoria() << endl;
		myfile << n[i].getPeixe() << endl;
		myfile << n[i].getAgua() << endl;
		myfile << n[i].getDeriva() << endl;
		myfile << n[i].getAut() << endl;
		myfile << n[i].getIcon() << endl;
		myfile << n[i].getX() << endl;
		myfile << n[i].getY() << endl;
	}

	vector<Porto> po = this->jog.getVectorPortos();
	for (unsigned int i = 0; i < po.size(); i++) {
		myfile << po[i].getX() << " " << po[i].getY() << endl;
	}

	/*Pirata p;
	p = this->pir;
	*/
	myfile.close();
}
void Game::load(string nome) {
	ifstream myfile;
	myfile.open(nome);
	string line;

	if (!myfile.is_open()) {
		cout << "Erro a abrir o ficheiro para escrita!" << endl;
		return;
	}


	config.~Configuration();
	getline(myfile, line);
	config.setLinhas(stoi(line));
	line.clear();
	getline(myfile, line);
	config.setColunas(stoi(line));
	line.clear();
	getline(myfile, line);
	config.setMoedas(stoi(line));
	line.clear();
	getline(myfile, line);
	config.setProbPirata(stoi(line));
	line.clear();
	getline(myfile, line);
	config.setPrecoNavio(stoi(line));
	line.clear();
	getline(myfile, line);
	config.setPrecoSoldado(stoi(line));
	line.clear();
	getline(myfile, line);
	config.setPrecoVendPeixe(stoi(line));
	line.clear();
	getline(myfile, line);
	config.setPrecoCompMercad(stoi(line));
	line.clear();
	getline(myfile, line);
	config.setPrecoVendMercad(stoi(line));
	line.clear();
	getline(myfile, line);
	config.setSoldadosPorto(stoi(line));
	line.clear();
	getline(myfile, line);
	config.setProbEvento(stoi(line));
	line.clear();
	getline(myfile, line);
	config.setProbTempestade(stoi(line));
	line.clear();
	getline(myfile, line);
	config.setProbSereias(stoi(line));
	line.clear();
	getline(myfile, line);
	config.setProbCalmaria(stoi(line));
	line.clear();
	getline(myfile, line);
	config.setProbMotim(stoi(line));
	line.clear();

	for (int i = 0; i < config.getLinhas(); i++) {
		getline(myfile, line);
		config.map.push_back(line);
		line.clear();
	}

	myfile.close();
}
void Game::del(string nome) {

	const char * c = nome.c_str();

	if (remove(c) != 0)
		perror("Error deleting file");
	else
		puts("File successfully deleted");
	return;
}

Game::~Game(){}