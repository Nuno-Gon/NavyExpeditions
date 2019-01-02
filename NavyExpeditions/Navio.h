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
	bool getDeriva();

	void setId(int id);
	void setSoldados(int s);
	void setMercadorias(int m);
	void setAgua(int a);
	void setDeriva(bool d);

	~Navio();

private:
	static int numNavios;
	int id;
	int soldados;
	int mercadoria;
	int agua;
	bool deriva;
};