#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Evento{
public:
	Evento();
	Evento(int pCalmaria, int pMotim, int pSereias, int pTempestade);
	virtual void msg();
	~Evento();
private:
	Evento * e;
};

