#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Posicao.h"

using namespace std;

class Navio : public Posicao {
private:
	static int numNavios;
	int id;
	int soldados;
	int peixe;
	int mercadoria;
	int agua;
	int quantidade_v;
	int quantidade_g;
	int quantidade_e;
	int quantidade_f;

public:
	Navio();
	Navio(int, int, int, int, char);
	
	int getId();
	int getSoldados();
	int getPeixe();
	int getMercadoria();
	int getQuantidade_v();
	int getQuantidade_g();
	int getQuantidade_e();
	int getQuantidade_f();


	void setId(int id);
	void setSoldades(int s);
	void setPeixe(int p);
	void setMercadorias(int m);
	void setQuantidade_v(int v);
	void setQuantidade_g(int g);
	void setQuantidade_e(int e);
	void setQuantidade_f(int f);

	~Navio();
};