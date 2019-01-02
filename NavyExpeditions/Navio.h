#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Posicao.h"

using namespace std;

class Navio : public Posicao {
public:
	Navio(int, int, int, char);
	
	int getId();
	int getSoldados();
	int getMercadoria();
	int getAgua();

	void setId(int id);
	void setSoldados(int s);
	void setMercadorias(int m);
	void setAgua(int a);

	~Navio();

private:
	static int numNavios;
	int id;
	int soldados;
	int mercadoria;
	int agua;
	int quantidade_v;
	int quantidade_g;
	int quantidade_e;
	int quantidade_f;
};