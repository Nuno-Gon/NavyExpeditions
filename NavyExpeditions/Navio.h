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
	Navio(int, int, int, int, char);
	
	int getId();
	int getSoldados();
	int getMercadoria();
	int getPeixe();
	int getAgua();
	bool getDeriva();

	void setId(int id);
	bool setSoldados(int s);
	bool setMercadorias(int m);
	bool setPeixe(int p);
	void setAgua(int a);
	void setDeriva(bool d);

	~Navio();

private:
	static int numNavios;
	int id;
	int soldados;
	int mercadoria;
	int peixe;
	int agua;
	bool deriva;
};