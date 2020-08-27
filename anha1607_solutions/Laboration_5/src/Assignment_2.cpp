#include <iostream>
#include <ctime>
using namespace std;

// Antal värden som arrayen kommer att behandla
const int numbers = 100;

// Array som får antal platser av const int värdet "numbers" som är 100
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

// Metod som sorterar värdena i arrayen
int * sortNumbersInArray(int specificArray[], int sizeOfArray)
{
	bool swapped;
	//for loop som loopar igenom arrayen och så länge det finns tal som inte ligger i ordningen 1-100
	//När ett tal blir "swappad" så kommer boolen att bli true vilket gör att for loopen körs igen
	//När det inte finns några mer tal att sortera så kommer for loopen att breaka och sedan retuneras den sorterad arrayen
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

// Metod som tar värdet från inmatningen och söker i arrayen efter det
int binarySearch(int specificArray[], int searchedNumber, int sizeOfArray)
{
	int low = 0;
	int high = sizeOfArray - 1;
	int middle;
	
	// While loop som loopar igenom arrayen så länge talet som anges är större eller lika med "low" värdet
	while (low <= high)
	{
		//Värde som kommer att användas för att hitta talet som användaren söker efter
		//middle har värdet 50 efter följande uträkning eftersom "sizeOfArray" är 100
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

	//if sats visar för användaren om numret finns eller inte och om det existerar i arrayen så får man reda på vart i arrayen den ligger
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

