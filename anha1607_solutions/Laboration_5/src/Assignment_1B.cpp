#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

//Const int värde som anger antal platser för vectorerna som kommer att användas som är 600
const int totalNumbers = 600;
//Vector som används för att skapa alla talen som sedan ska kopieras till "copyNumbers" vectorn
vector<int> numbers(totalNumbers);
//Vector som hanterar nummer som kopieras från "numbers" som blir random generarade av "generateNumbers" metoden
vector<int> copyNumbers(totalNumbers);

//Metod som genererar random nummers till vectorn
vector<int> generateNumbers(vector<int> numbers)
{
	srand(time(NULL));
	for (int i = 0; i < totalNumbers; i++)
	{
		numbers[i] = rand() % (101 - 1) + 1;
		copyNumbers[i] = numbers[i];
	}
	return copyNumbers;
}

//Metod som räknar ut medelvärdet i vectorn
double calculateAverageNumber(vector<int> copyNumbers)
{
	int totalSpecificNumber = 0;

	for (int i = 0; i < totalNumbers; i++)
	{
		totalSpecificNumber += copyNumbers[i];
	}

	double average = totalSpecificNumber / totalNumbers;
	return average;
}

//int checkMaxValueInVector(vector<int> copyNumbers)
//{
//	int max = copyNumbers[0];
//
//	for (int i = 0; i < totalNumbers; i++)
//	{
//		if (copyNumbers[i] > max)
//		{
//			max = copyNumbers[i];
//		}
//	}
//	return max;
//}

//int checkMinValueInVector(vector<int> copyNumbers)
//{
//	int min = copyNumbers[0];
//
//	for (int i = 0; i < totalNumbers; i++)
//	{
//		if (copyNumbers[i] < min)
//		{
//			min = copyNumbers[i];
//		}
//	}
//	return min;
//}


//int countSpecificNumber(vector<int> copyNumbers, int number)
//{
//	int count = 0;
//
//	for (int i = 0; i < totalNumbers; i++)
//	{
//		if (number == copyNumbers[i])
//		{
//			count++;
//		}
//	}
//	return count;
//}

//Metod för att kolla vilket värde som förekommer mest i vectorn
int mostCommonNumberInVector(vector<int> copyNumbers)
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

int main() {
    
	int specificNumber = 0;
	generateNumbers(numbers);

	//Metod som räknar ut medelvärdet i vectorn
	double average = calculateAverageNumber(copyNumbers);
	cout << "I denna vector f\x94rekommer det 600 olika siffror som \x84r mellan 1-100 och nedanf\x94r g\x86r det att se information om vectorn!" << endl;
	cout << "Tryck Enter f\x94r att se st\x94rsta, minsta v\x84rdet och medelv\x84rdet!" << endl;
	cin.get();

	//Metoder som kollar minsta och högsta värdet i vectorn
	int min = *(min_element(copyNumbers.begin(), copyNumbers.end()));
	int max = *(max_element(copyNumbers.begin(), copyNumbers.end()));

	cout << "Max v\x84rdet: " << min << endl;
	cout << "Min v\x84rdet: " << max << endl;
	cout << "Medelv\x84rdet: " << average << endl;

	cout << "Tryck Enter f\x94r att forts\x84tta!" << endl;
	cin.get();

	int counter = 0, number = 0;
	cout << "Ange nummer som ska r\x84knas: ";
	cin >> specificNumber;

	//Metod för att räkna hur ofta ett tal förekommer
	counter = count(copyNumbers.begin(), copyNumbers.end(), number);
	cout << "Talet f\x94rekommer: " << counter << " g\x86nger" << endl;

	cin.get();

	cout << "Talet som f\x94rekommer mest \x84r nummer: " << mostCommonNumberInVector(copyNumbers) << endl;

	cout << "Tryck Enter f\x94r att sortera arrayen i nummer ordning!" << endl;
	cin.get();

	//Metod för att sortera vectorn till 1-100
	sort(copyNumbers.begin(), copyNumbers.end());
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

