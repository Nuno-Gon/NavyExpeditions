#include "stdafx.h"
#include "Navio.h"

int Navio::numNavios = 0;

Navio::Navio(int s, int m, int p, int a, char t) {
	this->numNavios++;
	this->id = numNavios;
	this->soldados = s;
	this->mercadoria = m;
	this->peixe = p;
	this->agua = a;
	this->deriva = false;
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

int Navio::getPeixe() {
	return this->peixe;
}

bool Navio::getDeriva() {
	return this->deriva;
}

void Navio::setId(int id) {
	this->id = id;
}
void Navio::setSoldados(int s) {
	if (this->getIcon() == 'v') {
		if (this->soldados + s > 20) {
			cout << "Nao e possivel adicionar tantos soldados ao veleiro (max 20, atualmente " << this->soldados << ")";
		}
		else if (this->soldados + s <= 0) {
			this->soldados = 0;
			this->deriva = true;
		}
		else {
			this->soldados = this->soldados + s;
		}
	}
	else if (this->getIcon() == 'g') {
		if (this->soldados + s > 40) {
			cout << "Nao e possivel adicionar tantos soldados ao galeao (max 20, atualmente " << this->soldados << ")";
		}
		else if (this->soldados + s < 0) {
			this->soldados = 0;
			this->deriva = true;
		}
		else {
			this->soldados = this->soldados + s;
		}
	}
	else if (this->getIcon() == 'e') {
		if (this->soldados + s > 10) {
			this->soldados = 0;
			this->deriva = true;
		}
		else if (this->soldados + s < 0) {
			cout << "Nao e possivel retirar soldados que nao existem";
		}
		else {
			this->soldados = this->soldados + s;
		}
	}
	else if (this->getIcon() == 'f') {
		if (this->soldados + s > 50) {
			cout << "Nao e possivel adicionar tantos soldados a fragata (max 50, atualmente " << this->soldados << ")";
		}
		else if (this->soldados + s <= 0) {
			this->soldados = 0;
			this->deriva = true;
		}
		else {
			this->soldados = this->soldados + s;
		}
	}
	else if (this->getIcon() == 'i') {
		if (this->soldados + s > 100) {
			cout << "Nao e possivel adicionar tantos soldados ao iate (max 100, atualmente " << this->soldados << ")";
		}
		else if (this->soldados + s < 0) {
			this->soldados = 0;
			this->deriva = true;
		}
		else {
			this->soldados = this->soldados + s;
		}
	}
}

bool Navio::setMercadorias(int m) {
	if (this->getIcon() == 'v') {
		if (this->mercadoria + this->peixe + m > 40) {
			int total = this->mercadoria + this->peixe;
			cout << "Nao e possivel adicionar tanta mercadoria ao veleiro (max 40, atualmente " << total << ")";
			return false;
		}
		else if (this->mercadoria + m < 0) {
			cout << "Nao e possivel retirar mercadoria que nao existe";
			return false;
		}
		else {
			this->mercadoria = this->mercadoria + m;
			return true;
		}
	}
	else if (this->getIcon() == 'g') {
		if (this->mercadoria + this->peixe + m > 70) {
			int total = this->mercadoria + this->peixe;
			cout << "Nao e possivel adicionar tanta mercadoria ao galeao (max 70, atualmente " << total << ")";
			return false;
		}
		else if (this->mercadoria + m < 0) {
			cout << "Nao e possivel retirar mercadoria que nao existe";
			return false;
		}
		else {
			this->mercadoria = this->mercadoria + m;
			return true;
		}
	}
	else if (this->getIcon() == 'e') {
		if (this->mercadoria + this->peixe + m > 20) {
			int total = this->mercadoria + this->peixe;
			cout << "Nao e possivel adicionar tanta mercadoria a escuna (max 20, atualmente " << total << ")";
			return false;
		}
		else if (this->mercadoria + m < 0) {
			cout << "Nao e possivel retirar mercadoria que nao existe";
			return false;
		}
		else {
			this->mercadoria = this->mercadoria + m;
			return true;
		}
	}
	else if (this->getIcon() == 'f') {
		cout << "Nao e possivel adicionar mercadoria a uma fragata!";
		return false;
	}
	else if (this->getIcon() == 'i') {
		if (this->mercadoria + this->peixe + m > 100) {
			int total = this->mercadoria + this->peixe;
			cout << "Nao e possivel adicionar tanta mercadoria ao iate (max 500, atualmente " << total << ")";
			return false;
		}
		else if (this->mercadoria + m < 0) {
			cout << "Nao e possivel retirar mercadoria que nao existe";
			return false;
		}
		else {
			this->mercadoria = this->mercadoria + m;
			return true;
		}
	}
	return false;
}

void Navio::setPeixe(int p) {
	if (this->getIcon() == 'v') {
		if (this->mercadoria + this->peixe + p > 40) {
			int total = this->mercadoria + this->peixe;
			cout << "Nao e possivel adicionar mais peixe ao veleiro (max 40, atualmente " << total << ")";
		}
		else if (this->peixe + p < 0) {
			cout << "Nao e possivel retirar peixe que nao existe";
		}
		else {
			this->peixe = this->peixe + p;
		}
	}
	else if (this->getIcon() == 'g') {
		if (this->mercadoria + this->peixe + p > 70) {
			int total = this->mercadoria + this->peixe;
			cout << "Nao e possivel adicionar mais peixe ao veleiro (max 40, atualmente " << total << ")";
		}
		else if (this->peixe + p < 0) {
			cout << "Nao e possivel retirar peixe que nao existe";
		}
		else {
			this->peixe = this->peixe + p;
		}
	}
	else if (this->getIcon() == 'e') {
		if (this->mercadoria + this->peixe + p > 20) {
			int total = this->mercadoria + this->peixe;
			cout << "Nao e possivel adicionar mais peixe ao veleiro (max 40, atualmente " << total << ")";
		}
		else if (this->peixe + p < 0) {
			cout << "Nao e possivel retirar peixe que nao existe";
		}
		else {
			this->peixe = this->peixe + p;
		}
	}
	else if (this->getIcon() == 'f') {
		cout << "Nao e possivel adicionar peixe a uma fragata!";
	}
	else if (this->getIcon() == 'i') {
		if (this->mercadoria + this->peixe + p > 100) {
			int total = this->mercadoria + this->peixe;
			cout << "Nao e possivel adicionar mais peixe ao veleiro (max 40, atualmente " << total << ")";
		}
		else if (this->peixe + p < 0) {
			cout << "Nao e possivel retirar peixe que nao existe";
		}
		else {
			this->peixe = this->peixe + p;
		}
	}
}

void Navio::setAgua(int a) {
	if (this->getIcon() == 'v') {
		if (this->agua + a > 200) {
			this->agua = 200;
		}
		else if (this->agua + a <= 0) {
			this->agua = 0;
			this->soldados = this->soldados - 1;
		}
		else {
			this->agua = this->agua + a;
		}
	}
	else if (this->getIcon() == 'g') {
		if (this->agua + a > 400) {
			this->agua = 200;
		}
		else if (this->agua + a <= 0) {
			this->agua = 0;
			this->soldados = this->soldados - 1;
		}
		else {
			this->agua = this->agua + a;
		}
	}
	else if (this->getIcon() == 'e') {
		if (this->agua + a > 100) {
			this->agua = 100;
		}
		else if (this->agua + a <= 0) {
			this->agua = 0;
			this->soldados = this->soldados - 1;
		}
		else {
			this->agua = this->agua + a;
		}
	}
	else if (this->getIcon() == 'f') {
		if (this->agua + a > 500) {
			this->agua = 500;
		}
		else if (this->agua + a <= 0) {
			this->agua = 0;
			this->soldados = this->soldados - 1;
		}
		else {
			this->agua = this->agua + a;
		}
	}
	else if (this->getIcon() == 'i') {
		if (this->agua + a > 1000) {
			this->agua = 1000;
		}
		else if (this->agua + a <= 0) {
			this->agua = 0;
			this->soldados = this->soldados - 1;
		}
		else {
			this->agua = this->agua + a;
		}
	}
}

void Navio::setDeriva(bool d) {
	this->deriva = d;
}

Navio::~Navio()
{
}
