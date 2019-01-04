#pragma once
class Terreno{
public:
	Terreno();

	//usar VIRTUAL functions class abstract
	virtual void produzir() = 0;
	virtual void change(bool x)=0;
	~Terreno();
};

