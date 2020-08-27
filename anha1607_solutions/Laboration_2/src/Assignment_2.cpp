#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char ch;
	cout << left;
	for (int i = 32; i < 64; i++)
	{
		ch = i;
		if (ch != '\n')
		{
			cout << setw(3) << i << setw(6) << ch;
		}
		else
		{
			cout << setw(3) << i << setw(6);
		}

			for (int j = 1; j < 7; j++)
			{
				ch += 32;
				if (ch != '\n')
				{
					cout << setw(3) << i + (32 * j) << setw(6) << ch;
				}
				else
				{
					cout << setw(3) << i + (32 * j) << setw(6);
				}
			}
			cout << endl;
	}

    cin.get();
	return 0;
}

