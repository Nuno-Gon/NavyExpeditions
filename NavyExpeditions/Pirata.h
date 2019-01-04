#pragma once
#include "Jogador.h"
class Pirata {
public:
	Pirata();

	void inserePirata(int, int, string);
	void setVeleiro(Veleiro v);
	void setFragata(Fragata f);
	void setPorto(Porto p);
	vector<Navio> getVectorNavios();
	vector<Porto> getVectorPortos();

	~Pirata();

private:
	vector<Navio> navios;
	vector<Porto> portos;
};

