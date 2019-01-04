#pragma once
class Terreno{
public:
	Terreno();

	//usar VIRTUAL functions class abstract
	virtual void produzirPeixe() = 0;
	~Terreno();
};

