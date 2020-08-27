#include <iostream>
#include<string>	

using namespace std;

int main()
{
	// Nycklar som används
	const int ROT13 = 13, ROT7 = 7;

	cout << endl << " Enter a string of text. Press ENTER when finished. " << endl << endl;
	cout << " Text: ";

	string text;
	int count13 = 0, count7 = 0;
	getline(cin, text);

	string encText(text); // text att enkrypta

	for (int i = 0; i < encText.size(); i++) //Metod för att enkrypta strängen
	{
		if (count7 == 5)
		{
			count13 = 0;
			count7 = 0;
		}
		if (count13 < 5)
		{
			encText[i] = encText[i] + ROT13;
			count13++;
		}


		else
		{
			encText[i] = encText[i] + ROT7;
			count7++;
		}

	}


	cout << endl << "Encrypted text is " << endl << encText << endl;
	cin.get();

	count13 = 0;
	count7 = 0;

	for (int i = 0; i < encText.size(); i++) //Metod för att dekrytera strängen
	{
		if (count7 == 5)
		{
			count13 = 0;
			count7 = 0;
		}

		if (count13 < 5)
		{
			encText[i] = encText[i] - ROT13;
			count13++;
		}


		else
		{
			encText[i] = encText[i] - ROT7;
			count7++;
		}

	}

	cout << endl << "Decrypted text is " << endl << encText << endl;
	cin.get();
}

