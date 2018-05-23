#include <vector>
#include <iostream>
#include <conio.h>
using namespace std;

void print_vec(const vector<double>& v)
{
	for (auto x : v)
		cout << x << endl;
}
int main()
{
	vector<double> vec1{ 1.2, 2.3, 34.4, 12.3, 43.2, 2.3, 1.4, 5.6 };

	int size = 8;
	vector<double> vec2(size);
	vec2.reserve(size);
	for (int i = 0; i < size; i++)
		vec2[i] = i;
	vec1.swap(vec2);

	print_vec(vec1);
	print_vec(vec2);

	cout << endl;

	vec1.pop_back();
	vec2.erase(vec2.begin()+4, vec2.begin() + 6);

	print_vec(vec1);
	print_vec(vec2);

	_getch();
}