#include "Vending.h"
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

Vending::Vending()
{

	balance = 0.00;
	profit = 0.00;
	//cout << "Machine has been created." << endl;
	Drink Default1("Sprite", 2.00, 100);
	Drink Default2("Coke", 2.00, 100);
	Drink Default3("Water", 1.50, 0);

	menu.push_back(Default1);
	menu.push_back(Default2);
	menu.push_back(Default3);
}

void Vending::machineRun()
{
	int choice;
	cout << "ROOT MENU" << endl << endl;
	while (1)
	{
		cout << "Please make a selection" << endl;
		cout << "1 = Consumer mode" << endl;
		cout << "0 = Quit" << endl << endl;
		cout << "User Input: ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			consumerMode();
			break;
		case 0:
			break;
		default:
			cout << "Error, Please check you input" << endl;
			break;
		}

		if (choice == 0)
		{
			cout << "Exiting Run mode" << endl;
			break;
		}
	}
}


//consumer mode starts
void Vending::consumerMode()
{
	int choice;
	cout << "CONSUMER MODE" << endl << endl;
	while (1)
	{
		printBal();
		cout << "What would u like to do? " << endl;
		cout << "1 = Add credit" << endl;
		cout << "2 = Show Drink data" << endl;
		cout << "3 = Purchase" << endl;
		cout << "4 = Refund" << endl;
		cout << "0 = Quit Consumer Mode" << endl << endl;
		cout << "User Input: ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			credit();
			break;
		case 2:
			printDrink(choice);
			break;
		case 3:
			purchase();
			break;
		case 4:
			refund();
			break;
		case 0:
			break;
		default:
			cout << "Error, Please check you input" << endl;
			break;
		}

		if (choice == 0)
		{
			cout << "Exiting consumer mode" << endl << endl;
			break;
		}

	}

	cout << "Thanks for the purchase" << endl << endl;

}
void Vending::refund()
{
	if (balance == 0)
	{
		cout << "Balance is empty" << endl << endl;
	}
	else
		cout << "Refunding $" << setprecision(2) << fixed << balance << "." << endl << endl;
	balance = 0;
}
void Vending::credit()
{
	int choice;

	while (1)
	{
		printBal();
		cout << "What would u like to add? " << endl;
		cout << "1 = Quarter" << endl;
		cout << "2 = Dollar" << endl;
		cout << "3 = 5 Dollars" << endl;
		cout << "0 = Back" << endl;
		cout << "User Input: ";

		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			balance += 0.25;
			break;

		case 2:
			balance += 1.00;
			break;

		case 3:
			balance += 5.00;
			break;

		case 0:
			break;

		default:
			cout << "Error, Please check you input" << endl << endl;
			break;
		}

		if (choice == 0)
		{
			cout << "Exiting credit mode" << endl << endl;
			break;
		}
	}
}

void Vending::purchase()
{
	int choice;
	cout << "PURCHASE MODE" << endl << endl;

	while (1)
	{
		cout << "Please make a selection: " << endl << endl;
		printMenu();
		cout << "0: Back" << endl << endl;
		cout << "User Input: ";
		cin >> choice;
		cout << endl;

		if (choice < menu.size() && choice > 0)
		{
			choice -= 1;

			if (menu[choice].getPrice() > balance)
			{
				cout << "Insufficient Funds. Please make another selection." << endl;

			}
			else if (menu[choice].getCount() == 0)
			{
				cout << "Out of Stock" << endl;
			}
			else
			{
				debt(menu[choice].getPrice());
				profit += menu[choice].getPrice();
				menu[choice].minusCount();
			}

		}
		else if (choice == 0)
		{
			cout << "Exiting Purchase mode..." << endl;
			break;
		}
	}
}

int Vending::getInput(int num)
{
	while (1)
	{
		cin >> input;
		if (input <= num)
			return input;
		else
			cout << "Please check your input" << endl;
	}
}



void Vending::debt(double d)
{

	balance -= d;

}
void Vending::printMenu()
{
	cout << "Current Menu:" << endl << endl;
	for (int i = 0; i < menu.size(); i++)
	{
		cout << i + 1 << ": " << menu[i].getName() << " ";

		for (int j = 0; j < 20; j++)
		{
			if (j > menu[i].getName().length())
				cout << "-";
		}

		if (menu[i].getCount() != 0)
		{
			cout << " $" << setprecision(2) << fixed << menu[i].getPrice() << endl;
		}
		else
			cout << " SOLD OUT" << endl;
	}
}

void Vending::printBal()
{
	cout << "Current Balance: $" << setprecision(2) << fixed << balance << endl;
}


void Vending::printDrink(int n)
{
	cout << "Drink:" << menu[n].getName() << endl;
	cout << "Price: $" << menu[n].getPrice() << endl;
	cout << "Calories:" << menu[n].getCal() << endl;
}

void Vending::printProfit()
{
	cout << profit << endl;
}


