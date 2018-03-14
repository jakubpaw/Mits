#pragma once
class Wektor
{
public:
	double dlugosc;
	Wektor(double dl) :dlugosc(dl)
	{
	}
	virtual ~Wektor(){}
	void zmniejsz(double oile);
};