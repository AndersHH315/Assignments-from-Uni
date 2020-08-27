#include <iostream>

using namespace std;

int main() {
	char choice;

	do 
	{
		int palindrome = 0, reverse = 0, number = 0, key = 0;

		do
		{
			cout << "Skriv ett femsiffrigt nummer f\x94r att kolla om de \x84r en palindrome: ";
			cin >> palindrome;

		} while (palindrome < 9999 || palindrome > 100000);


		key = palindrome;

		for (int i = 1; palindrome != 0; i++)
		{
			number = palindrome % 10;
			palindrome = palindrome / 10;
			reverse = number + (reverse * 10);
		}
			cout << "De omv\x84nda numret \x84r: " << reverse << endl;

		if (reverse == key)
		{
			cout << key << " \x84r ett palindrome!" << endl << endl;
		}
		else
		{
			cout << key << " \x84r inte ett palindrome!" << endl << endl;
		}

		do
		{
			cout << "Vill du skriva in ett till nummer f\x94r att kolla om de \x84r en palindrome? (j/n): ";
			cin >> choice;
			choice = toupper(choice);
		} while (!(choice == 'J' || choice == 'N'));
	} while (choice == 'J');

	return(0);
}