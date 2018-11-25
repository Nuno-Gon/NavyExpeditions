#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Navio.h"

using namespace std;

class Jogador {
private:
	int moedas;

public:
	vector<Navio> navios;
	Jogador();

	~Jogador();
};