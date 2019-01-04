#include "stdafx.h"
#include "Mar.h"
#include "Terreno.h"
#include <iostream>

Mar::Mar(){
	this->peixe = true;
	this->turno = 3;
}

bool Mar::getPeixe() {
	return this->peixe;
}
void Mar::setPeixe(bool x) {
	this->peixe = x;
}

int Mar::getTurno() {
	return this->turno;
}
void Mar::setTurno(int x) {
	this->turno = x;
}
void Mar::decTurno() {
	this->turno--;
}

void Mar::produzir() {
	if (peixe == false) {
		this->turno--;
		if (turno == 0) {
			this->peixe = true;
			this->turno = 3;
		}
	}
}

void Mar::change(bool x) {
	this->peixe = x;
}

Mar::~Mar(){}
