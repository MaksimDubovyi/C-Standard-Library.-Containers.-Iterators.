#include <iostream>
#include <conio.h>
#include "Audi_Center.h"
#include "Car.h"
#include "Utilities.h"

using namespace std;

int main()
{

	Audi_Center a;
	a.Load();
	char menu[][100] = {
		 "___________________________________________AUDI_CENTER_ODESS______________________________________",
			"1. Add Car",
			"2. Print ",
			"3. Find",
			"4. Edit",
			"5. Delete",
			"6. Sort",
			"7. Выход" };
	while (true)
	{
	system("cls");
	Menu(menu, 8);
	int choice = _getch();
	switch (choice)
	{
	case '1':
		a.Push_back();
		break;
	case '2':
		a.Print();
		system("pause");
		break;
	case '3':
		a.FindCar();
		system("pause");
		break;
	case '4':
		a.EditCar();
		break;
	case '5':
		a.DeleteCar();
		break;
	case '6':
		a.Sort();
		break;

	case '7':
		a.Save();
		return 0;
	}
	}

	return 0;
}
	