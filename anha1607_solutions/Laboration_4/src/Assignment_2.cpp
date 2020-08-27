#include <iostream>
#include <sstream>
#include <string>
using namespace std;


bool dagsRabatt(int minute) {

	const int EIGHT_AM = 480;
	const int SIX_THIRTY_PM = 1110;

	//Returnerar true om det �r f�re 08.00 eller efter 18.30

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

//Metod som r�knar ut den totala konstanden f�r samtalet
double totalKostnad(int t1Hour, int t1Minute, int t2Hour, int t2Minute)
{

	int totalMinutes1 = 0, totalMintues2 = 0, fullTax = 0, normalTax = 0;
	double totalCost = 0; // Det totala priset p� samtalet
	const double MOMS = 0.25; // 25% moms
	const double prisTaxa = 4.00;
	const double dagRabatt = 0.35; // Om samtalet �r mellan 8:00 - 18:30 s� blir det 65% rabatt
	const double langdRabatt = 0.85; // 15% rabatt f�r samtal som �r l�ngre �n 30 min

	//Ber�knar totala m�ngden minutrar
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

	//�ndrar kostnaden beroende p� rabatten
	totalCost = ((fullTax * prisTaxa * dagRabatt) + (normalTax * prisTaxa));
	totalCost = totalCost + (totalCost * MOMS);

	//Om samtalet �r l�ngre �n 30 min s� blir det 15% rabatt
	if (fullTax + normalTax > 30)
	{
		totalCost = totalCost * langdRabatt;
	}


	// Ifall samtalet �r mer �n 30 min dras rabatten av fr�n totalkostnaden



	return totalCost; // Returnerar totalkostnaden

}

double kostnad(string startTime, string endTime) {

	//Variablar f�r att ber�kna kostnaden
	bool timeOK = true;
	int t1Hour = 0;
	int t1Minute = 0;
	int t2Hour = 0;
	int t2Minute = 0;

	int colo1 = startTime.find(":");
	int colo2 = endTime.find(":");

	do
	{
		// Skriver �ver ':' med mellanslag
		startTime[colo1] = ' ';

		endTime[colo2] = ' ';

		// Konverterar siffror i str�ng till tal

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



		// Kontrollerar att timmar och minuter �r ok

		// Kontrollerar att stopptiden �r st�rre �n starttiden

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

	} while (!timeOK); // Upprepas ifall tid inte �r ok

}


int main()
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

		//En if sats som kollar om anv�ndaren vill g�ra en till ber�kning
		if (yesOrNo == 'y') {
			newTime = true;
		}if (yesOrNo == 'n') {
			newTime = false;
		}

	}

	return system("pause");
}