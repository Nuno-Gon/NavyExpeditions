#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class Configuration{
public:
	Configuration();
	~Configuration();

	void run();
	void resolveCommands(bool *val, string comando);
	void displayMenuOne(string *comando);
	void getFileConfig(bool *val, string fich);

	int getLinhas();
	int getColunas();
	int getMoedas();
	float getProbPirata();
	int getPrecoNavio();
	int getPrecoSoldado();
	int getPrecoVendPeixe();
	int getPrecoVendMercad();
	int getSoldadosPorto();
	float getProbEvento();
	float getProbTempestade();
	float getProbSereias();
	float getProbCalmaria();
	float getProbMotim();

	void setLinhas(int l);
	void setColunas(int c);
	void setMoedas(int m);
	void setProbPirata(float p);
	void setPrecoNavio(int p);
	void setPrecoSoldado(int p);
	void setPrecoVendPeixe(int p);
	void setPrecoVendMercad(int p);
	void setSoldadosPorto(int p);
	void setProbEvento(float p);
	void setProbTempestade(float p);
	void setProbSereias(float p);
	void setProbCalmaria(float p);
	void setProbMotim(float p);

	vector<string> getMapa();
	vector<string> map;
private:
	int linhas;
	int colunas;
	int moedas;
	float probpirata;
	int preconavio;
	int precosoldado;
	int precovendpeixe;
	int precovendmercad;
	int soldadosporto;
	float probevento;
	float probtempestade;
	float probsereias;
	float probcalmaria;
	float probmotim;

	//vector<string> map;
};