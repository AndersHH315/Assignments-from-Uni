#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include "constants.h"

using namespace std;

// Menyn som visar i början på programmet
void ShowMenu()
{
	cout << "             Meny " << endl;
	cout << "1. L\x84gg till person i listan " << endl;
	cout << "2. Skriv ut listan p\x86 sk\x84rmen " << endl;
	cout << "3. S\x99k efter person i listan " << endl;
	cout << "4. Ta bort en person i listan " << endl;
	cout << "5. Sortera listan " << endl;
	cout << "6. Blanda listan " << endl;
	cout << "7. Skriv listan till en fil " << endl;
	cout << "8. L\x84s listan fr\x86n en fil " << endl;
	cout << "9. Avsluta program " << endl;
}

// Felkontroll ifall användaren inte matar in en siffra mellan 1-9 så kommer detta meddelande dyka upp
void InvalidChoice()
{
	cout << "Mata in en siffra mellan 1 och 9 för att g \x99ra ditt val!" << endl;
}

// Metod som tar in inmatningen från användaren och retunerar funktionen som användaren har valt
int MenuChoice()
{
	int menu_choice;

	while ((cout << " Menyval: ") && (!(cin >> menu_choice) || menu_choice < 1 || menu_choice > 9))
	{
		InvalidChoice();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return menu_choice;
}

// Felkontroll ifall användaren inte matar in en siffra mellan 1-3 för sorterings alternativen
void InvalidSortChoice()
{
	cout << "Mata in en siffra mellan 1 och 3 f\x99r att g\x99ra ditt val!" << endl;
}

// Metod för att lägga till personer i listan
void addPerson(Person p, vector<Person> &v)
{
	string firstname, lastname, signature;
	double height = 0.0;

	string vsize = to_string(v.size() + 1);

	if (vsize.size() == 1)
	{
		vsize = to_string(0) + vsize;

	}

	cin.get();

	cout << "Skriv personens namn: ";
	getline(cin, firstname);

	cout << "Skriv personens efternamn: ";
	getline(cin, lastname);

	cout << "Skriv personens signatur (xxxyyy): ";
	cin >> signature;

	// If satser som fyller ut signaturen med "x" ifall man använder mindre än 3 bokstäver
	if (firstname.size() >= 3 && lastname.size() >= 3)
	{
		signature.insert(6, vsize);
	}

	if (firstname.size() == 2 && lastname.size() == 2)
	{
		signature.insert(2, FILL);
		signature.insert(5, FILL);
		signature.insert(6, vsize);
	}

	if (firstname.size() >= 3 && lastname.size() == 2)
	{
		signature.insert(5, FILL);
		signature.insert(6, vsize);
	}

	if (firstname.size() == 2 && lastname.size() >= 3)
	{
		signature.insert(2, FILL);
		signature.insert(6, vsize);
	}

	cout << "Skriv personens l\x84ngd (M.CM): ";
	cin >> height;
	
	// Lägger till personen och dess data till listan
		p.firstname = firstname;
		p.lastname = lastname;
		p.signature = signature;
		p.height = height;
		v.push_back(p);

		cout << "Personen \x84r tillagd" << endl;
}

// Metod för att skriva ut personlistan
void WriteList(vector<Person> &v)
{
	int pers = v.size();
	int number = 1;

	cin.get();

	cout << "      Personlistan!" << endl;
	cout << "Antal personer i listan: " << pers << endl << endl;

	cout << left << setw(7) << "Nr";
	cout << setw(10) << "Sign";
	cout << setw(30) << "Namn";
	cout << right << setw(16) << "L\x84ngd [m]" << endl;

	// For loop för att endast skriva ut 20 personer åt gången
	for (size_t i = 0; i < v.size(); i++)
	{
		if (i + 1 > 9)
		{
			cout << left << setw(2) << i + 1 << setw(5) << ".";
			cout << setw(10) << v[i].signature;
			cout << setw(30) << v[i].firstname + " " + v[i].lastname;
			cout << right << setw(10) << fixed << setprecision(2) << v[i].height << endl;

			if (number % 20 == 0)
			{
				cout << "Tryck p\x86 valfri tangent f\x99r att forts\x84tta!" << endl;
				cin.get();
			}

			number++;
		}

		else
		{
			cout << left << setw(1) << i + 1 << setw(6) << ".";
			cout << setw(10) << v[i].signature;
			cout << setw(30) << v[i].firstname + " " + v[i].lastname;
			cout << right << setw(10) << fixed << setprecision(2) << v[i].height << endl;

			if (number % 20 == 0)
			{
				cout << "Tryck p\x86 valfri tangent f\x99r att forts\x84tta!" << endl;
				cin.get();
			}

			number++;
		}
	}
}

// Metod för att hitta person i listan med hjälp av signaturen
int FindPersonById(string person, vector<Person> &p)
{
	auto it = find_if(begin(p), end(p), [=](Person const &p)
	{
		return (p.signature == person);
	});

	int Id = it - p.begin();

	return Id;
}

// Metod för att hitta person i listan
void FindPerson(vector<Person> &p)
{
	string search;
	int Id = 0, size = p.size();

	cout << "Mata in en signatur att s\x99ka efter i listan: ";
	cin >> search;

	Id = FindPersonById(search, p);

	if (Id > size - 1)
	{
		cout << "Din s\x99kning efter " << "\"" << search << "\"." << "gav inget resultat!" << endl;
	}
	else
	{
		cout << left << setw(6) << "Nr";
		cout << setw(10) << "Sign";
		cout << setw(30) << "Namn";
		cout << right << setw(16) << "L\x84ngd [M]" << endl;

		cout << left << Id + 1 << setw(5) << ".";
		cout << setw(10) << p[Id].signature;
		cout << setw(30) << p[Id].firstname + " " + p[Id].lastname;
		cout << right << setw(10) << fixed << setprecision(2) << p[Id].height << endl;
	}
}

// Metod för att ta bort person från listan med att ange signaturen för personen
void DelPerson(vector<Person> &p)
{
	string search;
	int Id = 0, size = p.size();

	cout << "Mata in en signatur att ta bort fr\x86n listan: ";
	cin >> search;

	Id = FindPersonById(search, p);

	if (Id > size - 1)
	{
		cout << "Din s\x99kning efter " << "\"" << search << "\"" << "gav inget resultat!" << endl;
	}
	else
	{
		p.erase(p.begin() + Id);
		cout << "Raderade personen med den signatur " << "\"" << search << "\"." << " som du angav!" << endl;
	}
}

// Bool metod som jämför efternamnen och sätter de i bokstavsordning
bool CompareName(Person a, Person b)
{
	locale loc;

	transform(a.lastname.begin(), a.lastname.end(), a.lastname.begin(), [loc](char c)
	{return toupper(c); });

	transform(b.lastname.begin(), b.lastname.end(), b.lastname.begin(), [loc](char c)
	{return toupper(c); });

	return (a.lastname < b.lastname);
}

// Bool metod som jämför signaturerna och sorterar efter löpnumret
bool CompareSign(const Person &a, const Person &b)
{
	return a.signature < b.signature;
}

// Bool metod som sorterar efter längden på personerna i listan
bool CompareHeight(const Person &a, const Person &b)
{
	return a.height > b.height;
}

// Metod som behandlar bool metoderna ovan, som skriver ut och sorterar listan efter inmatningen från användaren
void SortList(int s, vector<Person> &p)
{
	switch (s)
	{
	case name:
		cout << "Listan sorterad efter namn!" << endl;
		sort(p.begin(), p.end(), CompareName);
		WriteList(p);
		break;
	case sign:
		cout << "Listan sorterad efter signatur!" << endl;
		sort(p.begin(), p.end(), CompareSign);
		WriteList(p);
		break;
	case height:
		cout << "Listan sorterad efter l\x84ngd!" << endl;
		sort(p.begin(), p.end(), CompareHeight);
		WriteList(p);
		break;
	default:
		InvalidSortChoice();
		break;
	}
}

// Metod för att slumpa personerna i listan
void RandList(vector<Person> &p)
{
	random_shuffle(p.begin(), p.end());
	WriteList(p);
}

// Metod för att spara listan till en fil
void SaveFile(vector<Person> &p)
{
	string filename;

	cout << "Ange ditt filnamn att spara din data till: ";
	cin >> filename;

	ofstream outFile(filename);

	if (outFile.is_open())
	{
		for (size_t i = 0; i < p.size(); i++)
		{
			outFile << p[i].firstname << DELIM << p[i].lastname << DELIM << p[i].signature << DELIM << p[i].height << endl;
		}
	}
	else
	{
		cout << "Kunde inte \x99ppna filen!" << endl;
	}

	outFile.close();

}

 // Metod för att läsa från fil till programmet
void ReadFile(Person &p, vector<Person> &v)
{
	string filename;

	cout << "Ange filnamnet f\x99r att \x99ppna din fil: ";
	cin >> filename;

	ifstream inFile(filename);

	if (!v.empty())
	{
		v.clear();
	}

	if (inFile.is_open())
	{
		string tempstr, tempfname, templname, tempsign, tempheight;

		while (getline(inFile, tempstr))
		{
			stringstream ss(tempstr);

			if (getline(ss,tempfname, '|') && getline(ss,templname, '|') && getline(ss, tempsign, '|') && getline(ss, tempheight))
			{
				p.firstname = tempfname;
				p.lastname = templname;
				p.signature = tempsign;
				p.height = stod(tempheight);

				v.push_back(p);
			}
			else
			{
				cout << "Filens data kunde inte avl\x84sas, kontrollera formatet!" << endl;
			}
		}
	}
	else
	{
		cout << "Kunde inte \x99ppna din fil!" << endl;
	}
	inFile.close();
}