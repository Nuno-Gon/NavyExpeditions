#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class Porto{
public:

	//Porto();
	Porto(int x, int y);
	
	void setX(int x);
	void setY(int y);

	int getX();
	int getY();

	~Porto();
private:
	int x;
	int y;
};