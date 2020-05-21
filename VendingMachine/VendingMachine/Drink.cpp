#include "Drink.h"
#include <string>

using namespace std;

Drink::Drink(string n, double p, int c)
{
	name = n;
	price = p;
	cal = c;
	count = 10;
}
string Drink::getName()
{
	return name;
}

double Drink::getPrice()
{
	return price;
}

int Drink::getCal()
{
	return cal;
}

void Drink::setName(string n)
{
	name = n;

}

void Drink::setPrice(double p)
{
	price = p;

}

int Drink::getCount()
{
	return count;
}

void Drink::setCount(int x)
{
	count = x;
}
void Drink::minusCount()
{
	count--;
}

void Drink::setCal(int c)
{
	cal = c;
}