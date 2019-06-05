#include <iostream>
#include <string>
#include <regex>

int main()
{
	//ZADANIE 1 -(regex_search)-------------------------------------------------------------
	//Napisz fragment kodu kt�ra sprawdzi ile w podanej tablicy znajduje si� hasel:
	//a) kt�re zawieraj� cyfry (11)
	//b) kt�re nie zawieraja samog�osek (7)
	//Podpowied�: (b) uzyj symboli poczatku i konca lini

	std::string hasla[20] = { "7@Dh^2ur", "hEst^Xf%", "VaKBSRy^","xxK&yGfg", "V4knm%@S" , "8ruWEue@",
		"B3xg!FfX" , "B9ccM^2S" , "PHu&3Xkh" , "Z*eqKRPr" , "!H7H2vd!" , "RynCwt#c" , "%texeJkp" ,
		"x@ftZ#62" , "W$mKUvPx" , "5zM#jeBw" , "*BDvgcY^" , "zvK#bsSV" , "gN9$NcsA" , "wMP8X$Rk" };
	int count = 0;
	int count1 = 0;
    std::regex rex0("[[:digit:]]");
    std::regex rex1("([aAeEiIoOuUyY])");
    for (int i = 0; i < 20; ++i) {
        if(std::regex_search(hasla[i], rex0))
            count++;
        if(!std::regex_search(hasla[i], rex1))
            count1++;
    }

	//ZADANIE 2 -(regex_match)--------------------------------------------------------------
	//Popraw kod, tak aby przyj�� od u�ytkownika tylko poprawnie podany numer, zgodny z formatem.
	// i poinformowa� u�ytkownika gdy to nast�pi.
	//Mo�sz u�y� do tego p�tli do-while
	//Podpowied�: prefiks do Polski to 0048 lub +48 (uwzgl�dnij oba warianty)

	std::string numer;
   std::regex rex2("((0048|\\+48))-([[:digit:]]{3})-([[:digit:]]{3})-([[:digit:]]{3})");
	std::cout << std::endl << "Podaj numer telefonu komorkowego do Polski" << std::endl;
	std::cout << "Format(Prefix-XXX-XXX-XXX) : ";

	std::cin >> numer;
    if(std::regex_match(numer, rex2))
        std::cout << "Poprawny numer" << std::endl;
    else
        std::cout << "Niepoprawny numer" << std::endl;
	//ZADANIE 3 -(regex_replace)------------------------------------------------------------
	//Ponizszy kod, przerabia podany napis tak by samogloski zast�pi� znakiem podkreslenia ('_')
	//Popraw kod u�ywaj�c funkcji regex_replace

	std::string cytat("Zwycieska armia najpierw wygrywa, a potem dazy do walki.\nPokonana armia najpierw walczy, a potem dazy do zwyciestwa.\n-Sun Zi");
	/*
	for (int i = 0; i < cytat.size(); i++)
		if (cytat[i] == 'a' || cytat[i] == 'e' || cytat[i] == 'i' || cytat[i] == 'o' || cytat[i] == 'u' || cytat[i] == 'y')
			cytat[i] = '_';
    */
	cytat = std::regex_replace(cytat, rex1, "_");
	std::cout  << cytat << std::endl;

	//ZDANIE 4 -(smatch)-------------------------------------------------------------------
	//Napisz fragment kodu ktory wypisz pocz�tki s��w ko�cz�ce si� na 'ok' w podanym zdaniu (moga sie powtarzac)
	//Pocz�tek s�owa - czyli wszystko bez jego ko�c�wki.
	
	std::string zdanie("The cook took a good look at the cookery book");
	std::regex rex3("\\b([[:alpha:]]*)ok\\b");
    std::smatch smatch;
    while(std::regex_search(zdanie, smatch, rex3)){
        std::cout <<smatch[1].str() << std::endl;
        zdanie = smatch.suffix().str();
    }
	return 0;
}
