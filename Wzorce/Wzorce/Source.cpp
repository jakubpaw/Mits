#include "complex.h"
#include "set.h"
#include <iostream>
#include <conio.h>
#include "statistic.h"
using namespace std;
int main()
{
	//zadanie 1
	Complex<int> compI(2, -4);
	Complex<int> compI2(1, 2);
	Complex<double> compD(3, -6);
	Complex<float> compF(2.2, -5.5);

	cout << compI.calculate_absolute_value() << endl;
	cout << compI2.calculate_absolute_value() << endl;
	cout << compD.calculate_absolute_value() << endl;
	cout << compF.calculate_absolute_value() << endl;

	if (compI > compI2) cout << "yes" << endl;
	else cout << "no" << endl;

	//zadanie 2

	Complex<double> compD2(3, -6);
	Complex<double> compD3(3, -6);
	Complex<double> compD4(3, -5);
	Complex<double> compD5(3, -4);
	Complex<double> compD6(3, -7);
	Set<Complex<double>, 3> set1;
	set1.add(compD2);
	set1.add(compD3);
	set1.add(compD4);
	set1.add(compD5);
	set1.add(compD6);
	auto vector=set1.to_vector();


	//zadanie 3
	Statistics<Complex<double>> statistics_complex(vector);

	const auto max_complex = statistics_complex.max();

	const auto average_complex = statistics_complex.calculate_average();

	Statistics<double> statistics_double({ 1.2, 5.2, 125.2, 1.01 });

	const auto max_double = statistics_double.max();

	const auto average_double = statistics_double.calculate_average();

	_getch();
}