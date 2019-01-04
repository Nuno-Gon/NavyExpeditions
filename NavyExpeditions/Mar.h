#include "Terreno.h"
#pragma once

using namespace std;

class Mar : public Terreno {
public:
	Mar();
	 bool getPeixe();
	 void setPeixe(bool x);
	 int getTurno();
	 void setTurno(int x);
	 void decTurno();

	 void produzirPeixe();

	~Mar();

	bool peixe;
	int turno;
};

