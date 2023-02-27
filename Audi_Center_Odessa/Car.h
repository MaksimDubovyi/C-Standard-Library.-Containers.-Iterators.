#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;

class Car
{
	string model;
	int year;
	double engine_volume;
	double price;
public:
	 Car()
	{
		  model="AUDI";
		  year=0;
		  engine_volume=0;
		  price=0;
	}
	 Car(string m,int y, double e, double p);
	 
	 void SetModel(string n)
	 {
		 model = n;
	 }
	 string GetModel()
	 {
		 return model;
	 }
	 int GetGetModelSize()
	 {
		 return model.size();
	 }
	 void SetYear(int m)
	 {
		 year = m;
	 }
	 int GetYear()
	 {
		 return year;
	 }

	 void SetEngine_volume(double g)
	 {
		 engine_volume = g;
	 }
	 double GetEngine_volume()
	 {
		 return engine_volume;
	 }

	 void SetPrice(double g)
	 {
		 price = g;
	 }
	 double GetPrice()
	 {
		 return price;
	 }


	 virtual void Input();
	 void Print();
	 friend ostream& operator << (ostream& cout, const Car& );

};