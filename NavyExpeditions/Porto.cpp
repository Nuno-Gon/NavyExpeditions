#include "stdafx.h"
#include "Porto.h"

//Porto::Porto() {}

Porto::Porto(int x, int y) : x(x), y(y) {}

Porto::~Porto()
{
}

void Porto::setX(int x) {
	this->x = x;
}
int Porto::getX() {
	return x;
}

void Porto::setY(int y) {
	this->y = y;
}
int Porto::getY() {
	return y;
}
