#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>

using namespace std;
int rollDice();

int main()
{
	//Random generator som genererar tal till antalet g�nger t�rningen kasten
	//Summan fr�n alla t�rningskast blir sammanlagt 100% f�r att se hur stor del till exempel antalet sexor f�rekommer
	srand(time(NULL));
	int roll;
	const int a = 100;
	double relativeFrequenceOne, relativeFrequenceTwo, relativeFrequenceThree, relativeFrequenceFour, relativeFrequenceFive, relativeFrequenceSix, ammountOfRolls = 0, ammountOfOne = 0, ammountOfTwo = 0, ammountOfThree = 0, ammountOfFour = 0, ammountOfFive = 0, ammountOfSix = 0;
	//Inmatning f�r hur m�nga g�nger t�rningen ska kastas
	cout << "Mata in antalet g\x84nger t\x84rningen ska kastas: ";
	cin >> ammountOfRolls;
	//En for loop som ber�knar hur m�nga g�nger varje tal f�rekommer genom alla kasten
	for (size_t i = 0; i < ammountOfRolls; i++)
	{
		roll = rollDice();
		if (roll == 1)
		{
			ammountOfOne += 1;
		}
		else if (roll == 2)
		{
			ammountOfTwo += 1;
		}
		else if (roll == 3)
		{
			ammountOfThree += 1;
		}
		else if (roll == 4)
		{
			ammountOfFour += 1;
		}
		else if (roll == 5)
		{
			ammountOfFive += 1;
		}
		else
		{
			ammountOfSix += 1;
		}
	}
	//Utr�kningar som visar hur ofta respektive tal f�re kommer efter alla kast �r gjorda
	relativeFrequenceOne = (ammountOfOne / ammountOfRolls) * a;
	relativeFrequenceTwo = (ammountOfTwo / ammountOfRolls) * a;
	relativeFrequenceThree = (ammountOfThree / ammountOfRolls) * a;
	relativeFrequenceFour = (ammountOfFour / ammountOfRolls) * a;
	relativeFrequenceFive = (ammountOfFive / ammountOfRolls) * a;
	relativeFrequenceSix = (ammountOfSix / ammountOfRolls) * a;

	//Resultatet skrivs ut vilken siffra och hur ofta det f�rekommer som �r procent baserad
	cout << "Antal ettor: " << ammountOfOne << "st	Relativa frekvensen \x84r: " << round(relativeFrequenceOne) << "%" << endl;
	cout << "Antal tv\x86or: " << ammountOfTwo << "st	Relativa frekvensen \x84r: " << round(relativeFrequenceTwo) << "%" << endl;
	cout << "Antal treor: " << ammountOfThree << "st	Relativa frekvensen \x84r: " << round(relativeFrequenceThree) << "%" << endl;
	cout << "Antal fyror: " << ammountOfFour << "st	Relativa frekvensen \x84r: " << round(relativeFrequenceFour) << "%" << endl;
	cout << "Antal femor: " << ammountOfFive << "st	Relativa frekvensen \x84r: " << round(relativeFrequenceFive) << "%" << endl;
	cout << "Antal sexor: " << ammountOfSix << "st	Relativa frekvensen \x84r: " << round(relativeFrequenceSix) << "%" << endl;

	cin.get();
	cin.get();
	return 0;
}
//Metod som genererar tal mellan 1-6 f�r varje kast
int rollDice()
{
	return 1 + rand() % 6;
}


