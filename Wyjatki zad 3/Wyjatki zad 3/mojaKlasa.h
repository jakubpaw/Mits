#pragma once
#include<iostream>
using namespace std;
class MojaKlasa
{
public:
	MojaKlasa()
	{
		cout << "wywo�ano konstruktor" << endl;
	}
	~MojaKlasa()
	{
		cout << "wywo�ano destruktor" << endl;
	}
};