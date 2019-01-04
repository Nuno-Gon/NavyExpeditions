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

	 void produzir();
	 void change(bool x);
	 bool ret() {
		 return peixe;
	 }

	~Mar();
	
	bool peixe;
	int turno;
};

