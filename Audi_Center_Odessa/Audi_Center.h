#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Car.h"
using namespace std;
class Audi_Center
{
	vector<Car> car;
public:


	int GetCount();

	void Push_back();
	void Print();

	void DeleteCar();
	void EditCar();
	void FindCar();
	void Sort();

	void Save();
	void Load();

};
