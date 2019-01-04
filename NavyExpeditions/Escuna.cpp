#include "stdafx.h"
#include "Escuna.h"
#include "Celula.h"

Escuna::Escuna() : Navio(10, 0, 0, 100, 'e') {}

void Escuna::pescar() {
	this->setPeixe(this->getPeixe()+1);
}

Escuna::~Escuna()
{
}
