#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class Navio {
private:
	int id;
	int soldados;
	int peixe;
	int agua;
	int quantidade_v;
	int quantidade_g;
	int quantidade_e;
	int quantidade_f;

public:
	Navio();
	Navio(int, int, int, int, char) {
		
	}
	
	int getId();
	void setId(int id);

	~Navio();
};