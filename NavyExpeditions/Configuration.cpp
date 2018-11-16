#include "stdafx.h"
#include "Configuration.h"
#include <fstream>

Configuration::Configuration(){
}

void Configuration::Run() {
	bool val = false;
	
	do {
		system("cls");
		DisplayMenu(); // Separar Logica de UserInterface

	} while (val != true);
}

Configuration::~Configuration(){}