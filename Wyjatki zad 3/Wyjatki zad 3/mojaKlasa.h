#pragma once
#include<iostream>
using namespace std;
class MojaKlasa
{
public:
	MojaKlasa()
	{
		cout << "wywo³ano konstruktor" << endl;
	}
	~MojaKlasa()
	{
		cout << "wywo³ano destruktor" << endl;
	}
};