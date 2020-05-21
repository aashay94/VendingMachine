#pragma once

#include <string>
#include <vector>
#include "Drink.h"

class Vending
{
public:

	Vending();
	void debt(double);
	void change();
	void printBal();
	void printMenu();
	int getInput(int);
	void refund();
	//cycle
	void machineRun(); // runs vending
	void consumerMode(); // enters consumer mode
	void credit();

	void printDrink(int);
	void purchase();
	void printProfit();

private:
	vector<Drink> menu;
	vector<int>inv;
	unsigned int input;
	double balance;
	double profit;
	string name;

};

