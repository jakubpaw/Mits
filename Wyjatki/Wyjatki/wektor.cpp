#include "wektor.h"
void Wektor::zmniejsz(double oile)
{
	dlugosc -= oile;
	if (dlugosc < 0)
		throw *this;
}