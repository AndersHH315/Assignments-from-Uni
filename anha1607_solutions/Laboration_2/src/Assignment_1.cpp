#include <cmath>
#include <iostream>
using namespace std;

int main() {
	int a2 = 0, b2 = 0, c2 = 0;
	int antal = 0;
	for (int i = 1; i <= 500; i++)
	{
		c2 = i * i;
		for (int j = 1; j <= 500; j++) 
		{
			b2 = j * j;
			for (int k = 1; k < j; k++)
			{
				a2 = k * k;
				if (c2 == a2 + b2)
				{
					if(i == 100 || i == 200 || i == 300 || i == 400 || i == 500)
						cout << "Triangel med hypotenusan " << "{" << i << "," << k << "," << j << "}" << endl;
					antal++;
				}
			}

		}

	}
	cin.get();
	cout << "Ingen sida f\x86r \x94verstiga 500 ";
	cin.get();
	cout << "Antal utfall " << antal;
	cin.get();
	return 0;
}

