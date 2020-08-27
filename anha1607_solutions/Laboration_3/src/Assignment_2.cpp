#include <sstream>
#include <iostream>
#include <string>
using namespace std;

int main() {

	string nameA, nameB, nameC, lastname1, lastname2, lastname3, firstname1, firstname2, firstname3, firstname, secondname, thirdname, n1, n2, n3;

	cout << "Skriv in ett f\x94rnamn <mellanslag> efternamn:" << endl;
	getline(cin, firstname1, ' ');
	getline(cin, lastname1);
	nameA = firstname1 + " " + lastname1;
	n1 = nameA;
	for (int i = 0; i < (int)n1.length(); i++)
	{
		n1[i] = toupper(n1[i]);
	
	}
	firstname = lastname1 + " " + firstname1;

	cout << "Skriv in ett andra f\x94rnamn <mellanslag> efternamn:" << endl;
	getline(cin, firstname2, ' ');
	getline(cin, lastname2);
	nameB = firstname2 + " " + lastname2;
	n2 = nameB;
	for (int i = 0; i < (int)n2.length(); i++)
	{
		n2[i] = toupper(n2[i]);
	}
	secondname = lastname2 + " " + firstname2;

	cout << "Skriv in ett tredje f\x94rnamn <mellanslag> efternamn:" << endl;
	getline(cin, firstname3, ' ');
	getline(cin, lastname3);
	nameC = firstname3 + " " + lastname3;
	n3 = nameC;
	for (int i = 0; i < (int)n3.length(); i++)
	{
		n3[i] = toupper(n3[i]);
	}
	thirdname = lastname3 + " " + firstname3;

	if (firstname > secondname && secondname > thirdname)
	{
		cout << nameC << endl << nameB << endl << nameA << endl;
	}
	else if (firstname > thirdname && thirdname > secondname)
	{
		cout << nameB << endl << nameC << endl << nameA << endl;
	}
	else if (secondname > firstname && firstname > thirdname)
	{
		cout << nameC  << endl << nameA  << endl << nameB  << endl;
	}
	else if (secondname > thirdname && thirdname > firstname)
	{
		cout << nameA << endl << nameC  << endl << nameB  << endl;
	}
	else if (thirdname > firstname && firstname > secondname)
	{
		cout << nameB  << endl << nameA  << endl << nameC  << endl;
	}
	else
		cout << nameA  << endl << nameB  << endl << nameC  << endl;

	cin.get();
}


