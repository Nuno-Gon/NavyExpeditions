#include "stdafx.h"
#include "Configuration.h"

Configuration::Configuration(){
}

void Configuration::Run(){
	string comando;	
	bool val = false;
	
	do {
		system("cls");
		
		DisplayMOne(&comando);
		DisplayMenu(&val, comando);

		cout << endl;
		system("pause");
	} while (val != true);
}

void Configuration::DisplayMenu(bool *val, string comando) {
	string cmd;
	istringstream iss(comando);
	iss >> cmd;

	if (cmd == "config") {
		iss >> cmd; //nome do ficheiro

	}// Else Ifs com Os Restantes Comandos
	else if(cmd == "exec"){
		//...
	}
	else {
		cout << "Default" << endl;
		cin.get();
	}
}

void Configuration::DisplayMOne(string *comando) {
	cout << "--- Lista de Comandos Fase 1 --- \n" << endl;
	cout << endl;
	cout << "config <nomeFicheiro>" << endl;
	cout << endl;
	cout << "Comando: " << endl;
	getline(cin, *comando);
}

Configuration::~Configuration(){}