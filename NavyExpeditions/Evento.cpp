#include "stdafx.h"
#include "Evento.h"
#include <ctime>
#include "Calmaria.h"
#include "Motim.h"
#include "Sereias.h"
#include "Tempestade.h"

Evento::Evento() {};

Evento::Evento(int pCalmaria, int pMotim, int pSereias, int pTempestade){
	srand((unsigned int)time(NULL));
	int r = (rand() % 100);
	if(r <= pCalmaria) {
		e = new Calmaria();
	}
	else if (r > pCalmaria && r <= pMotim + pCalmaria) {
		e = new Motim();
	}
	else if (r > pMotim && r <= pSereias + pMotim + pCalmaria) {
		e = new Sereias();
	}
	else if (r > pSereias && r <= pTempestade + pSereias + pMotim + pCalmaria) {
		e = new Tempestade();
	}
}

void Evento::msg() {
	cout << "Foi criado um evento!" << endl;
};

Evento::~Evento()
{
}
