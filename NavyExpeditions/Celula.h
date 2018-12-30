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

	Celula(char ch);

	/*friend ostream& operator<<(ostream& os, const vector<vector<Celula>>& g) {
		for (unsigned int i = 0; i < g.size(); i++) {
			for (unsigned int j = 0; j < g[i].size(); j++) {
				cout << g[i][j].img;
			}
			cout << endl;
		}
		return os;
	}*/

	friend ostream& operator<<(ostream& os, const Celula& g) {
		cout << g.img;
		return os;
	}

	~Celula();

private:
	Terreno * t;
	char img;
};

