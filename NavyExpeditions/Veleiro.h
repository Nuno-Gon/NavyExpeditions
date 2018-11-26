#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Navio.h"

class Veleiro : public Navio {

public:
	Veleiro();

	int getSoldado() {
		return this->getSoldados();
	}
	~Veleiro();
};