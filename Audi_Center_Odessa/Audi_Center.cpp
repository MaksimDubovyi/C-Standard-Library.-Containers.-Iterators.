#include "Audi_Center.h"
#include <vector>
#include <iterator>
#include <algorithm>
#include<fstream>
#include "Utilities.h"
using namespace std;

int Audi_Center::GetCount()
{
	return car.size();
}

void Audi_Center::Push_back()
{
	Car temp;
	temp.Input();
	car.push_back(temp);
}

void Audi_Center::Print()
{
	//system("cls");
	cout << "___________________________________________AUDI_CENTER_ODESS______________________________________\n\n";
	ostream_iterator<Car> out(cout);
	copy(car.begin(), car.end(), out);
}

void Audi_Center::DeleteCar()
{
	string m;
	int y;
	cout << " Enter model -  ";
	cin >> m;
	cout << " Enter year -  ";
	cin >> y;
	vector<Car>::iterator it;
	
	it = remove_if(car.begin(), car.end(), del(m, y));
	car.erase(it, car.end());
}
class Edit
{
	string model;
	int year;
public:

	Edit(string  m,int y)
	{
		model = m;
		year = y;
	}
	bool  operator()(Car a)
	{
		if (a.GetModel()==model&& a.GetYear()== year)
		{
			return	true;
		}
		return false;
	}
};
void Audi_Center::EditCar()
{
	string str;
	int y;
	cout << "Enter the model and year of the vehicle to be replaced - ";
	cin >> str>>y;
	cout << "Enter new data - ";
	Car temp;
	temp.Input();
	replace_if(car.begin(), car.end(), Edit(str,y), temp);
	
}

void Audi_Center::FindCar()
{
	system("cls");
	int choice;
	cout << "               Choose a criterion\n";
	cout << "Model - 1\nYear - 2\nEngine volume - 3\nPrice - 4\nModel and Year - 5\n";
	cin >> choice;
	string m;
	int y;
	double e;
	vector<Car>::iterator it;
	it = car.begin();
	if (choice == 1)
	{
		cout << " Enter Model -  ";
		cin >> m;
		do
		{
			it = find_if(it, car.end(), Find_M(m));
			if (it == car.end())
			{
				break;
			}
			else
			{
				cout << *it;
				it++;
			}

		} while (true);
	}
	else if (choice == 2)
	{
		cout << " Enter Year  - 2";
		cin >> y;
		do
		{
			it = find_if(it, car.end(), Find_Y(y));
			if (it == car.end())
			{
				break;
			}
			else
			{
				cout << *it;
				it++;
			}

		} while (true);
	}
	else if (choice == 3)
	{
		cout << " Enter Engine volume  - ";
		cin >> e;
		do
		{
			it = find_if(it, car.end(), Find_E(e));
			if (it == car.end())
			{
				break;
			}
			else
			{
				cout << *it;
				it++;
			}

		} while (true);
	}
	else if (choice == 4)
	{
		cout << " Enter Price  - ";
		cin >> e;
		do
		{
			it = find_if(it, car.end(), Find_P(e));
			if (it == car.end())
			{
				break;
			}
			else
			{
				cout << *it;
				it++;
			}

		} while (true);
	}
	else if (choice == 5)
	{
		cout << " Enter Model and Year - ";
		cin >> m>>e;
		do
		{
			it = find_if(it, car.end(), Find_M_Y(m,e));
			if (it == car.end())
			{
				break;
			}
			else
			{
				cout << *it;
				it++;
			}

		} while (true);
	}
	
}

void Audi_Center::Sort()
{
	system("cls");
	int choice;
	cout << "               Select a sorting criterion\n";
	cout << "Model - 1\nYear - 2\nEngine volume - 3\nPrice - 4\n";
	cin >> choice;
	sort(car.begin(), car.end(), Sort_M);
	if (choice == 1)
	{
		sort(car.begin(), car.end(), Sort_M);
	}
	else if (choice == 2)
	{
		sort(car.begin(), car.end(), Sort_Y);
	}
	else if (choice == 3)
	{
		sort(car.begin(), car.end(), Sort_E);
	}
	else if (choice == 4)
	{
		sort(car.begin(), car.end(), Sort_P);
	}
}

void Audi_Center::Save()
{
	char Model[30];
	memset(Model, 0, 30);
	int s = car.size();
	ofstream out("Audi.txt", ios::binary);
	if (!out.is_open())
	{
		cout << "Error!\n";
		return;
	}
	out.write((char*)&s, sizeof(s));
	vector<Car>::iterator it;
	
	int i = 0,y;
	double p,e;
	for (it = car.begin(); it != car.end(); it++)
	{
		int sise_m = car[i].GetGetModelSize();
		y = car[i].GetYear();
		e = car[i].GetEngine_volume();
		p = car[i].GetPrice();
		out.write((char*)&sise_m, sizeof(sise_m));
		out.write(car[i].GetModel().c_str(), sise_m+1);

		out.write((char*)&y, sizeof(y));
		out.write((char*)&e, sizeof(e));
		out.write((char*)&p, sizeof(p));

		i++;
	}
	out.close();
}

void Audi_Center::Load()
{
	ifstream in("Audi.txt", ios::binary);
	if (!in.is_open()) 
	{
		cout << "Error!\n";
		return;
	}
	int size;
	in.read((char*)&size, sizeof(size));
	Car temp;
	string m;
	char str[10];
	memset(str, 0, 10);
	int y,x;
	double e,p;
	for (int i = 0; i < size; i++)
	{
		
		in.read((char*)&x, sizeof(x));
		in.read(str, x+1);

		in.read((char*)&y, sizeof(y));
		in.read((char*)&e, sizeof(e));
		in.read((char*)&p, sizeof(p));
		temp.SetModel(str);
		temp.SetYear(y);
		temp.SetEngine_volume(e);
		temp.SetPrice(p);

		car.push_back(temp);
		memset(str, 0, 10);
	}
	in.close();
}

