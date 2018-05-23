#include <iostream>
#include <map>
#include <string>
#include <set>
#include <conio.h>
using namespace std;
class Books
{
private:
	multimap<string, string> mm1;
public:
	void add(const string& author,const string& name)
	{
		mm1.insert(pair<string, string>(author, name));
	}
	void erase(const string& author,const string& name)
	{
		for (auto found = mm1.find(author); found != mm1.end() && found->first == author;)
		{
			if (found->second == name)
				found = mm1.erase(found);
			else
				++found;
		}
	}
	void print()
	{
		for (multimap<string, string>::iterator it = mm1.begin(); it != mm1.end(); it++)
			cout << it->first << " " << it->second << endl;
	}
	void print_alphabetically()
	{
		std::map<std::string, std::set<std::string>> order_data;

		for (const auto& author : mm1)
			order_data[author.first].insert(author.second);

		std::cout << "Alphabetically:" << std::endl;
		for (const auto& author : order_data) {
			std::cout << author.first << ": ";
			for (const auto& work : author.second)
				std::cout << work << " ";
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
};
int main()
{
	Books bk1;
	bk1.add("Q.W.", "tytu³1");
	bk1.add("Q.Q.", "tytu³2");
	bk1.add("Y.W.", "tytu³3");
	bk1.add("U.W.", "tytu³4");
	bk1.add("P.W.", "tytu³5");
	bk1.add("I.W.", "tytu³6");
	bk1.add("Q.T.", "tytu³7");
	bk1.add("H.W.", "tytu³8");
	bk1.print();
	bk1.print_alphabetically();
	_getch();

}