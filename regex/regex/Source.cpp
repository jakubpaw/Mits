#include<iostream>
#include <regex>
#include <fstream>
#include <conio.h>
#include <thread>
#include <chrono>
using namespace std;
void zadanie1()
{
	string str, line, str2;
	fstream file;
	file.open("tekst.txt", std::ios::in);
	if (!file.good())
	{
		cout << "blad" << endl;
	}
	else
	{
		while (!file.eof())
		{
			getline(file, line);
			str += line;
		}
	}
	file.close();
	regex regex1("\\b([a-zA-Z_0-9])*\\.([a-zA-Z]{1,3})\\b");
	auto begin = std::sregex_iterator(str.begin(), str.end(), regex1);
	auto end = std::sregex_iterator();
	std::smatch smatch1;

	for (std::sregex_iterator i = begin; i != end; i++)
	{
		smatch1 = *i;
		str2 += smatch1.str();
		cout << smatch1.str() << endl;
	}
	cout << str2 << endl;
}

void countWords(const string& filename, const string& strPattern)
{
	string line, str;
	fstream file;
	file.open(filename, std::ios::in);
	if (!file.good())
	{
		cout << "blad" << endl;
	}
	else
	{
		while (!file.eof())
		{
			getline(file, line);
			str += line;
			str += "\n";
		}
	}
	file.close();

	regex regex2(strPattern);
	std::regex_iterator<std::string::iterator> begin(str.begin(), str.end(), regex2);
	std::regex_iterator<std::string::iterator> end;

	int count = 0;
	while (begin != end) {
		begin++;
		count++;
	}
	std::cout << " Plik zawiera: " << count << " szukanych slow." << std::endl;
}
void replaceWords(const std::string filename, std::string newFilename, const std::string& strPattern, const std::string& replacement)
{
	string line, str;
	fstream file;
	file.open(filename, std::ios::in);
	if (!file.good())
	{
		cout << "blad" << endl;
	}
	else
	{
		while (!file.eof())
		{
			getline(file, line);
			str += line;
			str += "\n";
		}
	}
	file.close();

	std::regex search(strPattern);
	std::string str2 = std::regex_replace(str, search, replacement);

	file.open("wynik.txt", std::ios::out);
	if (!file.good())
	{
		cout << "blad" << endl;
	}
	else
	{
		file << str2;
	}
	file.close();
	cout << "replaceWords done" << endl;

}
void zadanie2()
{
	countWords("Pan Tadeusz.txt", "\\b(g|G)([^ ]*)");
	replaceWords("Pan Tadeusz.txt", "Nowy Pan Tadeusz.txt", "(Rejtan)", "Janusz");
}
bool validateLogin(const std::string& login)
{
	std::regex regex3("[a-z][a-z0-9-._]{4,14}");
	return regex_match(login, regex3);
}
bool validatePassword(const std::string& password)
{
	std::regex regex3("[a-zA-Z0-9#*$&]{8,}");
	std::regex REGEX3("[A-Z]+");
	std::regex regex3_special("[#*$&]{2,}");

	bool pass1 = false;
	bool pass_upper_case = false;
	bool pass_special = false;

	pass1 = regex_match(password, regex3);
	pass_upper_case = regex_search(password, REGEX3);
	pass_special = regex_search(password, regex3_special);

	if (pass1 && pass_upper_case && pass_special)
		return true;
	return false;
}
void zadanie3()
{
	
	std::string login;
	std::string password;

	int count(-1);

	do {
		login = std::string();
		password = std::string();
		count++;

		if (count)
		{
			std::cout << " Login or password is incorrect!";
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
		system("cls");

		std::cout << " Enter your login: " << std::endl;
		getline(std::cin, login);
		std::cout << " Enter your password: " << std::endl;
		getline(std::cin, password);

	} while (!(validateLogin(login) && validatePassword(password)));
	std::cout << " Register process is complete!";
}
int main()
{
	zadanie1();
	_getch();
	zadanie2();
	_getch();
	zadanie3();
	_getch();
}