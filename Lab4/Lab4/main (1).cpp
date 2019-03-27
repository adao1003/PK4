#include <iostream>
#include <string>

#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <list>
#include <forward_list>
#include <deque>
#include <vector>
#include <array>

template<typename T> T stack69(std::stack<T> s)
{
	for (int i = 0; i <= s.size()+1;i++)
	{
		s.pop();
	}
	return s.top();
}
template<typename T> void stack666(std::stack<T>& s)
{
	std::stack<T> tempS;
	for (int i = 0; i <= s.size()+1;i++)
	{
		tempS.push(s.top());
		s.pop();
	}
	s.pop();
	while(!tempS.empty())
	{
		s.push(tempS.top());
		tempS.pop();
	}
}
template <typename T> std::map<int, T> map666(std::map<int, T> m)
{
	std::map<int, T> temp;
	for (auto i = m.begin(); i != m.end(); i++)
	{
		if (i->first % 2 != 0)
			temp.insert(*i);
	}
	return temp;
}
void main() {
	// ZAD0a
	std::vector<char> v{ 'F', 'r', 'i', 'e', 'n', 'd', 's', 0 };
	// Sprawdzić, co się stanie podczas próby wypisania na strumień wyjścia metody data()
	std::cout << v.data();
	// ZAD0b
	// Co trzeba zrobić, aby uniknąć sytuacji z ZAD0a?

	// ZAD1
	std::array <int, 10> array{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	// Porównaj działanie operatora[], metody at() oraz funkcji std::get<>(),
	//  próbując odczytać element o indeksie nie należącym do tablicy
//	array[10];
//	array.at(10);	
//	std::get<10>(array);

	// ZAD2
	std::vector<std::string> vector{ "000","011","010","011","110" };
	std::vector<std::string>::iterator iterV = vector.begin() + 1;
	*iterV = "001";
	*(iterV + 3) = "100";
	//vector.resize(8);
	vector.insert(vector.end(), "101");
	vector.insert(vector.end(), "110");
	vector.insert(vector.end(), "111");
	for (auto &i : vector)
	{
		std::cout << i << std::endl;
	}
	//vector.insert(iterV + 5, "110");
	//vector.insert(iterV + 6, "111");
	// Korzystając z iteratorów, popraw i uzupełnij vector, tak aby elementy w nim zawarte układały się w ciąg "000","001","010","011","100","101","110","111"
	
	// ZAD3
	std::deque<char> deque{ 'K', 'o', 'b', 'y', 'l', 'a', ' ', 'm', 'a', ' ', 'm', 'a', 'l', 'y', ' ', 'b', 'o', 'k' };
	std::string temp0;
	std::string temp1;
	for (auto it = deque.begin();it != deque.end();it++)
	{
		if ((*it) == 32)
			continue;
		temp0 += toupper(*it);
	}
	for (auto it = deque.rbegin();it != deque.rend();it++)
	{
		if ((*it) == 32)
			continue;
		temp1 += toupper(*it);
	}
	//std::cout << temp0 << std::endl;
	//std::cout << temp1 << std::endl;
	if (temp0 == temp1)
		std::cout << "palindrom" << std::endl;
	else
		std::cout << "nie palindrom" << std::endl;
	// Napisz funkcję sprawdzającą, czy std::deque<char> przechowuje palindrom. Wykorzystaj iteratory. (toupper() i pominięcie znaków białych)
	// ZAD4a
	std::stack<double> stack;
	stack.push(0.0009);
	stack.push(0.2352);
	stack.push(0.2547);
	stack.push(0.4643);
	stack.push(0.5454);
	std::cout << stack69(stack) << std::endl;
	stack666(stack);
	std::cout << stack69(stack) << std::endl;
	std::cout << stack.top() << std::endl;
	// Napisz funkcję zwracającą element znajdujący się na dnie stosu przechowującego dowolne typy
	
	// ZAD4b
	// Napisz funkcję usuwającą element znajdujący się na dnie stosu przechowującego dowolne typy

	// ZAD5
	std::map<int, int> map{ {1,5},{2,6},{5,4},{4,7},{7,9},{8,8} };
	auto tempMap = map666(map);
	for (auto &i : tempMap)
	{
		std::cout << i.second << std::endl;
	}
	std::cin.get();
	// Napisz funkcję, która wyciągnie z kontenera std::map<int, T> elementy o nieparzystych kluczach i zwróci je jako drugi kontener std::map<int, T> (iterator->first)
}