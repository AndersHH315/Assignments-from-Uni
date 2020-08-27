#include <iostream>
#include <iomanip>
#include <regex>
#include <string>
#include <cctype>

using namespace std;

string const inText1 = "Foten �r en kroppsdel som f�rekommer mycket i v�ra uttryck.";
string const inText2 = "P� st�ende fot betyder omedelbart, utan f�rberedelse.";
string const inText3 = "F�rs�tta p� fri fot betyder att ge n�gon friheten.";
string const inText4 = "S�tta foten i munnen betyder att g�ra bort sig.";
string const inText5 = "F� om bakfoten betyder att missuppfatta n�got.";
string const inText6 = "Skrapa med foten betyder att visa sig underd�nig eller �dmjuk.";
string const inText7 = "Stryka p� foten betyder att tvingas ge upp.";
string const inText8 = "Leva p� stor fot betyder att f�ra ett dyrbart eller sl�saktigt leverne.";
string const inText9 = "Varf�r fick du foten???";



string checktext(string text) // Metod f�r att skapa ny rad vid punkt samt byter ut "fot" mot "hand"
{
	transform(text.begin(), text.end(), text.begin(), ::tolower);
	text.replace(text.find("fot"), 3, "hand");
	text[0] = toupper(text[0]);

	string::size_type dot = text.find('.');

	if (dot != string::npos)
	{
		text.insert(dot + 1, "\n");
	}
	return text;
}

int main() {
	locale swedish("swedish");
	locale::global(swedish);

	string text1(inText1), text2(inText2), text3(inText3), text4(inText4), text5(inText5), text6(inText6), text7(inText7), text8(inText8), text9(inText9);

	string alltext = checktext(text1) + checktext(text2) + checktext(text3) + checktext(text4) + checktext(text5) + checktext(text6) + checktext(text7) + checktext(text8) + checktext(text9);

	cout << alltext << endl;

	cin.get();
	return 0;
}

