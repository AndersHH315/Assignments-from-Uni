#include <iostream>
#include <istream>
#include <ctime>
#include <stdio.h>
using namespace std;

// const v�rdet som arrayens kommer att anv�nda sig av
const int totalNumbers = 600;

// Array som f�r 600 platser av "totalNumbers"
int numbers[totalNumbers];

// Array som behandlar v�rden fr�n "numbers" arrayen
int copyNumbers[totalNumbers];

// Metod f�r att generera random nummer till "copyNumbers" arrayen
int * generateNumbers(int numbers[])
{

	srand(time(NULL));
	for (int i = 0; i < totalNumbers; i++)
	{
		numbers[i] = rand() % (101-1) + 1;
		copyNumbers[i] = numbers[i];
	}
	return copyNumbers;
}

// Metod f�r att ber�kna medelv�rdet i arrayen
double calculateAverageNumber(int copyNumbers[])
{
	int totalSpecificNumber = 0;
	
	for (int i = 0; i < totalNumbers; i++)
	{
		totalSpecificNumber += copyNumbers[i];

	}

	double average = totalSpecificNumber / totalNumbers;
	return average;
}

//int checkMinAndMaxValueInArray(int copyNumbers[])
//{
//	int max = copyNumbers[0], min = copyNumbers[0];
//	for (int i = 0; i < totalNumbers; i++)
//	{
//		if (copyNumbers[i] > max)
//		{
//			max = copyNumbers[i];
//		}
//		if (copyNumbers[i] < min)
//		{
//			min = copyNumbers[i];
//		}
//
//		return max, min;
//	}
//
//}

// Metod f�r att kolla det h�gsta v�rdet i arrayen
int checkMaxValueInArray(int copyNumbers[])
{
	int max = copyNumbers[0];
	for (int i = 0; i < totalNumbers; i++)
	{
		if (copyNumbers[i] > max)
		{
			max = copyNumbers[i];
		}
	}
	return max;
}

// Metod f�r att kolla det minsta v�rdet i arrayen
int checkMinValueInArray(int copyNumbers[])
{
	int min = copyNumbers[0];
	for (int i = 0; i < totalNumbers; i++)
	{
		if (copyNumbers[i] < min)
		{
			min = copyNumbers[i];
		}
	}
	return min;
}

// Metod f�r att r�kna specifikt nummer som anv�nder sj�lv matar in
int countSpecificNumber(int copyNumbers[], int number)
{
	int count = 0;
	for (int i = 0; i < totalNumbers; i++)
	{
		if (number == copyNumbers[i])
		{
			count ++;
		}
	}
	return count;
}

// Metod som r�knar ut det mest f�rekommande nummer i arrayen
int mostCommonNumberInArray(int copyNumbers[])
{
	int count, totalCount = 0, mostCommonNumber = 0;

	for (int i = 0; i < totalNumbers; i++)
	{
		count = 0;
		for (int j = 0; j < totalNumbers; j++)
		{
			if (copyNumbers[i] == copyNumbers[j])
			{
				count++;
			}

			if (count > totalCount)
			{
				totalCount = count;
				mostCommonNumber = copyNumbers[i];
			}
		}
	}

	return mostCommonNumber;
}


// Bubblesort Metod f�r att sortera numren i arrayen
int * sortNumbersInArray(int copyNumbers[])
{
	bool swapped;
	for (int i = 0; i < totalNumbers - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < totalNumbers - i - 1; j++)
		{
			if (copyNumbers[j] > copyNumbers[j + 1])
			{
				swap(copyNumbers[j], copyNumbers[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
		{
			break;
		}
	}
	return copyNumbers;
}

// Metod som Bubblesort metoden anv�nder sig av f�r att swapa numren
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int main() {

	int specificNumber = 0;
	generateNumbers(numbers);
	double average = calculateAverageNumber(copyNumbers);

	//Text som beskriver f�r anv�ndaren vad som h�nder och vad anv�ndaren ska g�ra
	cout << "I denna array f\x94rekommer det 600 olika siffror som \x84r mellan 1-100 och nedanf\x94r g\x86r det att se information om arrayen!" << endl;
	cout << "Tryck Enter f\x94r att se st\x94rsta, minsta v\x84rdet och medelv\x84rdet!" << endl;
	cin.get();
	//Text som visar minsta, h�gsta och medelv�rdet i arrayen
	cout << "Max v\x84rdet: " << checkMaxValueInArray(copyNumbers) << endl;
	cout << "Min v\x84rdet: " << checkMinValueInArray(copyNumbers) << endl;
	cout << "Medelv\x84rdet: " << average << endl;

	cout << "Tryck Enter f\x94r att forts\x84tta!" << endl;
	cin.get();

	//Inmatning fr�n anv�ndaren f�r att kolla hur ofta talet f�rekommer i arrayen
	cout << "Ange nummer som ska r\x84knas: ";
	cin >> specificNumber;

	cin.get();

	//Visar hur m�nga g�nger talet f�rekommer
	cout << "Talet f\x94rekommer: " << countSpecificNumber(copyNumbers, specificNumber) << " g\x86nger" << endl;

	cin.get();

	//Visar det talet som f�rekommer mest
	cout << "Talet som f\x94rekommer mest \x84r nummer: " << mostCommonNumberInArray(copyNumbers) << endl;
	cout << "Tryck Enter f\x94r att sortera arrayen i nummer ordning!" << endl;
	cin.get();

	//Metod och for loop som skriver ut numren i ordning och varje typ av tal per rad
	sortNumbersInArray(copyNumbers);
	for (int i = 0; i < totalNumbers; i++)
	{
		int temp = copyNumbers[i];

		cout << copyNumbers[i];
		if (copyNumbers[i + 1] != temp)
		{
			cout << endl;
		}
	}

	cin.get();
    return 0;
}
