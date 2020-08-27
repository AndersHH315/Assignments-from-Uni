#include <iostream>

using namespace std; // Allows the use of "std" without using the "std::prefix"

int main() {
	// Variables and constants
	int radius, circumference, area;
	const float PI = 3.14; // Can't use "," when refering to decimals because ur trying to declare 2 numbers to one variable // syntaxfel
	// Input the circles radius
	cout << "Assign the circle's radius: ";
	cin >> radius;
	// Algorithm to calculate circumference (2*PI*r) and area (PI*r*r)
	circumference = PI * radius * radius;
	area = 2 * PI * radius; // You have to type "PI" to use the const float PI, as c++ is case sensetive // syntaxfel
	// Output of results
	cout << "A circle with the radius " << radius << " has the circumference "<< circumference << " and area " << area << endl;
	// Validate x
	cout << "Validate x by typing in a number: "; // Added a indication for the user to know what to type in next
	int x;
	cin >> x;
	if (x == 100) // If you use a single "=" it means you are giving the x variable the number 100 instead of checking if the variable equal to 100 from the input // logiskt fel
		cout << "x is equal to 100" << endl;
	if (x > 0)
	cout << "x is larger than zero" << endl;
	switch (x) { // Missing breakpoints which will make more then one case to happend // logisktfel
	case 5: cout << "x is equal to 5 " << endl;
		break;
	case 10: cout << "x is equal to 10" << endl;
		break;
	default: cout << "x is neither 5 nor 10" << endl;
		break;
	}
	cin.get();
	cin.get();
	} // End main
