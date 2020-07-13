#include <iostream>
#include "animal.h"
#include "zoo.h"
#include "sealion.h"
#include "tiger.h"
#include "bear.h"

using namespace std;

int main()
{
	Zoo zoo;
	int choice = 0;

	cout << "Welcome to Zoo Tycoon!" << endl;
	zoo.print_bank();

	while (choice == 0)
	{
		zoo.bankrupt();

		cout << "What would you like to do?" << endl;
		cout << "(1) Buy new animal(s)" << endl;
		cout << "(2) Feed animals and continue" << endl;
		cout << "(3) See what happened last month again" << endl;
		cout << "(4) Quit the game" << endl;
		cin >> choice;

		if (choice == 1)
		{
			zoo.buy();
		}

		else if (choice == 2)
		{
			zoo.month_events();
		}

		else if (choice == 3)
		{
			cout << "MONTH STFFS" << endl;
		}

		else if (choice == 4)
		{
			exit(0);
		}

		else
		{
			cout << "Invalid choice. Try again:" << endl;
			choice = 0;
		}

		choice = 0;
	}
}