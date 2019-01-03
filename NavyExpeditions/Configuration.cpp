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
		cout << "Comando Incorreto!" << endl;
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
	if (file.fail()) {
		cerr << "Erro ao abrir ficheiro!" << endl;
		cout << "Press enter to continue..." << endl;
		cin.get();
	}
	else {
		while (!file.eof()) {
			getline(file, line);
			istringstream iss(line);
			string c;
			iss >> c;
			if (c == "linhas") {
				iss >> c;
				setLinhas(stoi(c));
			}
			else if (c == "colunas") {
				iss >> c;
				setColunas(stoi(c));
				}
			else if(c  == "moedas"){
				iss >> c;
				setMoedas(stoi(c));
			}
			else if (c == "probpirata") {
				iss >> c;
				setProbPirata(stof(c));
			}
			else if (c == "preconavio") {
				iss >> c;
				setPrecoNavio(stoi(c));
			}
			else if (c == "precosoldado") {
				iss >> c;
				setPrecoSoldado(stoi(c));
			}
			else if (c == "precovendpeixe") {
				iss >> c;
				setPrecoVendPeixe(stoi(c));
			}
			else if (c == "precocompmercad") {
				iss >> c;
				setPrecoCompMercad(stoi(c));
			}
			else if (c == "precovendmercad") {
				iss >> c;
				setPrecoVendMercad(stoi(c));
			}
			else if (c == "soldadosporto") {
				iss >> c;
				setSoldadosPorto(stoi(c));
			}
			else if (c == "probevento") {
				iss >> c;
				setProbEvento(stof(c));
			}
			else if (c == "probtempestade") {
				iss >> c;
				setProbTempestade(stof(c));
			}
			else if (c == "probsereias") {
				iss >> c;
				setProbSereias(stof(c));
			}
			else if (c == "probcalmaria") {
				iss >> c;
				setProbCalmaria(stof(c));
			}
			else if (c == "probmotim") {
				iss >> c;
				setProbMotim(stof(c));
			}
			else {
				map.push_back(c);
			}
		}
		
		//imprime mapa
		/*for (auto i = map.begin(); i != map.end(); ++i){
			cout << *i << endl;
		}*/

		//imprime o "A" maiusculo na posicao (2,10) do mapa
		/*auto i = map.begin();
		cout << i[2][10] << endl; 
		*/

		*val = true;
	}
}
//Getters
int Configuration::getLinhas() { return this->linhas; }
int Configuration::getColunas() { return this->colunas; }
int Configuration::getMoedas() { return this->moedas; }
float Configuration::getProbPirata() { return this->probpirata; }
int Configuration::getPrecoNavio() { return this->preconavio; }
int Configuration::getPrecoSoldado() { return this->precosoldado; }
int Configuration::getPrecoVendPeixe() { return this->precovendpeixe; }
int Configuration::getPrecoCompMercad() { return this->precocompmercad; }
int Configuration::getPrecoVendMercad() { return this->precovendmercad; }
int Configuration::getSoldadosPorto() { return this->soldadosporto; }
float Configuration::getProbEvento() { return this->probevento; }
float Configuration::getProbTempestade() { return this->probtempestade; }
float Configuration::getProbSereias() { return this->probsereias; }
float Configuration::getProbCalmaria() { return this->probcalmaria; }
float Configuration::getProbMotim() { return this->probmotim; }
//Setters
void Configuration::setLinhas(int l) { this->linhas = l; }
void Configuration::setColunas(int c) { this->colunas = c; }
void Configuration::setMoedas(int m) { this->moedas = m; }
void Configuration::setProbPirata(float p) { this->probpirata = p; }
void Configuration::setPrecoNavio(int p) { this->preconavio = p; }
void Configuration::setPrecoSoldado(int p) { this->precosoldado = p; }
void Configuration::setPrecoVendPeixe(int p) { this->precovendpeixe = p; }
void Configuration::setPrecoCompMercad(int p) { this->precocompmercad = p; }
void Configuration::setPrecoVendMercad(int p) { this->precovendmercad = p; }
void Configuration::setSoldadosPorto(int p) { this->soldadosporto = p; }
void Configuration::setProbEvento(float p) { this->probevento = p; }
void Configuration::setProbTempestade(float p) { this->probtempestade = p; }
void Configuration::setProbSereias(float p) { this->probsereias = p; }
void Configuration::setProbCalmaria(float p) { this->probcalmaria = p; }
void Configuration::setProbMotim(float p) { this->probmotim = p; }

vector<string> Configuration::getMapa() {
	return map;
}

Configuration::~Configuration(){}