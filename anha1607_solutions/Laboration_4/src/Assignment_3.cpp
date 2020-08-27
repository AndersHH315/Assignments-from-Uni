#include<iostream>
#include<string>
#include <sstream>
#include<iomanip>
#include<math.h>
using namespace std;

int rollDice();

void dices()
{
	//Random generator som genererar tal till antalet gånger tärningen kasten
	//Summan från alla tärningskast blir sammanlagt 100% för att se hur stor del till exempel antalet sexor förekommer
	srand(time(NULL));
	int roll;
	const int a = 100;
	double relativeFrequenceOne, relativeFrequenceTwo, relativeFrequenceThree, relativeFrequenceFour, relativeFrequenceFive, relativeFrequenceSix, ammountOfRolls = 0, ammountOfOne = 0, ammountOfTwo = 0, ammountOfThree = 0, ammountOfFour = 0, ammountOfFive = 0, ammountOfSix = 0;
	//Inmatning för hur många gånger tärningen ska kastas
	cout << "Mata in antalet g\x86nger t\x84rningen ska kastas: ";
	cin >> ammountOfRolls;
	//En for loop som beräknar hur många gånger varje tal förekommer genom alla kasten
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
	//Uträkningar som visar hur ofta respektive tal före kommer efter alla kast är gjorda
	relativeFrequenceOne = (ammountOfOne / ammountOfRolls) * a;
	relativeFrequenceTwo = (ammountOfTwo / ammountOfRolls) * a;
	relativeFrequenceThree = (ammountOfThree / ammountOfRolls) * a;
	relativeFrequenceFour = (ammountOfFour / ammountOfRolls) * a;
	relativeFrequenceFive = (ammountOfFive / ammountOfRolls) * a;
	relativeFrequenceSix = (ammountOfSix / ammountOfRolls) * a;

	//Resultatet skrivs ut vilken siffra och hur ofta det förekommer som är procent baserad
	cout << "Antal ettor: " << ammountOfOne << "st	Relativa frekvensen \x84r: " << round(relativeFrequenceOne) << "%" << endl;
	cout << "Antal tv\x86or: " << ammountOfTwo << "st	Relativa frekvensen \x84r: " << round(relativeFrequenceTwo) << "%" << endl;
	cout << "Antal treor: " << ammountOfThree << "st	Relativa frekvensen \x84r: " << round(relativeFrequenceThree) << "%" << endl;
	cout << "Antal fyror: " << ammountOfFour << "st	Relativa frekvensen \x84r: " << round(relativeFrequenceFour) << "%" << endl;
	cout << "Antal femor: " << ammountOfFive << "st	Relativa frekvensen \x84r: " << round(relativeFrequenceFive) << "%" << endl;
	cout << "Antal sexor: " << ammountOfSix << "st	Relativa frekvensen \x84r: " << round(relativeFrequenceSix) << "%" << endl;

	cin.get();
	cin.get();
}
//Metod som genererar tal mellan 1-6 för varje kast
int rollDice()
{
	return 1 + rand() % 6;
}


bool dagsRabatt(int minute) {

	const int EIGHT_AM = 480;
	const int SIX_THIRTY_PM = 1110;

	//Returnerar true om det är före 08.00 eller efter 18.30

	// 1 dygn = 24 * 60 minuter = 1440 minuter)

	if ((minute >= 0 && minute < EIGHT_AM) || (minute >= SIX_THIRTY_PM && minute <= 1440))
	{
		return true;
	}
	else
	{
		return false;
	}

}

double totalKostnad(int t1Hour, int t1Minute, int t2Hour, int t2Minute)
{

	int totalMinutes1 = 0, totalMintues2 = 0, fullTax = 0, normalTax = 0;
	double totalCost = 0; // Det totala priset på samtalet
	const double MOMS = 0.25; // 25% moms
	const double prisTaxa = 4.00;
	const double dagRabatt = 0.35; // Om samtalet är mellan 8:00 - 18:30 så blir det 65% rabatt
	const double langdRabatt = 0.85; // 15% rabatt för samtal som är längre än 30 min

	//Beräknar totala mängden minutrar
	totalMinutes1 = (t1Hour * 60) + t1Minute;
	totalMintues2 = (t2Hour * 60) + t2Minute;



	for (int i = totalMinutes1; i < totalMintues2; i++)

	{

		if (!(dagsRabatt(i))) // Anropar funktionen "dagsRabatt"
		{
			normalTax++;
		}
		else
		{
			fullTax++;
		}

	}

	//Ändrar kostnaden beroende på rabatten
	totalCost = ((fullTax * prisTaxa * dagRabatt) + (normalTax * prisTaxa));
	totalCost = totalCost + (totalCost * MOMS);

	//Om samtalet är längre än 30 min så blir det 15% rabatt
	if (fullTax + normalTax > 30)
	{
		totalCost = totalCost * langdRabatt;
	}


	// Ifall samtalet är mer än 30 min dras rabatten av från totalkostnaden



	return totalCost; // Returnerar totalkostnaden
}

double kostnad(string startTime, string endTime) {

	//Variablar för att beräkna kostnaden
	bool timeOK = true;
	int t1Hour = 0;
	int t1Minute = 0;
	int t2Hour = 0;
	int t2Minute = 0;

	int colo1 = startTime.find(":");
	int colo2 = endTime.find(":");

	do
	{
		// Skriver över ':' med mellanslag
		startTime[colo1] = ' ';

		endTime[colo2] = ' ';

		// Konverterar siffror i sträng till tal

		istringstream start(startTime);

		start >> t1Hour >> t1Minute;

		istringstream stop(endTime);

		stop >> t2Hour >> t2Minute;



		if ((startTime.length() == 4 && colo1 == 1) || (startTime.length() == 5 && colo1 == 2))
		{
			timeOK = true;
		}

		if ((endTime.length() == 4 && colo1 == 1) || (endTime.length() == 5 && colo1 == 2))
		{
			timeOK = true;
		}



		// Kontrollerar att timmar och minuter är ok

		// Kontrollerar att stopptiden är större än starttiden

		if (t1Hour < 0 || t1Hour > 23)

			timeOK = false;

		if (t2Hour < 0 || t2Hour > 23)

			timeOK = false;

		if (t1Minute < 0 || t1Minute > 59)

			timeOK = false;

		if (t2Minute < 0 || t2Minute > 59)

			timeOK = false;

		if ((t2Hour * 60 + t2Minute) < (t1Hour * 60 + t1Minute))

			timeOK = false;

		if (!timeOK)
		{
			cout << "Felaktig inmatning!" << endl;
			cout << "Mata in (hh:mm) eller (h:mm)" << endl;
			return totalKostnad(0, 0, 0, 0);
		}
		else
		{
			return totalKostnad(t1Hour, t1Minute, t2Hour, t2Minute);
		}

	} while (!timeOK); // Upprepas ifall tid inte är ok


}

void phonecall()
{
	bool newTime = true;
	char yesOrNo;
	string startTime, endTime;

	while (newTime == true) {
		cout << "N\x84r startade samtalet? (Format hh:mm eller h:mm) " << endl;
		cin >> startTime;
		cout << "N\x84r avslutades samtalet? (Format hh:mm eller h:mm) " << endl;
		cin >> endTime;

		cout << "Total samtalskostnad: " << endl << kostnad(startTime, endTime) << "kr " << endl;

		cout << "Vill du g\x94ra ny ber\x84kning? (y/n)" << endl;
		cin >> yesOrNo;

		//En if sats som kollar om användaren vill göra en till beräkning
		if (yesOrNo == 'y') {
			newTime = true;
		}if (yesOrNo == 'n') {
			newTime = false;
		}

	}

}

//Metod som visar alternativen i programmet för användaren
void showmenu()
{
	cout << "V\x84lj program genom att ange ett nummer " << endl;
	cout << "Tryck 1 f\x94r att kasta t\x84rning " << endl;
	cout << "Tryck 2 f\x94r att r\x84kna kostnaden f\x94r ett samtal " << endl;
	cout << "Tryck 3 f\x94r att avsluta " << endl;
}



int main() {

	bool again = true;

	do
	{
		showmenu();
		char number;
		cin >> number;

		switch (number)
		{
		case '1': dices();
			break;
		case '2': phonecall();
			break;
		case '3': exit(0);
			break;
		}
	} while (again);
    return 0;
}

