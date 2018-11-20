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
	void Run();
	void DisplayMenu(bool *val, string *cmd);
	void DisplayMOne(string *cmd);
	void DisplayMTwo();
	~Configuration();
};