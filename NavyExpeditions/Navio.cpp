#include "stdafx.h"
#include "Navio.h"

int Navio::numNavios = 0;

Navio::Navio(int s, int m, int a, char t) {
	this->numNavios++;
	this->id = numNavios;
	this->soldados = s;
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
	if (t == 'i') {
		this->setIcon('i');
	}
}

int Navio::getId() {
	return this->id;
}

int Navio::getSoldados() {
	return this->soldados;
}

int Navio::getAgua() {
	return this->agua;
}

int Navio::getMercadoria() {
	return this->mercadoria;
}

void Navio::setId(int id) {
	this->id = id;
}
void Navio::setSoldados(int s) {
	if (this->getIcon == "v") {
		if (this->soldados + s > 20) {
			cout << "Nao e possivel adicionar tantos soldados ao veleiro (max 20, atualmente " << this->soldados << ")";
		}
		else if (this->soldados + s < 0) {
			cout << "Nao e possivel retirar soldados que nao existem";
		}
		else {
			this->soldados = this->soldados + s;
		}
	}
	else if (this->getIcon == "g") {
		if (this->soldados + s > 40) {
			cout << "Nao e possivel adicionar tantos soldados ao galeao (max 20, atualmente " << this->soldados << ")";
		}
		else if (this->soldados + s < 0) {
			cout << "Nao e possivel retirar soldados que nao existem";
		}
		else {
			this->soldados = this->soldados + s;
		}
	}
	else if (this->getIcon == "e") {
		if (this->soldados + s > 10) {
			cout << "Nao e possivel adicionar tantos soldados a escuna (max 10, atualmente " << this->soldados << ")";
		}
		else if (this->soldados + s < 0) {
			cout << "Nao e possivel retirar soldados que nao existem";
		}
		else {
			this->soldados = this->soldados + s;
		}
	}
	else if (this->getIcon == "f") {
		if (this->soldados + s > 50) {
			cout << "Nao e possivel adicionar tantos soldados a fragata (max 50, atualmente " << this->soldados << ")";
		}
		else if (this->soldados + s < 0) {
			cout << "Nao e possivel retirar soldados que nao existem";
		}
		else {
			this->soldados = this->soldados + s;
		}
	}
	else if (this->getIcon == "i") {
		if (this->soldados + s > 100) {
			cout << "Nao e possivel adicionar tantos soldados ao iate (max 100, atualmente " << this->soldados << ")";
		}
		else if (this->soldados + s < 0) {
			cout << "Nao e possivel retirar soldados que nao existem";
		}
		else {
			this->soldados = this->soldados + s;
		}
	}
}

void Navio::setMercadorias(int m) {
	if (this->getIcon == "v") {
		if (this->mercadoria + m > 40) {
			cout << "Nao e possivel adicionar tanta mercadoria ao veleiro (max 40, atualmente " << this->mercadoria << ")";
		}
		else if (this->mercadoria + m < 0) {
			cout << "Nao e possivel retirar mercadoria que nao existe";
		}
		else {
			this->mercadoria = this->mercadoria + m;
		}
	}
	else if (this->getIcon == "g") {
		if (this->mercadoria + m > 70) {
			cout << "Nao e possivel adicionar tanta mercadoria ao galeao (max 70, atualmente " << this->mercadoria << ")";
		}
		else if (this->mercadoria + m < 0) {
			cout << "Nao e possivel retirar mercadoria que nao existe";
		}
		else {
			this->mercadoria = this->mercadoria + m;
		}
	}
	else if (this->getIcon == "e") {
		if (this->mercadoria + m > 20) {
			cout << "Nao e possivel adicionar tanta mercadoria a escuna (max 20, atualmente " << this->mercadoria << ")";
		}
		else if (this->mercadoria + m < 0) {
			cout << "Nao e possivel retirar mercadoria que nao existe";
		}
		else {
			this->mercadoria = this->mercadoria + m;
		}
	}
	else if (this->getIcon == "f") {
		cout << "Nao e possivel adicionar mercadoria a uma fragata!";
	}
	else if (this->getIcon == "i") {
		if (this->mercadoria + m > 500) {
			cout << "Nao e possivel adicionar tanta mercadoria ao iate (max 500, atualmente " << this->mercadoria << ")";
		}
		else if (this->mercadoria + m < 0) {
			cout << "Nao e possivel retirar mercadoria que nao existe";
		}
		else {
			this->mercadoria = this->mercadoria + m;
		}
	}
}
void Navio::setAgua(int a) {
	this->agua = this->agua + a;
}

Navio::~Navio()
{
}
