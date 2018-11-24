#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Navio.h"

class Veleiro : public Navio {
private:
	int quantidade;

public:
	Veleiro();

	void setQuantidade(int q) {
		this->quantidade = q;
	}

	~Veleiro();
};