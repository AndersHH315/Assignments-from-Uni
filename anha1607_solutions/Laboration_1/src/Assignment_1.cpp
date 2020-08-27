#include <iostream>
using namespace std;

const double gascost = 560.8;

double fuelConsumptionPer10Km(double previousKm, double currentKm, double liters) // Metod som räknar ut hur mycket bensin det drar per mil
{
	double calculate, result;

	calculate = (currentKm - previousKm) / 10;
	result = liters / calculate;
	return result;
}

double costCalculationPer10Km(double previousKm, double currentKm) // Metod som räknar ut kostnaden per mil
{
	double calculate, result;

	calculate = (currentKm - previousKm) / 10;
	result = gascost / calculate;
	return result;
}

int main() {

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	double fuelConsumption, costCalculation, previousKm, currentKm, liters;
    cout << "Bensinf\x99rbrukning och kostnad!" << endl;

	cout << "Ange m\x84tarst\x84llning 1 [km]: ";
	cin >> previousKm;
	cout << "Ange m\x84tarst\x84llning 2 [km]: ";
	cin >> currentKm;
	cout << "Hur mycket tankade du [l] : ";
	cin >> liters;

	cout << "" << endl;

	fuelConsumption = fuelConsumptionPer10Km(previousKm, currentKm, liters);
	costCalculation = costCalculationPer10Km(previousKm, currentKm);
	cout << "Bensinf\x99rbrukning  [l/mil]: " << fuelConsumption << endl;
	cout << "Milkostnaden      [kr/mil]: " << costCalculation << endl;

	cin.get();
	cin.get();
    return 0;
}

