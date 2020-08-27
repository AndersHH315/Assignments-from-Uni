#include <iostream>
#include <ctime>
using namespace std;

// Antal v�rden som arrayen kommer att behandla
const int numbers = 100;

// Array som f�r antal platser av const int v�rdet "numbers" som �r 100
int numberArray[numbers];


// Metod som genererar random nummer till "numberArray"
int * generateNumbers(int numberArray[])
{
	srand(time(NULL));
	for (int i = 0; i < numbers; i++)
	{
		numberArray[i] = rand() % (101 - 1) + 1;
	}
	return numberArray;
}

// Metod som sorterar v�rdena i arrayen
int * sortNumbersInArray(int specificArray[], int sizeOfArray)
{
	bool swapped;
	//for loop som loopar igenom arrayen och s� l�nge det finns tal som inte ligger i ordningen 1-100
	//N�r ett tal blir "swappad" s� kommer boolen att bli true vilket g�r att for loopen k�rs igen
	//N�r det inte finns n�gra mer tal att sortera s� kommer for loopen att breaka och sedan retuneras den sorterad arrayen
	for (int i = 0; i < sizeOfArray - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < sizeOfArray - i - 1; j++)
		{
			if (specificArray[j] > specificArray[j + 1])
			{
				swap(specificArray[j], specificArray[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
		{
			break;
		}
	}
	return specificArray;
}

// Metod som tar v�rdet fr�n inmatningen och s�ker i arrayen efter det
int binarySearch(int specificArray[], int searchedNumber, int sizeOfArray)
{
	int low = 0;
	int high = sizeOfArray - 1;
	int middle;
	
	// While loop som loopar igenom arrayen s� l�nge talet som anges �r st�rre eller lika med "low" v�rdet
	while (low <= high)
	{
		//V�rde som kommer att anv�ndas f�r att hitta talet som anv�ndaren s�ker efter
		//middle har v�rdet 50 efter f�ljande utr�kning eftersom "sizeOfArray" �r 100
		middle = low + (high - low)/2;

		if (searchedNumber > specificArray[middle])
		{
			low = middle + 1;
		}
		else if(searchedNumber < specificArray[middle])
		{
			high = middle - 1;
		}
		else
		{
			return middle;
		}
	}
}

int main() {
	int testNumber = 0;
	int numberSearch;
	generateNumbers(numberArray);
	sortNumbersInArray(numberArray, numbers);
	cout << "S\x94k efter ett nummer! ";
	cin >> testNumber;

	numberSearch = binarySearch(numberArray, testNumber, numbers);

	//if sats visar f�r anv�ndaren om numret finns eller inte och om det existerar i arrayen s� f�r man reda p� vart i arrayen den ligger
	if (numberSearch != -1)
	{
		cout << "Numret finns p\x86 plats: " << numberSearch << " i Arrayen!" << endl;
	}
	else
	{
		cout << "Numret hittades inte." << endl;
	}
	cin.get();
	cin.get();
	
    return 0;
}

