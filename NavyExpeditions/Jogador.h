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
#include "Iate.h"
#include "Porto.h"
#include "Celula.h"

using namespace std;

class Jogador {
public:
	
	Jogador();
	
	void setVeleiro(Veleiro v);
	void setEscuna(Escuna e);
	void setFragata(Fragata f);
	void setGaleao(Galeao g);
	void setIate(Iate i);
	void setPorto(Porto p);
	void setMoney(int m);
	int getMoney();
	void moveNavios(int n, string x, vector <vector <Celula>>& grelha);
	void compraNav(string tipo, int preco);
	vector<Navio> getVectorNavios();
	vector<Porto> getVectorPortos();
	vector<Navio> getVectorNaviosDeriva();
	void verifcaEscuna();
	bool segueNavio(Navio, Navio);
	void compraMercadorias(int id, int quantidade, int preco);
	void vendeMercadorias(int id, int precoM, int precoP);
	void vendeNavio(string tipo, int, int, int);
	void compraSoldados(int id, int quantidade, int preco);
	void ativarMovimentoAuto(int);
	void movimentoStop(int);
	void moverFragataAut(vector<Navio>);
	
	~Jogador();

private:

	int money;
	vector<Navio> navios;
	vector<Porto> portos;
	vector<Navio> naviosDeriva;
};