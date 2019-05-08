// InteligentneWskazniki.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <memory>
#include <iostream>

using namespace std;

class justClass
{
public:
	int x;
	int y;
	int z;

	justClass(int x, int y, int z) : x(x), y(y), z(z)
	{}
	~justClass()
	{}

	void show()
	{
		cout << x << '\t';
		cout << y << '\t';
		cout << z << endl;
	}
};

int main()
{
	//auto_ptr
#pragma region Zadanie 1
	cout << endl << "~~~ ZADANIE 1 ~~~" << endl << endl;

	//Stwórz wskaźnik a_ptr1 typu auto_ptr i przypisz mu obiekt klasy justClass
	cout << endl << "~~~Dodanie a_ptr1~~~" << endl;

	auto_ptr<justClass> a_ptr1(new justClass(69,666,420));

	//Odczytaj wartości obiektu, na który wskazuje a_ptr
	cout << "a_ptr1: " << endl;
	a_ptr1->show();

	//Stwórz wskaźnik a_ptr2 typu auto_ptr i przypisz mu a_ptr1 
	cout << endl << "~~~Dodanie a_ptr2~~~" << endl;
	auto_ptr<justClass> a_ptr2 = a_ptr1;

	//Czy można użyć funkcji show() z klasy justClass przy pomocy wskaźników a_ptr1 oraz a_ptr2?
	//Sprawdź funkcją get() czy a_ptr1 oraz a_ptr2 czy oba wskaźniki wskazują na ten sam obiekt (jeśli wskazują na jakikolwiek).
	cout << "a_ptr1: " << endl;
//	a_ptr1->show();
	cout << "a_ptr2: " << endl;
	a_ptr2->show();
	//Podejmij próbę usunięcia wskazników przy użyciu reset()
	cout << endl << "~~~Reset~~~" << endl;
	a_ptr2.reset();

	//Jeśli udało się usunąć wskaźniki:
	//Czy można wywołać procedurę show() na obiekt1?
///	cout << "obiekt1: " << endl;
//	a_ptr2->show();
	//Jeśli nie udało się usunąć wskaźników, podejmij próbę ich usunięcia przy pomocy release

#pragma endregion

	//unique_ptr
#pragma region Zadanie2
	cout << endl << "~~~ ZADANIE 2 ~~~" << endl << endl;

	justClass obiekt2 = justClass(4, 5, 6);
	cout << "obiekt2: " << endl;
	obiekt2.show();

	//Stwórz wskaźnik u_ptr1 typu unique_ptr i przypisz mu obiekt2
	cout << endl << "~~~Dodanie u_ptr1~~~" << endl;

	unique_ptr<justClass> u_ptr1(&obiekt2);
	//Odczytaj wartości obiektu, na który wskazuje u_ptr
	cout << "u_ptr1: " << endl;


	//Stwórz wskaźnik u_ptr2 typu unique_ptr i przypisz mu u_ptr1 
	cout << endl << "~~~Dodanie u_ptr2~~~" << endl;
	unique_ptr<justClass> u_ptr2(&(*u_ptr1)); /// MOŻNA xD

	//Czy można użyć funkcji show() z klasy justClass przy pomocy zarówno wskaźnika u_ptr1 jaki i u_ptr2?
	//Sprawdź funkcją get() czy u_ptr1 oraz u_ptr2 czy oba wskaźniki wskazują na ten sam obiekt (jeśli wskazują na jakikolwiek).
	cout << "u_ptr1: " << u_ptr1.get() << endl;

	cout << "u_ptr2: " << u_ptr2.get() << endl;

	//Podejmij próbę usunięcia wskaźników przy pomocy release
	cout << endl << "~~~Release~~~" << endl;
	u_ptr1.release();
	u_ptr2.release();
	obiekt2.show();
	//Jeśli udało się usunąć wskaźniki:
	//Czy można wywołać procedurę show() na obiekt2?
///	cout << "obiekt2: " << endl;

#pragma endregion

	//shared_ptr
#pragma region Zadanie3
	cout << endl << "~~~ ZADANIE 3 ~~~" << endl << endl;

	//Stwórz wskaźnik shared_ptr o nazwie s_ptr1 na nowo stworzony obiekt klasy justClass

	//Stwórz dwa wskaźniki shared_ptr odnoszące się do zrobionego przed chwilą wskaźnika

	auto s_ptr1 = std::make_shared<justClass>(666, 69, 420);
	auto s_ptr2 = s_ptr1;
	auto s_ptr3 = s_ptr1;
	//Odczytaj wartości obiektu, na który wskazuje poszczególny wskaźnik 
	cout << "Wskaznik 1: " << s_ptr1.get() << endl;

	cout << "Wskaznik 2: " << s_ptr2.get() << endl;

	cout << "Wskaznik 3: " << s_ptr3.get() << endl;


	//Użyj odpowiedniej funkcji, by policzyć liczbę wskaźników, które wskazują na ten sam obiekt, co wskaźnik s_ptr1
	cout << "Liczba wskaznikow: " << s_ptr1.use_count()<< endl;

	//Sprawdź czy użycie funkcji reset() na s_ptr1 wpłynie w jakiś sposób na stworzone przez Ciebie wskaźniki shared_ptr
	cout << endl << "~~~ Usuniecie s_ptr1 ~~~" << endl;
	s_ptr1.reset();
	cout << "Wskaznik 1: " << s_ptr1.get() << endl;

	cout << "Wskaznik 2: " << s_ptr2.get() << endl;

	cout << "Wskaznik 3: " << s_ptr3.get() << endl;
#pragma endregion

	//weak_ptr
#pragma region Zadanie 4
	cout << endl << "~~~ ZADANIE 4 ~~~" << endl << endl;
	
	//Stwórz po jednym weak_ptr odnoszącym się do każdego z shared_ptr stworzonych gdzieś powyżej (i wciąż istniejących)
	cout << endl << "~~~ Dodanie weak_ptr ~~~" << endl;
	weak_ptr<justClass> weak0 = s_ptr2;
	weak_ptr<justClass> weak1 = s_ptr3;
	//Użyj odpowiedniej funkcji, by policzyć ile jest wskaźników shared_ptr 
	//oraz stworzonych niedawno weak_ptr odnoszących się do poszczególnych obiektów
	cout << "Liczba wskaznikow shared_ptr: " <<s_ptr2.use_count()<<  endl;
	cout << "Liczba wskaznikow weak_ptr: " << weak0.use_count() << endl;// nie da się policzyc (chyba)


	//Przy użyciu odpowiedniej funkcji na weak_ptr, stwórz nowy shared_ptr, 
	//przypisując mu jeden z już istniejących shared_ptr, na który wskazuje jeden z weak_ptr
	
	auto sh = weak0.lock();
	//Podejmij próbę usunięcia shared_ptr stworzonych w zadaniu 4
	cout << endl << "~~~ Usuniecie kolejnych shared_ptr ~~~" << endl;
	s_ptr2.reset();
	s_ptr3.reset();
	//Przy użyciu odpowiedniej funkcji, sprawdź czy wciąż istnieje shared_pointer, do którego odnoszą się weak_ptr
	cout << weak0.expired() << endl;

	//Podejmij próbę usunięcia shared_ptr stworzonego w tym zadaniu
	cout << endl << "~~~ Usuniecie ostatniego z shared_ptr ~~~" << endl;
	sh.reset();
	cout << weak0.expired() << endl;
	// Jeśli udało się usunąć shared_ptr:
	// Przy użyciu odpowiedniej funkcji, sprawdź czy wciąż istnieje shared_pointer, do którego odnoszą się weak_ptr


	//Usuń weak_ptr

#pragma endregion

#pragma region Zadanie5
	cout << endl << "~~~ ZADANIE 5 ~~~" << endl;
	//Uzupełnij dwie poniższe klasy, aby obiekty pierwszej klasy wskazywały na obiekty drugiej
	//a obiekty drugiej klasy wskazywały na obiekty pierwszej. Wykorzystać w obu shared_ptr.
	//Nie zapomnij, aby konstruktor zawierał odpowiedni fragment, 
	//by przy tworzeniu obiektu można było mu przypisać wskaźnik do drugiej klasy.

	class Pierwsza;
	class Druga;

	class Pierwsza
	{
	public:
		shared_ptr<Druga> ptr;
		Pierwsza(Druga* p):ptr(p)
		{}
		Pierwsza(shared_ptr<Druga> p) :ptr(p)
		{}
		~Pierwsza()
		{}
	};

	class Druga
	{
	public:
		shared_ptr<Pierwsza> ptr;
		Druga(Pierwsza* p) :ptr(p) {}
		Druga(shared_ptr<Pierwsza> p) :ptr(p) {}
		~Druga()
		{}
	};

	//Odkomentuj i zupełnij poniższy kod, aby obiekty zawierały wskaźniki na obiekty drugiej klasy
	shared_ptr<Pierwsza> a = std::make_shared<Pierwsza>(nullptr);
	shared_ptr<Pierwsza> b = std::make_shared<Pierwsza>(nullptr);
	shared_ptr<Druga> c = std::make_shared<Druga>(a);
	shared_ptr<Druga> d = std::make_shared<Druga>(b);
	shared_ptr<Druga> e = std::make_shared<Druga>(b);
	shared_ptr<Druga> f = std::make_shared<Druga>(a);
	shared_ptr<Pierwsza> g = std::make_shared<Pierwsza>(c);
	shared_ptr<Pierwsza> h = std::make_shared<Pierwsza>(d);
	shared_ptr<Pierwsza> i = std::make_shared<Pierwsza>(e);
	shared_ptr<Pierwsza> j = std::make_shared<Pierwsza>(f);
	shared_ptr<Pierwsza> k = std::make_shared<Pierwsza>(f);

	//Funkcją use_count policzyć liczbę poszczególnych wskaźników i wyświetlić w konsoli (jeśli to możliwe).
	cout << "c: " << c.use_count() << endl;
	cout << "d: " << d.use_count() << endl;
	cout << "e: " << e.use_count() << endl;
	cout << "f: " << f.use_count() << endl;
	cout << "a: " << a.use_count() << endl;
	cout << "b: " << b.use_count() << endl;

	//Odkomentuj poniższy kod. Pozbywamy się w nim obiektów jednej z klas.
	c.reset();
	d.reset();
	e.reset();
	f.reset();

	//Czy istnieje możliwość dostania się do danych usuniętych wskazników? Pokaż na przykładzie.
	cout << g->ptr << endl;

	//Uzupełnij dwie poniższe klasy, aby obiekty pierwszej klasy wskazywały na obiekty drugiej
	//a obiekty drugiej klasy wskazywały na obiekty pierwszej. Wykorzystać w jednej shared_ptr, w drugiej weak_ptr.
	//Nie zapomnij, aby konstruktor zawierał odpowiedni fragment, 
	//by przy tworzeniu obiektu można było mu przypisać wskaźnik do drugiej klasy.

	class tuSharedPtr;
	class tuWeakPtr;

	class tuSharedPtr
	{
	public:
		shared_ptr<tuWeakPtr> ptr;
		tuSharedPtr(shared_ptr<tuWeakPtr> ptr):ptr(ptr)
		{}
		~tuSharedPtr()
		{}
	};

	class tuWeakPtr
	{
	public:
		shared_ptr<tuSharedPtr> ptr;
		tuWeakPtr(shared_ptr<tuSharedPtr> ptr) :ptr(ptr)
		{}
		~tuWeakPtr()
		{}
	};

	//Odkomentuj i uzupełnij poniższy kod, aby obiekty zawierały wskaźniki na obiekty drugiej klasy
	shared_ptr < tuSharedPtr> a2 = make_shared<tuSharedPtr>(nullptr);
	shared_ptr < tuSharedPtr> b2 = make_shared<tuSharedPtr>(nullptr);
	shared_ptr < tuWeakPtr> c2 = make_shared<tuWeakPtr>(a2);
	shared_ptr < tuWeakPtr> d2 = make_shared<tuWeakPtr>(a2);
	shared_ptr < tuWeakPtr> e2 = make_shared<tuWeakPtr>(b2);
	shared_ptr < tuWeakPtr> f2 = make_shared<tuWeakPtr>(b2);
	shared_ptr < tuSharedPtr> g2 = make_shared<tuSharedPtr>(c2);
	shared_ptr < tuSharedPtr> h2 = make_shared<tuSharedPtr>(d2);
	shared_ptr < tuSharedPtr> i2 = make_shared<tuSharedPtr>(f2);
	shared_ptr < tuSharedPtr> j2 = make_shared<tuSharedPtr>(e2);
	shared_ptr < tuSharedPtr> k2 = make_shared<tuSharedPtr>(d2);

	//Funkcją use_count policzyć liczbę poszczególnych wskaźników i wyświetlić w konsoli (jeśli to możliwe).
	cout << "c2: " << c2.use_count() << endl; 
	cout << "d2: " << d2.use_count() << endl;
	cout << "e2: " << e2.use_count() << endl;
	cout << "f2: " << f2.use_count() << endl;
	cout << "a2: " << a2.use_count() << endl;
	cout << "b2: " << b2.use_count() << endl;

	//Odkomentuj poniższy kod. Pozbywamy się w nim obiektów jednej z klas. Dopilnuj, aby była to klasa z shared_ptr.
	a2.reset();
	b2.reset();
	g2.reset();
	h2.reset();
	i2.reset();
	j2.reset();
	k2.reset();

	//Czy istnieje możliwość dostania się do danych usuniętych wskazników? Pokaż na przykładzie.
	cout << h2->ptr.get();
#pragma endregion

	return 1;
}
