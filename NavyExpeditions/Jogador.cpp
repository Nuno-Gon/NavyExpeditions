#include "stdafx.h"
#include "Jogador.h"
#include "Veleiro.h"
#include "Escuna.h"
#include "Fragata.h"
#include "Galeao.h"

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

Jogador::~Jogador(){}
