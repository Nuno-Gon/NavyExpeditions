#pragma once
class Posicao
{
public:
	Posicao();
	Posicao(int col, int lin);
	~Posicao();

	void setX(int col);
	void setY(int lin);
	void setIcon(char tipo);

	int getX();
	int getY();
	char getIcon();

private:
	int x;
	int y;
	char icon;
};