#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Navio.h"

class Fragata : public Navio {

public:
	Fragata();

	void setQuantidade(int q) {
		this->quantidade = q;
	}

	~Fragata();
};