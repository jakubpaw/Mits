#pragma once
#include <string>
#include "zwierze.h"

class Ryba :public Zwierze
{
protected:
	std::string gatunek;
public:
	Ryba(int sWaga, std::string sGatunek);
	virtual void jakaWaga() override;
	virtual void jakiGatunek();
};