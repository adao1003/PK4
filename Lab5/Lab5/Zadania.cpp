#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <list>

void wektor()
{

	std::vector<int>   a{ 3, 1, 4 , 5, 7, 2, 9 };
	std::vector<int>   b{ 8, 4, 1 , 3, 9, 2, 0 };
	std::vector<float> c{ 3, 2, (float)3.3, 4, 5, 6, 8 };
	for (auto it =a.begin(); it !=a.end(); it=std::next(it,1))
	{
		std::cout << *it << std::endl;
	}
	auto min = b.begin();
	auto max = b.begin();
	for (auto it = b.begin();it != b.end();it++)
	{
		if (*it > *max)
			max = it;
		else if(*it<*min)
			min = it;
	}
	std::cout << "MIN:" << *min << std::endl;
	std::cout << "MAX:" << *max << std::endl;
	std::cout << "Distance:" << std::distance(min, max) << std::endl;
	/*
	int mini = *itb;
	std::vector<int>::iterator miniwsk = itb;
	int maks = *itb;
	std::vector<int>::iterator maxwsk = itb;
	*/
}


void lista()
{
	std::list<char> listaA{   'n', 'i', 'e' , 'm', 'i' , 'l' , 'e' , 'g' , 'o' ,' ', 'd' , 'n' , 'i', 'a' };
	std::list<char> listaB{ 's', 'e', 'i', 'p',' ','o','t','l','a','r','s',' ','e','i','b','o','s',' ','c','e','i','z','d','e','i','w','o','p',' ','i','l','y','z',
		'c',' ',',','e','i','n','z','c','i','f','z','o','l','i','f',' ','y','z','c','e','z','r','o','d',' ','c','s','j','e','d','o','p',' ','a','n','z','o','m',' ',
		'o','c',' ','o','n','d','e','j' };
	for (auto it = --listaA.rend();;it--)
	{
		std::cout << *it;
		if (it == listaA.rbegin())
			break;
	}
}

void iterator_ktory()
{
	std::list<int> l;
	std::vector<int> w;
	//std::array<int, 10> a;
	
	//test(l.begin(), l.end());
	//test(a.begin(), a.end());
	//test(w.begin(), w.end());	
}

class card
{
private:
	int figure;
	std::string color;
public:
	card(int fig, std::string col) : figure(fig), color(col) {}
	card() : figure(14), color("none") {}
	int get_figure() { return figure; }
	std::string get_color() { return color; }
	bool operator< (const card& c)
	{
		return false;
	}
	bool operator==(const card& c)
	{
		if (c.color == color&&c.figure == figure)
			return true;
		else
			return false;
	}

};
class student
{
private:
	std::string name;
	std::string surname;
	int age;
public:
	double marks[3];
	student(std::string nam, std::string surnam, int ag) : name(nam), surname(surnam), age(ag)
	{
		for (int i = 0;i < 3;i++) marks[i] = (rand() % 7) / 2 + 2;
	}
	bool operator< (const student& c)
	{
		return age < c.age ? true:false;
	}
};


int main()
{
	//funkcje i klasy do zadań znajdują się powyżej i mogą wymagać modyfikacji
	//zad -4
	//a) Używając funkcji next() lub prev() odczytać wartości wektora a.Sprawdzić co się stanie gdy wskaźnikiem wyjdziemy poza obszar danych.
	//	Dołączyć bibliotekę <vector>, <iterator>;
	//b) znaleźć najmniejszą i największą wartość vectora b.porównać indeksy obu wartości i obliczyć ich różnicę za pomocą funkcji distance().nie używać inkrementacji iteratora ani funkcji min_element i max_element z <algorithm>
	//c) sprawdzić czy da się odczytać wartość vectora c oraz b za pomocą iteratora z zadania a. NIE

	wektor();

	//zad -3
	//a) wypisać napis ListaA w konsoli za pomocą iteratorów rewersyjnych, dołączyć bibliotekę <list>, nie dopisywać 0 :)
	//c) sprawdzić kompatybilność z "zwykłymi" itratorami

	lista();

	//zad -2
	//Napisać funkcję test(), która sprawdza dostęp do: vectora, listy, tablicy



	//zad -1 vector<card> deck przedstawia talię kart gdzie 1 - as, 11 - walet, 12 - dama, 13 - król
	//a) zastosować funkcje sort, search, remove do vectora deck i skompilować - sprawdzić co się stanie jeśli nie działają to naprawić
	//b) potasować karty (random_shuffle) i znaleźć asa kier a następnie usunąć go z talii
	//c) napisać funkcję lub sam kod rozdający 5 kart do "ręki" (nowy vector<card> hand) tak aby nie pozostały w talii, sprawdzić czy karty wciąż znajdują się w talii. Użyć copy(), search(), erase()
	
	std::vector<card> deck;
	for (int i = 0;i < 13;i++)
	{
		deck.push_back(card(i+1, "kier"));
		deck.push_back(card(i+1, "karo"));
		deck.push_back(card(i+1, "pik"));
		deck.push_back(card(i+1, "trefl"));
	}
	std::sort(deck.begin(),deck.end());
	std::random_shuffle(deck.begin(), deck.end());
	for (auto i = deck.begin();i != deck.end();i++)
	{
		if (i->get_figure() == 1 && i->get_color() == "kier") {
			deck.erase(i);
			break;
		}
	}
	//for (auto i = deck.begin();i != deck.end();i++)
	//{
	//	std::cout << i->get_figure() << " " << i->get_color() << std::endl;
	//}
	std::vector<card> hand;
	std::random_shuffle(deck.begin(), deck.end());
	hand.insert(hand.begin(), deck.begin(), deck.begin() + 5);
	deck.erase(deck.begin(), deck.begin() + 5);
	for (auto i = hand.begin();i != hand.end();i++)
	{
		std::cout << i->get_figure() << " " << i->get_color() << std::endl;
	}
	//zad 0 vector<student> classRegi przedstawia interpretację dziennika
	//a) napisać funkcję lub kod który będzie sortował pod względem wybranego przez użytkownika atrybutu: imienia, nazwiska, wieku lub średniej ocen
	//b) znaleźć uczniów których średnia jest mniejsza lub równa 2.5 i wpisać ich do nowego wektora (warunkowicze)
	//c) usunąć z dziennika wszystkie osoby ze średnią 2.5 lub mniejszą
	
	std::vector<student> classRegi;
	std::vector<student> warunkowicze;
	classRegi.push_back(student("Artur", "Marbach", 21));
	classRegi.push_back(student("Katarzyna", "Majgier", 20));
	classRegi.push_back(student("Adam", "Chłopek", 22));
	classRegi.push_back(student("Sebastian", "Skutela", 23));
	classRegi.push_back(student("Anna", "Absurd", 20));
	classRegi.push_back(student("Hubert", "Przyszlak", 19));
	classRegi.push_back(student("Karolina", "Mach", 19));
	std::sort(classRegi.begin(), classRegi.end());
	for (auto it = classRegi.begin();it != classRegi.end();it++)
	{
		int sum = 0;
		for (int i = 0;i < 3;i++)
		{
			sum += it->marks[i];
		}
		if (sum / 3.0 < 2.50)
		{
			warunkowicze.push_back(*it);
		}
	}
	std::cin.get();
	return 0;
}
