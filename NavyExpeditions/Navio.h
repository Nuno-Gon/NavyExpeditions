#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class Navio //: public Posicao
{
private:
	int id;

public:
	Navio();
	Navio(int id);
	int getId() {
		return this->id;
	}
	void setId(int id) {
		this->id = id;
	}	

};