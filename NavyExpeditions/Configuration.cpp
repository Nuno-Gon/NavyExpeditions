#include "stdafx.h"
#include "Configuration.h"

Configuration::Configuration(){
}

void Configuration::Run(){
	string cmd;	
	bool val = false;
	
	do {
		system("cls");
		
		DisplayMOne(&cmd);
		DisplayMenu(&val, &cmd);

		cout << endl;
		system("pause");
	} while (val != true);
}

void Configuration::DisplayMenu(bool *val, string *cmd) {

}

void Configuration::DisplayMOne(string *cmd) {
	cout << "--- Lista de Comandos Fase 1 --- \n" << endl;
	cout << endl;
	cout << "config <nomeFicheiro>" << endl;
	cout << endl;
	cout << "Comando: " << endl;
	getline(cin, *cmd);
}

Configuration::~Configuration(){}