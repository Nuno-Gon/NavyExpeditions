#include "stdafx.h"
#include "Pirata.h"


Pirata::Pirata()
{
}

void Pirata::setVeleiro(Veleiro v) {
	navios.push_back(v);
}
void Pirata::setFragata(Fragata f) {
	navios.push_back(f);
}
vector<Navio> Pirata::getVectorNavios() {
	return navios;
}
void Pirata::setPorto(Porto p) {
	portos.push_back(p);
}
vector<Porto> Pirata::getVectorPortos() {
	return portos;
}

void Pirata::inserePirata(int x, int y, string tipo) {
	if (tipo == "v") {
		Veleiro v;
		v.setX(x);
		v.setY(y);
		setVeleiro(v);
		cout << "Criou um navio pirata do tipo veleiro" << v.getX() << endl;
	}
	else if (tipo == "f") {
		Fragata f;
		f.setX(x);
		f.setY(y);
		setFragata(f);
		cout << "Criou um navio pirata do tipo fragata" << endl;
	}
	else
		cout << "Tipo de navio pirata inexistente" << endl;
}

Pirata::~Pirata()
{
}
