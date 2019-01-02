#include "stdafx.h"
#include "Celula.h"


Celula::Celula()
{
}

Celula::Celula(char ch){
	this->img = ch;

	if (ch == '.')
		t = new Mar();
	else if (ch == '+')
		t = new Terra();
	else
		t = new Porto();
};

char Celula::getImg() {
	return this->img;
}

Celula::~Celula()
{
}
