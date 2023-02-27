#pragma once
#include <vector>
#include <iterator>
#include<fstream>
#include "Car.h"
using namespace std;
void Menu(char ptr[][100], int row);
void RussianMessage(const char* str);

class del
{
	string model;
	int yers;
public:
	del(string  m, int y);
	bool operator()(Car& a);
};

class Find_M
{
	string model;
public:
	Find_M(string  m);
	bool operator()(Car& a);
};

class Find_Y
{
	int year;
public:
	Find_Y(int  y);
	bool operator()(Car& a);
};

class Find_E
{
	double a;
public:
	Find_E(double  m);
	bool operator()(Car& a);
};

class Find_P
{
	double price;
public:
	Find_P(double  m);
	bool operator()(Car& a);
};

class Find_M_Y
{
	string model;
	int yers;
public:
	Find_M_Y(string  m, int y);
	bool operator()(Car& a);
};

bool Sort_M(Car a, Car b);
bool Sort_Y(Car a, Car b);
bool Sort_E(Car a, Car b);
bool Sort_P(Car a, Car b);