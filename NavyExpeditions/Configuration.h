#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class Configuration{
public:
	Configuration();
	void run();
	void resolveCommands(bool *val, string comando);
	void displayMenuOne(string *comando);
	void getFileConfig(bool *val, string fich);
	~Configuration();
};