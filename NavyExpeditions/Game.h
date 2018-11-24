#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class Game{
public:
	Game();

	void displayMenuTwo(/*string *comando*/);
	void getCommand(string comando);
	void getFileCommands(string fich);

	~Game();
};

