#include<iostream>
#include<exception>
#include<string>
#include<limits>

void Zakupy(int ciastka, int mleko)
{
	if (mleko == 0)
	{
		throw ciastka;
	}
	auto ile_kupie = ciastka / static_cast<double>(mleko);
}
class MyExceptionClass : public std::exception
{
	std::string messsage = "KATASTROFALNY BLAD!!!!!!!!!!!!!!!!!!!!!";
	public:
		MyExceptionClass()
		{
			std::cout << "Konstrukto" << std::endl;
		}
		~MyExceptionClass()
		{
			std::cout << "Destrukotr" << std::endl;
		}
		const char* what() const noexcept override
		{
			return messsage.c_str();
		}
};
void Fib()
{
	int l1 = 0;
	int l2 = 1;
	for (;;)
	{
		int fib = l1 + l2;
		l1 = l2;
		l2 = fib;
		if (fib >= std::numeric_limits<short>::max())
			throw MyExceptionClass();
	}
}
class Zolnierze
{
protected:
	std::string info;
public:
	Zolnierze() : info("Jakas Armia") {}
	Zolnierze(const std::string & nazwa_armii) : info(nazwa_armii) {}
	virtual std::string PodajInfo()
	{
		return info;
	}
};
class Saparzy : public Zolnierze
{
public:
	virtual std::string PodajInfo()
	{
		return info;
	}
};
void Sprawdz(int armia_nr1, int armia_nr2)
{
	if (armia_nr1 < 0 || armia_nr2 < 0)
		throw Zolnierze("Armia Zbigniefa");
}
int main()
{
	int x = 0, y = 0;
	int lzol1 =-420, lzol2 = 666;
	Zolnierze* ptrZ = nullptr;
	std::cout<<typeid(ptrZ).name();

	Zolnierze pz;
	try
	{
		auto temp = dynamic_cast<Saparzy&>(pz);
	}
	catch (std::bad_cast& e)
	{
		std::cout << e.what();
	}
	try
	{
		for (;;)
		{
			Saparzy* tabSap = new Saparzy[10000000ul];
		}
	}
	catch (std::bad_alloc& e)
	{
		std::cout << "Brak miejsca!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		try
		{
			Sprawdz(lzol1, lzol2);
			Fib();
			Zakupy(x, y);
		}
		catch (int e)
		{
			std::cout << "Brak mleka. Iloœæ ciastek:" << e << std::endl;
		}
		catch (MyExceptionClass& e)
		{
			std::cout << e.what() << std::endl;
			throw;
		}
		catch (Zolnierze& e)
		{
			std::cout << e.PodajInfo() << std::endl;
		}
		catch (...)
		{

		}
	}
	catch (MyExceptionClass& e)
	{
		std::cout << "Dowodze" << std::endl;
	}
	std::cin.get();
}