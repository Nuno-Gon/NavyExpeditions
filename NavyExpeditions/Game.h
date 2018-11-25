#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Configuration.h" 

using namespace std;

class Game{
public:
	Game(Configuration config);
	void displayMenuTwo();
	void resolveCommand(string comando);
	void getFileCommands(string fich);

	~Game();

private:
	Configuration config;
};

