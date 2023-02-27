#include "Car.h"

Car::Car(string m, int y, double e, double p)
{
	model = m;
	year = y;
	engine_volume = e;
	price = p;
}

void Car::Input()
{
	cout << " Enter model -  ";
	cin >> model;
	cout << " Enter year -  ";
	cin >> year;
	cout << " Enter engine_volume -  ";
	cin >> engine_volume;
	cout << " Enter price -  ";
	cin >> price;
	cout << endl;
}

void Car::Print()
{
	cout << "\nMODEL - " << model << "     Year - " << year << "     Engine volume - " << engine_volume << " L" << "     Price - " << price << "$\n";
}

ostream& operator<<(ostream& cout, const Car& c)
{
	cout << "\nMODEL - " << c.model << "     Year - " << c.year << "     Engine volume - " << c.engine_volume << " L" << "     Price - " << c.price << "$\n";
	
	return cout;
}