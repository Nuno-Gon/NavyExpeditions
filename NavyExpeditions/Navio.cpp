#include "stdafx.h"
#include "Navio.h"

Navio::Navio() {};

Navio::Navio(int i, int s, int m, int p, int a, char t) {
	this->id = i;
	this->soldados = s;
	this->mercadorias = m;
	this->peixe = p;
	this->agua = a;
	if (t == 'v') {
		this->quantidade_v++;
	}
	if (t == 'g') {
		this->quantidade_g++;
	}
	if (t == 'e') {
		this->quantidade_e++;
	}
	if (t == 'f') {
		this->quantidade_f++;
	}
}

int Navio::getId() {
	return this->id;
}
void Navio::setId(int id) {
	this->id = id;
}

Navio::~Navio()
{
}
