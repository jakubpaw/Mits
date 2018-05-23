#include<memory>
#include<iostream>
#include<map>
#include<string>
#include <assert.h>
#include <conio.h>

using namespace std;

template <typename KeyT,typename ValueT>
class Zad1
{
public:
	Zad1()=default;
	~Zad1()=default;

	template<typename... Args>

	void Emplace(KeyT&& k1,Args... args);
	void Erase(KeyT&& k1);
	ValueT* Get(KeyT&& k1);
	ValueT* Release(KeyT&& k1);
	shared_ptr<ValueT> ToShared(KeyT&& k1);

private:
	map<KeyT, unique_ptr<ValueT>> zad1_map;
};

template<typename KeyT,typename ValueT>
template<typename... Args>
void Zad1<KeyT, ValueT>::Emplace(KeyT&& k1, Args... args)
{
	zad1_map.try_emplace(move(k1), make_unique<ValueT>(forward<Args>(args)...));
}

template<typename KeyT,typename ValueT>
void Zad1<KeyT, ValueT>::Erase(KeyT&& k1)
{
	zad1_map.erase(k1);
}

template<typename KeyT, typename ValueT>
ValueT* Zad1<KeyT, ValueT>::Get(KeyT&& k1)
{
	auto iterator = zad1_map.find(k1);
	if (iterator == cend(zad1_map))
		return nullptr;
	return iterator->second.get();
}

template<typename KeyT, typename ValueT>
ValueT* Zad1<KeyT, ValueT>::Release(KeyT&& k1)
{
	auto iterator = zad1_map.find(k1);
	if (iterator == cend(zad1_map))
		return nullptr;

	auto result = iterator->second.release();
	zad1_map.erase(iterator);

	return result;
}

template<typename KeyT, typename ValueT>
shared_ptr<ValueT> Zad1<KeyT, ValueT>::ToShared(KeyT&& k1)
{
	auto iterator = zad1_map.find(k1);
	if (iterator == cend(zad1_map))
		return nullptr;

	auto result = shared_ptr<ValueT>{ move(iterator->second) };
	zad1_map.erase(iterator);

	return move(result);
}

class Zad2 : public enable_shared_from_this<Zad2>
{
public:
	Zad2(std::string&& text);
	~Zad2() = default;

	string& GetText();

	shared_ptr<Zad2> GetSelf();
	weak_ptr<Zad2> GetWeakSelf();

private:
	string zad2_Text;
};


Zad2::Zad2(std::string&& text):
	zad2_Text(move(text))
{
}

string& Zad2::GetText()
{
	return zad2_Text;
}

shared_ptr<Zad2> Zad2::GetSelf()
{
	return shared_from_this();
}

weak_ptr<Zad2> Zad2::GetWeakSelf()
{
	return weak_from_this();
}

void tests(Zad2& zad2)
{
	try
	{
		if (const auto self = zad2.GetSelf())
			cout << "wynik GetSelfa: " << self->GetText() << endl;
		else
			cout << "GetSelf NULL" << endl;
	}
	catch (const exception& exception)
	{
		std::cout << "GetSelf exception: " << exception.what() << std::endl;
	}

	const auto weakPointer = zad2.GetWeakSelf();

	cout << "Czy wygasl? : " << weakPointer.expired() << endl;
	cout << "Licznik silnych iteracji: " << weakPointer.use_count() << endl;
}

int main()
{
	Zad1<string, Zad2> zad1;
	zad1.Emplace("1", "blabla");
	zad1.Emplace("2", "asd");
	zad1.Emplace("2", "asd2");
	zad1.Emplace("3", "qwert");
	zad1.Erase("1");


	const auto testMethod = [&zad1](const auto key, const auto methodName, const auto method)
	{
		const auto sharable = (zad1.*method)(key);
		assert(sharable);
		if (!sharable)
			return;

		cout << "testowanie " << methodName << " method: " << endl;
		tests(*sharable);
		cout << endl;
	};

	testMethod("2", "Get", &decltype(zad1)::Get);
	testMethod("2", "ToShared", &decltype(zad1)::ToShared);

	testMethod("3", "Get", &decltype(zad1)::Get);
	testMethod("3", "ToShared", &decltype(zad1)::ToShared);

	_getch();
	return 0;
}