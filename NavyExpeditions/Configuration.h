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
	void DisplayMenu(bool *val, string comando);
	void DisplayMOne(string *comando);
	void DisplayMTwo();
	void GetFileInfo(string fich);
	~Configuration();
};