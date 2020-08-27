#ifndef CONSTANT_H
#define CONSTANT_H
#include <string>

using namespace std;


const char DELIM = '|';
// const v�rde f�r att fylla ut signatur om de �r mindre �n 3 bokst�ver i f�rnamn och efternamn
const string FILL = "x";

// Struktur f�r person objekt
struct Person
{
	string firstname;
	string lastname;
	string signature;
	double height;
};
 
// Enum som anv�nds f�r sortering beroende p� inmatning av anv�ndare
enum Sort
{
	name = 1,
	sign = 2,
	height = 3
};

#endif