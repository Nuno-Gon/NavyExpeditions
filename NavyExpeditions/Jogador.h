#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Navio.h"
#include "Veleiro.h"
#include "Escuna.h"
#include "Fragata.h"
#include "Galeao.h"

using namespace std;

class Jogador {
public:
	
	Jogador();
	
	void setVeleiro(Veleiro v);
	void setEscuna(Escuna e);
	void setFragata(Fragata f);
	void setGaleao(Galeao g);

	vector<Navio> getVectorNavios();
	
	~Jogador();

private:
	int money;
	vector<Navio> navios;
	//vector<Porto> portos;
};