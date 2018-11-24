#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Navio.h"

class Escuna : public Navio {
private:
	int quantidade;

public:
	Escuna();

	void setQuantidade(int q) {
		this->quantidade = q;
	}

	~Escuna();
};