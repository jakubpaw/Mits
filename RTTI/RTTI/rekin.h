#pragma once
#include "ryba.h"
class Rekin :public Ryba
{
private:
	int dlugosc;
public:
	Rekin(int sWaga, std::string sGatunek, int sDlugosc);
	void jakiGatunek();
	void jakaWaga();
	void jakaDlugosc();
};