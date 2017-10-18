#include <iostream>
using namespace std;

Complex & operator+ (const Complex &z1, const Complex &z2)
{
	return Complex(z1.re + z2.re, z1.im + z2.im);
}

class Complex
{
public:
	double im, re;
	Complex(double, double);
	Complex&Complex::operator +=(const Complex & C)
	{
		im += C.im;
		re += C.re;
		return*this;
	}
	Complex&Complex::operator +(const Complex & C)
	{
		return Complex(re + C.re, im + C.im);
	}
	bool operator !=(const Complex & C)
	{
		return (re != C.re&&im != C.im);
	}
	bool operator ==(const Complex & C)
	{
		return(!(*this != C));
	}
	Complex&Complex::operator ++( int)
	{
		re++;
		im++;
		return (*this);
	}
	Complex Complex::operator ++()
	{
		re++;
		im++;
		return (*this);
	}
};
Complex::Complex(double i, double r)
{
	im = i;
	re = r;
}
int main()
{

}