#include <iostream>
#include <vector>
#include <algorithm>
#include "constants.h" // G�r det m�jligt att anv�nda strukurerna f�r metoderna
#include "functions.h" // G�r det m�jligt att anv�nda funktionerna fr�n functions.cpp

using namespace std;

int main()
{
	// Variabler som anv�nds f�r att kunna anv�nda metoderna fr�n functions.cpp
	int menu_choice;
	vector<Person> personvector;
	Person person;
	int sort;

	do 
	{
		// Visar menyn i programmet som visar vad anv�ndaren ska mata in f�r att forts�tta
		ShowMenu();

		menu_choice = MenuChoice();
		// Switch loop f�r meny valen som h�mtar respetive metod utifr�n inmatning av anv�ndare
		switch (menu_choice)
		{
		case 1:
			addPerson(person, personvector);
			break;
		case 2:
			WriteList(personvector);
			break;
		case 3:
			FindPerson(personvector);
			break;
		case 4:
			DelPerson(personvector);
			break;
		case 5:
			while ((cout << "Hur vill du sortera listan (1)Namn, (2)Signatur eller (3)L\x84ngd? ") && (!(cin >> sort) || sort < 1 || sort > 3))
			{
				InvalidSortChoice();
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			SortList(sort, personvector);
			break;
		case 6:
			RandList(personvector);
			break;
		case 7:
			SaveFile(personvector);
			break;
		case 8:
			ReadFile(person, personvector);
			break;
		case 9:
			cout << "Avslutar progammet!" << endl;
			return 0;
		default:
			InvalidChoice();
		}

	} while (menu_choice != 7);

	return 0;
}