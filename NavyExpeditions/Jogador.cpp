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
vector<Navio> Jogador::getVectorNavios() {
	return navios;
}
void Jogador::moveNavios() {
	int a, b, x = 0, z = 0;
	auto i = navios;

	for (unsigned int k = 0; k < i.size(); k++) {
		srand((unsigned int)time(NULL));
		int r = rand() % 100;
		cout << "r" << r << endl;
		if (r >= 0 && r < 25) {
			x = 1;
			z = 0;
		}
		else if (25 <= r && r < 50) {
			x = -1;
			z = 0;
		}
		else if (50 <= r && r < 75) {
			x = 0;
			z = 1;
		}
		else if (75 <= r && r < 100) {
			x = 0;
			z = -1;
		}

		cout << "xz" << x << z << endl;
		cin.get();
		a = i[k].getX() + x;
		b = i[k].getY() + z;
		/*if (config.map[a][b] == '+')
			break;
		else {*/
			navios[k].setX(a);
			navios[k].setY(b);
			cout << "2" << a << b << endl;
			cin.get();
		//}
	}
}

void Jogador::compraNav(string cmd) {
	if (cmd == "v") {
		Veleiro v;
		v.setX(2); //criar navio no porto principal
		v.setY(10); //ir buscar o primeiro porto do vetor de portos
		setVeleiro(v);
		cout << "Comprou um navio do tipo Veleiro" << endl;
	}
	else if (cmd == "e") {
		Escuna e;
		e.setX(2);
		e.setY(10);
		setEscuna(e);
		cout << "Comprou um navio do tipo Escuna" << endl;
	}
	else if (cmd == "g") {
		Galeao g;
		g.setX(2);
		g.setY(10);
		setGaleao(g);
		cout << "Comprou um navio do tipo Galeao" << endl;
	}
	else if (cmd == "f") {
		Fragata f;
		f.setX(2);
		f.setY(10);
		setFragata(f);
		cout << "Comprou um navio do tipo Fragata" << endl;
	}
	else {
		cout << "Tipo de navio inexistente!" << endl;
		return;
	}
}

Jogador::~Jogador(){}
