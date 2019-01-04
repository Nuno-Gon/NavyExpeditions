#include "stdafx.h"
#include "Sereias.h"
#include <ctime>
#include <vector>


Sereias::Sereias(){
	msg();
	eventoAcao();
}

Sereias::Sereias(vector<Navio> navios) {
	msg();
	eventoAcao(navios);
}

void Sereias::msg() {
	cout << "Ocorreu um Evento: Sereias!" << endl;
};

void Sereias::eventoAcao(vector<Navio> navios) {
	srand(time(NULL));
	int r = rand() % navios.size();
	navios[r].setSoldados(-navios[r].getSoldados() * 0.1);
}

Sereias::~Sereias()
{
}
