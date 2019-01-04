#include "stdafx.h"
#include "Pirata.h"


Pirata::Pirata()
{
}

void Pirata::setVeleiro(Veleiro v) {
	navios.push_back(v);
}
void Pirata::setFragata(Fragata f) {
	navios.push_back(f);
}
vector<Navio> Pirata::getVectorNavios() {
	return navios;
}
void Pirata::setPorto(Porto p) {
	portos.push_back(p);
}
vector<Porto> Pirata::getVectorPortos() {
	return portos;
}



Pirata::~Pirata()
{
}
