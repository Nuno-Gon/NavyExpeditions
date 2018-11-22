#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Navio.h"

class Veleiro : public Navio {
private:
	int soldados;
	int mercadorias;
	int peixe;
	//movimento
	int agua;
};