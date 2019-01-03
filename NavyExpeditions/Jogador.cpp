#include "stdafx.h"
#include "Jogador.h"
#include "Veleiro.h"
#include "Escuna.h"
#include "Fragata.h"
#include "Galeao.h"
#include "Game.h"
#include <ctime>

Jogador::Jogador() {}

void Jogador::setVeleiro(Veleiro v) {
	navios.push_back(v);
}
void Jogador::setEscuna(Escuna e) {
	navios.push_back(e);
}
void Jogador::setFragata(Fragata f) {
	navios.push_back(f);
}
void Jogador::setGaleao(Galeao g) {
	navios.push_back(g);
}
void Jogador::setIate(Iate i) {
	navios.push_back(i);
}
void Jogador::setMoney(int m) {
	this->money = this->money + m;
}

int Jogador::getMoney() {
	return this->money;
}
vector<Navio> Jogador::getVectorNavios() {
	return navios;
}
void Jogador::setPorto(Porto p) {
	portos.push_back(p);
}
vector<Porto> Jogador::getVectorPortos() {
	return portos;
}
void Jogador::moveNavios(int n, string x, vector <vector <Celula>>& grelha) {
	//converter a string x para UPPER CASE
	x[0] = toupper(x[0]);
	x[1] = toupper(x[1]);

	for (unsigned int i = 0; i < grelha.size(); i++) {
		for (unsigned int j = 0; j < grelha[i].size(); j++) {
			if (grelha[i][j].getImg() == '+');
		}
	}

	for (unsigned int i = 0; i < navios.size(); i++) {
		if (navios[i].getId() == n) {
			int xx = navios[i].getX();
			int yy = navios[i].getY();

			if (x == "D") {
				if (grelha[xx][yy+1].getImg() == '+') {
					cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
					break;
				}
				else
					navios[i].setY(navios[i].getY() + 1);
			}
			else if (x == "E"){
				if (grelha[xx][yy - 1].getImg() == '+') {
					cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
					break;
				}
				else
					navios[i].setY(navios[i].getY() - 1);
			}
			else if (x == "C"){
				if (grelha[xx-1][yy].getImg() == '+') {
					cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
					break;
				}
				else
					navios[i].setX(navios[i].getX() - 1);
			}
			else if (x == "B") {
				if (grelha[xx+1][yy].getImg() == '+') {
					cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
					break;
				}
				else
					navios[i].setX(navios[i].getX() + 1);
			}
			else if (x == "CE") {
				if (grelha[xx-1][yy-1].getImg() == '+') {
					cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
					break;
				}
				else {
					navios[i].setX(navios[i].getX() - 1);
					navios[i].setY(navios[i].getY() - 1);
				}
			}
			else if (x == "CD") {
				if (grelha[xx-1][yy + 1].getImg() == '+') {
					cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
					break;
				}
				else {
					navios[i].setX(navios[i].getX() - 1);
					navios[i].setY(navios[i].getY() + 1);
				}
			}
			else if (x == "BE") {
				if (grelha[xx + 1][yy - 1].getImg() == '+') {
					cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
					break;
				}
				else {
					navios[i].setX(navios[i].getX() + 1);
					navios[i].setY(navios[i].getY() - 1);
				}
			}
			else if (x == "BD") {
				if (grelha[xx + 1][yy + 1].getImg() == '+') {
					cout << "Tentativa de movimento para a terra, barco atracou na costa." << endl;
					break;
				}
				else {
					navios[i].setX(navios[i].getX() + 1);
					navios[i].setY(navios[i].getY() + 1);
				}
			}
			else
				cout << "Comando movimento incorreto!" << endl;
		}
	}
}

void Jogador::compraNav(string tipo) {
	if (tipo == "v") {
		Veleiro v;
		v.setX(portos[0].getX()); //criar navio no porto principal
		v.setY(portos[0].getY()); //ir buscar o primeiro porto do vetor de portos, ou seja o principal
		setVeleiro(v);
		cout << "Comprou um navio do tipo Veleiro" << endl;
	}
	else if (tipo == "e") {
		Escuna e;
		e.setX(portos[0].getX());
		e.setY(portos[0].getY());
		setEscuna(e);
		cout << "Comprou um navio do tipo Escuna" << endl;
	}
	else if (tipo == "g") {
		Galeao g;
		g.setX(portos[0].getX());
		g.setY(portos[0].getY());
		setGaleao(g);
		cout << "Comprou um navio do tipo Galeao" << endl;
	}
	else if (tipo == "f") {
		Fragata f;
		f.setX(portos[0].getX());
		f.setY(portos[0].getY());
		setFragata(f);
		cout << "Comprou um navio do tipo Fragata" << endl;
	}
	else if (tipo == "i") {
		Iate i;
		i.setX(portos[0].getX());
		i.setY(portos[0].getY());
		setIate(i);
		cout << "Comprou um navio do tipo Iate" << endl;
	}
	else {
		cout << "Tipo de navio inexistente!" << endl;
		return;
	}
}

void Jogador::verifcaEscuna() {
	for (unsigned int i = 0; i < navios.size(); i++) {
		if (navios[i].getIcon() == 'v' || navios[i].getIcon() == 'g' || navios[i].getIcon() == 'i') {
			for (unsigned int j = 0; j < navios.size(); j++) {
				if ((navios[i].getX() == navios[j].getX() - 1 || navios[i].getX() == navios[j].getX() || navios[i].getX() == navios[j].getX() + 1)
					&& (navios[i].getY() == navios[j].getY() - 1 || navios[i].getY() == navios[j].getY() || navios[i].getY() == navios[j].getY() + 1)) {
					if (navios[i].getIcon() == 'v') {
						if (40 - navios[i].getMercadoria() > navios[j].getMercadoria()) {
							navios[i].setMercadorias(navios[j].getMercadoria());
							navios[j].setMercadorias(-navios[j].getMercadoria());
						}
						else {
							navios[j].setMercadorias(-(40 - navios[i].getMercadoria()));
							navios[i].setMercadorias(40 - navios[i].getMercadoria());
						}
					}
					else if (navios[i].getIcon() == 'g') {
						if (70 - navios[i].getMercadoria() > navios[j].getMercadoria()) {
							navios[i].setMercadorias(navios[j].getMercadoria());
							navios[j].setMercadorias(-navios[j].getMercadoria());
						}
						else {
							navios[j].setMercadorias(-(70 - navios[i].getMercadoria()));
							navios[i].setMercadorias(70 - navios[i].getMercadoria());
						}
					}
					else if (navios[i].getIcon() == 'i') {
						if (100 - navios[i].getMercadoria() > navios[j].getMercadoria()) {
							navios[i].setMercadorias(navios[j].getMercadoria());
							navios[j].setMercadorias(-navios[j].getMercadoria());
						}
						else {
							navios[j].setMercadorias(-(100 - navios[i].getMercadoria()));
							navios[i].setMercadorias(100 - navios[i].getMercadoria());
						}
					}
				}
			}
		}
	}
}

void Jogador::compraMercadorias(int id, int quantidade, int preco) {
	
	bool done = false;
	for (unsigned int i = 0; i < navios.size(); i++) {
		if (navios[i].getId() == id) {
			for (unsigned int j = 0; j < portos.size(); j++) {
				if (navios[i].getX() == portos[j].getX() && navios[i].getY() == portos[j].getY()) {
					if (navios[i].setMercadorias(quantidade)) {
						setMoney(-(quantidade * preco));
					}
					done = true;
				}
			}
			if (!done) {
				cout << "O navio escolhido nao esta num porto";
			}
		}
	}
}

void Jogador::vendeMercadorias(int id, int precoM, int precoP) {
	bool done = false;
	for (unsigned int i = 0; i < navios.size(); i++) {
		if (navios[i].getId() == id) {
			for (unsigned int j = 0; j < portos.size(); j++) {
				if (navios[i].getX() == portos[j].getX() && navios[i].getY() == portos[j].getY()) {
					setMoney(navios[i].getMercadoria() * precoM);
					setMoney(navios[i].getPeixe() * precoP);
					navios[i].setMercadorias(-navios[i].getMercadoria());
					navios[i].setPeixe(-navios[i].getPeixe());
					done = true;
				}
			}
			if (!done) {
				cout << "O navio escolhido nao esta num porto";
			}
		}
	}
}

void Jogador::vendeNavio(char tipo, int precoM, int precoP, int precoN) {
	bool done = false;
	for (unsigned int i = 0; i < navios.size(); i++) {
		if (navios[i].getIcon() == tipo) {
			for (unsigned int j = 0; j < portos.size(); j++) {
				if (navios[i].getX() == portos[j].getX() && navios[i].getY() == portos[j].getY()) {
					setMoney(navios[i].getMercadoria() * precoM);
					setMoney(navios[i].getPeixe() * precoP);
					setMoney(precoN);
					navios.erase(navios.begin() + i);
					done = true;
				}
			}
			if (!done) {
				cout << "O navio escolhido nao esta num porto";
			}
		}
	}
}

void Jogador::compraSoldados(int id, int quantidade, int preco) {
	bool done = false;
	for (unsigned int i = 0; i < navios.size(); i++) {
		if (navios[i].getId() == id) {
			for (unsigned int j = 0; j < portos.size(); j++) {
				if (navios[i].getX() == portos[j].getX() && navios[i].getY() == portos[j].getY()) {
					if (navios[i].setSoldados(quantidade)) {
						setMoney(-(quantidade * preco));
					}
					done = true;
				}
			}
			if (!done) {
				cout << "O navio escolhido nao esta num porto";
			}
		}
	}
}

Jogador::~Jogador(){}
