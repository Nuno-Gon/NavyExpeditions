#include "stdafx.h"
#include "Configuration.h"

Configuration::Configuration(){
}

void Configuration::run(){
	string comando;	
	bool val = false;
	
	do {
		system("cls");
		
		displayMenuOne(&comando);
		resolveCommands(&val, comando);

		cout << endl;
		system("pause");
	} while (val != true);
}
void Configuration::resolveCommands(bool *val, string comando) {
	string cmd;
	istringstream iss(comando);
	iss >> cmd;

	if (cmd == "config") {
		iss >> cmd; //nome do ficheiro, retira a próxima palavra
		getFileConfig(val, cmd);
	}
	else {
		cout << "Comando Incorreto!" << endl; //Acho que estas mensagens têm de estar num log de strings
		cin.get();
	}
}
void Configuration::displayMenuOne(string *comando) {
	cout << "--- Lista de Comandos Fase 1 --- \n" << endl;
	cout << endl;
	cout << "config <nomeFicheiro>" << endl;
	cout << endl;
	cout << "Comando: ";
	getline(cin, *comando);
}
void Configuration::getFileConfig(bool *val, string fich) {
	string line;
	fstream file;
	file.open(fich);
	cout << "File name:" << fich << endl;
	if (file.fail()) {
		cerr << "Erro ao abrir ficheiro!" << endl;
		cout << "Press enter to continue..." << endl;
		cin.get();
	}
	else {
		while (!file.eof()) {
			getline(file, line);
			cout << "Info do ficheiro: " << line << endl;
			cin.get();
			/*
			get linhas
			get	colunas
			get MAPA = matrix[l][c]
	
			for(int l=0 ; l<linhas ; l++){
				for(int c=0 ; c<colunas ; c++){
					matrix[l][c]=;
				}
			}

			depois if command
			*/
		}
	}
}

Configuration::~Configuration(){}