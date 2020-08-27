#ifndef CONSTANT_H
#define CONSTANT_H
#include <string>

using namespace std;


const char DELIM = '|';
// const värde för att fylla ut signatur om de är mindre än 3 bokstäver i förnamn och efternamn
const string FILL = "x";

// Struktur för person objekt
struct Person
{
	string firstname;
	string lastname;
	string signature;
	double height;
};
 
// Enum som används för sortering beroende på inmatning av användare
enum Sort
{
	name = 1,
	sign = 2,
	height = 3
};

#endif