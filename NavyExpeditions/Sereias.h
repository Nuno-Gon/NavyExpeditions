#pragma once
#include "Evento.h"
#include "Navio.h"

class Sereias : public Evento {
public:
	Sereias();
	Sereias(vector<Navio>);
	void eventoAcao();
	void eventoAcao(vector<Navio>);
	void msg();
	~Sereias();
};

