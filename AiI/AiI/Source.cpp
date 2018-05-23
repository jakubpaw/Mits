#include <iostream>
#include <random>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>
#include <cmath>
#include <set>
#include <conio.h>

using namespace std;
struct Rect
{
	double x, y;
};
struct Circle
{
	Rect rect;
	double r;
	friend ostream&	operator <<(ostream&os, const Circle &circle)
	{
		os << "{{" << circle.rect.x << "," << circle.rect.y << "}," << circle.r << "}";
		return os;
	}
};
struct Generator {
	int i;
	int step;

	int operator()() {
		int ret = i;
		i += step;
		return ret;
	}
};


int main()
{

	cout << "ZAD1" << endl;
	default_random_engine engine{};
	uniform_real_distribution<double> r_gen{ 1,10 };
	uniform_real_distribution<double> pos_gen{ 0,100 };
	vector<Circle> circles(8);

	generate(circles.begin(), circles.end(), [&]() -> Circle {
		return { { pos_gen(engine),pos_gen(engine) },r_gen(engine) };
	});
	ostream_iterator<Circle> out_it(cout, ",");
	copy(circles.begin(), circles.end(), out_it);

	cout << endl;

	auto minAndMax = std::minmax_element(circles.begin(), circles.end(), [](const Circle& a, const Circle& b) {
		return a.r < b.r;
	});

	cout << "Element minimalny: " << *minAndMax.first << "    Element maksymalny: " << *minAndMax.second << endl;

	sort(circles.begin(), circles.end(), [](const Circle& a, const Circle& b) {
		return std::hypot(a.rect.x, a.rect.y) < std::hypot(b.rect.x, b.rect.y);
	});

	cout << "Posortowane wzgledem odleglosci od srodka ukladu wspiolrzdnych: " << endl;
	copy(circles.begin(), circles.end(), out_it);
	cout << endl;

	list<double> pp{};
	transform(circles.begin(), circles.end(), back_inserter(pp), [](const Circle& c) {
		return c.r * c.r * 3.1415;
	});

	cout << "Pola kol: " << endl;
	copy(pp.begin(), pp.end(), ostream_iterator<double>{std::cout," "});
	//cout << "Suma pol: " << accumulate(pp.begin(), pp.end(), 0.0, plus<double>{});
	cout << endl;


	cout << "ZAD2" << endl;




	cout << "ZAD3" << endl;
	Generator gEven{ 0,2 };
	Generator g10{ 0,10 };
	Generator g1000{ 1000,1000 };

	generate_n(ostream_iterator<int>{cout, " "}, 10, gEven);
	generate_n(ostream_iterator<int>{cout, " "}, 10, g10);
	generate_n(ostream_iterator<int>{cout, " "}, 10, g1000);
	_getch();
}