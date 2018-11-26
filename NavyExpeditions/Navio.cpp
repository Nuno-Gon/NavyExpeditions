#include "stdafx.h"
#include "Navio.h"

int Navio::numNavios = 0;

Navio::Navio(int s, int p, int m, int a, char t) {
	this->numNavios++;
	this->id = numNavios;
	this->soldados = s;
	this->peixe = p;
	this->mercadoria = m;
	this->agua = a;
	if (t == 'v') {
		this->setIcon('v');
	}
	if (t == 'g') {
		this->setIcon('g');
	}
	if (t == 'e') {
		this->setIcon('e');
	}
	if (t == 'f') {
		this->setIcon('f');
	}
}

int Navio::getId() {
	return this->id;
}

int Navio::getSoldados() {
	return this->soldados;
}
int Navio::getPeixe() {
	return this->peixe;
}
int Navio::getMercadoria() {
	return this->mercadoria;
}
int Navio::getQuantidade_v() {
	return this->quantidade_v;
}
int Navio::getQuantidade_g() {
	return this->quantidade_g;
}
int Navio::getQuantidade_e() {
	return this->quantidade_e;
}
int Navio::getQuantidade_f() {
	return this->quantidade_f;
}

void Navio::setId(int id) {
	this->id = id;
}
void Navio::setSoldades(int s) {
	this->soldados = this->soldados + s;
}
void Navio::setPeixe(int p) {
	this->peixe = this->peixe + p;
}
void Navio::setMercadorias(int m) {
	this->mercadoria = this->mercadoria + m;
}
void Navio::setQuantidade_v(int v) {
	this->quantidade_v = this->quantidade_v + v;
}
void Navio::setQuantidade_g(int g) {
	this->quantidade_g = this->quantidade_g + g;
}
void Navio::setQuantidade_e(int e) {
	this->quantidade_e = this->quantidade_e + e;
}
void Navio::setQuantidade_f(int f) {
	this->quantidade_f = this->quantidade_f + f;
}

Navio::~Navio()
{
}
