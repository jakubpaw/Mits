#pragma once
#include <iostream>
using namespace std;
class Zwierze
{
protected:
	int waga;
public:
	Zwierze(int sWaga);
	virtual void jakaWaga();
};