#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Navio.h"

using namespace std;

class Porto {
public:
	vector<Navio> navios;

	Porto();

	~Porto();
}