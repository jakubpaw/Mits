#pragma once
#include<cmath>
template<class T>
class Complex
{
private:
	T im;
	T re;
public:
	T getIm()
	{
		return im;
	}
	void setIm(T sIm)
	{
		this->im = sIm;
	}
	T getRe()
	{
		return re;
	}
	void setRe(T sRe)
	{
		this->re = sRe;
	}
	Complex() = default;
	Complex(T sIm, T sRe)
	{
		setIm(sIm);
		setRe(sRe);
	}
	T calculate_absolute_value();
	bool operator==(const Complex & comp);
	bool operator!=(const Complex& comp);
	bool operator>(Complex& comp);
	bool operator<(Complex& comp);
};
template<class T>
T Complex<T>:: calculate_absolute_value()
{
	return sqrt(pow(re,2) + pow(im,2));
}

template <class T>
bool Complex<T>::operator==(const Complex&comp)
{
	return (re == comp.re) && (im == comp.im);
}

template<class T>
bool Complex<T>::operator!=(const Complex&comp)
{
	return (im != comp.im) || (re != comp.re);
}

template<class T>
bool Complex<T>::operator>(Complex&comp)
{
	return calculate_absolute_value() > comp.calculate_absolute_value();
}
template<class T>
bool Complex<T>::operator<(Complex&comp)
{
	return calculate_absolute_value() < comp.calculate_absolute_value();
}