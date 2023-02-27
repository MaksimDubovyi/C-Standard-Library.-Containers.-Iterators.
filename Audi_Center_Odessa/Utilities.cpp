#include "Utilities.h"
void RussianMessage(const char* str)
{
	char* buf = new char[strlen(str) + 1];
	CharToOemA(str, buf);
	cout << buf;
	delete[]buf;
}
void Menu(char ptr[][100], int row)
{
	for (int i = 0; i < row; i++)
	{
		RussianMessage(ptr[i]);
		cout << endl;
	}
}
del::del(string  m, int y)
{
	model = m;
	yers = y;
}

bool del:: operator()(Car& a)
{
	return (a.GetModel() == this->model && a.GetYear() == this->yers);
}

Find_M::Find_M(string  m)
{
	model = m;
}
bool Find_M::operator()(Car& a)
{
	return (a.GetModel() == this->model);
}

Find_Y::Find_Y(int  y)
{
	year = y;
}
bool Find_Y::operator()(Car& a)
{
	return (a.GetYear() == year);
}

Find_E::Find_E(double  m)
{
	a = m;
}
bool Find_E::operator()(Car& a)
{
	return (a.GetEngine_volume() == this->a);
}

Find_P::Find_P(double  m)
{
	price = m;
}
bool Find_P::operator()(Car& a)
{
	return (a.GetPrice() == this->price);
}

Find_M_Y::Find_M_Y(string  m, int y)
{
	model = m;
	yers = y;
}
bool Find_M_Y::operator()(Car& a)
{
	return (a.GetModel() == model && a.GetYear() == yers);
}

bool Sort_M(Car a, Car b)
{
	return a.GetModel() < b.GetModel();
}
bool Sort_Y(Car a, Car b)
{
	return a.GetYear() < b.GetYear();
}
bool Sort_E(Car a, Car b)
{
	return a.GetEngine_volume() < b.GetEngine_volume();
}
bool Sort_P(Car a, Car b)
{
	return a.GetPrice() < b.GetPrice();
}