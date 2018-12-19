#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Porto.h"
#include "Mar.h"
#include "Terra.h"
#include "Terreno.h"

using namespace std;

class Celula
{
public:
	Celula();

	Celula(char ch) {
		if (ch == '.')
			t = new Mar();
		else if (ch == '+')
			t = new Terra();
		else
			t = new Porto();
		/*for (int i = 0; i < mapa.size(); i++){
			grelha.push_back(vector<celula>());
			for (int j = 0; j < nCol; j++){
				grelha.push_back(Celula(mapa[i][j]));
			}
		}*/
	};

	~Celula();

private:
	Terreno * t;
};

