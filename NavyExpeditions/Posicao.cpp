#include "stdafx.h"
#include "Posicao.h"


Posicao::Posicao(){}
Posicao::Posicao(int col, int lin) : x(col), y(lin) {}
Posicao::~Posicao(){}

void Posicao::setX(int col) {
	x = col;
}
int Posicao::getX() {
	return x;
}

void Posicao::setY(int lin) {
	y = lin;
}
int Posicao::getY() {
	return y;
}

void Posicao::setIcon(char tipo) {
	icon = tipo;
}
char Posicao::getIcon() {
	return icon;
}
