// Lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
template<typename T> void f(T x)
{
	coureret << typeid(x).name() << endl;
}
template<typename T = int, int N = 10> class Tab
{
	T tab[N];
public:
	int getSize()
	{
		return N;
	}
	string getType()
	{
		return typeid(T).name();
	}
};
class Player
{
	string name;
public:
	Player(string name) : name(name) {}
	string getName()
	{
		return name;
	}
};
class SoccerPlayer : public Player
{
public:
	SoccerPlayer(string name) : Player(name) {}
};

class BaseballPlayer : public Player
{
public:
	BaseballPlayer(string name) : Player(name) {}
};

template<typename T> class Team
{
	string name;
	vector<T> players;
public:
	Team(string n) :name(n) {}
	void addPlayer(T obj)
	{
		players.push_back(obj);
	}
	void PrintTeam()
	{
		cout << name << endl;
	for (auto &i : players)
	{
		cout << i.getName() << endl;
	}
	}
};
template<long long unsigned int x> struct fib
{
	const static long long unsigned f = fib<x - 1>::f+fib<x - 2>::f;
};
template<> struct fib<0>
{
	const static long long unsigned f = 0;
};
template<> struct fib<1>
{
	const static long long unsigned f = 1;
};
int main()
{
	int x = 0;
	//f(x);
	Tab<> tab;
	cout << tab.getSize() << endl;
	cout << tab.getType() << endl;
	vector<double> tabd;
	tabd.push_back(6.66);
	tabd.push_back(6.9);
	tabd.push_back(4.20);
	//tabd.push_back("666");
	for (auto &i : tabd)
	{
		cout << i << endl;
	}
	BaseballPlayer p0("Player 0");
	BaseballPlayer p1("Player 1");
	SoccerPlayer p2("Player 2");
	SoccerPlayer p3("Player 3");
	Team<BaseballPlayer> baseballTeam("Nazwa 0");
	Team<SoccerPlayer> soccerTeam("Nazwa 1");
	baseballTeam.addPlayer(p0);
	baseballTeam.addPlayer(p1);
	soccerTeam.addPlayer(p2);
	soccerTeam.addPlayer(p3);
	baseballTeam.PrintTeam();
	soccerTeam.PrintTeam();
	cout << fib<100>::f << endl;
    return 0;
}

