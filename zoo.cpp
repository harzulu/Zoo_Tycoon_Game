#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cassert>
#include "zoo.h"
#include "sealion.h"
#include "tiger.h"
#include "bear.h"
#include "animal.h"

using namespace std;

Zoo::Zoo()
{
	bank = 100000;
	lions = new SeaLion[15];
	tigers = new Tiger[15];
	bears = new Bear[15];
	lion_num = 0;
	tiger_num = 0;
	bear_num = 0;
	bought_animals = false;
	food = 80;
	month_cost = 0;
	revenue = 0;
}

void Zoo::print_bank()
{
	cout << "You have $" << bank << " in the bank." << endl;
	cout << " " << endl;
}

void Zoo::buy()
{
	int animal = 0;
	int num_of_animal;

	if (bought_animals == false)
	{
		while (animal == 0)
		{
			cout << "What kind of animal would you like to buy?" << endl;
			cout << "(1) Sea Lion" << endl;
			cout << "(2) Tiger" << endl;
			cout << "(3) Black Bear" << endl;
			cout << "(4) None " << endl;
			cin >> animal;

			while (animal == 1)
			{
				cout << "How many Sea Lions would you like to buy 1 or 2? " << endl;
				cin >> num_of_animal;

				if (num_of_animal == 1)
				{
					if (bank - 800 > 0)
					{
						bank = bank - 800;
						lions[lion_num].new_lion();
						lion_num++;
						print_bank();
						animal = 9;
						bought_animals = true;
					}
					else
					{
						cout << "You have insufficiant funds..." << endl;
						animal = 0;
					}
				}

				else if (num_of_animal == 2)
				{
					if (bank - 1600 > 0)
					{
						bank = bank - 1600;
						lions[lion_num].new_lion();
						lion_num++;
						lions[lion_num].new_lion();
						lion_num++;
						print_bank();
						animal = 9;
						bought_animals = true;
					}
					else
					{
						cout << "You have insufficiant funds..." << endl;
						animal = 0;
					}
				}

				else
				{
					cout << "You can only buy up to 2. Try again: " << endl;
					animal = 1;
				}

			}
			while (animal == 2)
			{
				cout << "How many Tigers would you like to buy 1 or 2? " << endl;
				cin >> num_of_animal;

				if (num_of_animal == 1)
				{
					if (bank - 15000 > 0)
					{
						bank = bank - 15000;
						tigers[tiger_num].new_tiger();
						tiger_num++;
						print_bank();
						animal = 9;
						bought_animals = true;
					}
					else
					{
						cout << "You have insufficiant funds..." << endl;
						animal = 0;
					}
				}

				else if (num_of_animal == 2)
				{
					if (bank - 30000 > 0)
					{
						bank = bank - 30000;
						tigers[tiger_num].new_tiger();
						tiger_num++;
						tigers[tiger_num].new_tiger();
						tiger_num++;
						print_bank();
						animal = 9;
						bought_animals = true;
					}
					else
					{
						cout << "You have insufficiant funds..." << endl;
						animal = 0;
					}
				}

				else
				{
					cout << "You can only buy up to 2. Try again: " << endl;
					animal = 2;
				}
			}
			while (animal == 3)
			{
				cout << "How many Black Bears would you like to buy 1 or 2? " << endl;
				cin >> num_of_animal;

				if (num_of_animal == 1)
				{
					if (bank - 6000 > 0)
					{
						bank = bank - 6000;
						bears[bear_num].new_bear();
						bear_num++;
						print_bank();
						animal = 9;
						bought_animals = true;
					}
					else
					{
						cout << "You have insufficiant funds..." << endl;
						animal = 0;
					}
				}

				else if (num_of_animal == 2)
				{
					if (bank - 12000 > 0)
					{
						bank = bank - 12000;
						bears[bear_num].new_bear();
						bear_num++;
						bears[bear_num].new_bear();
						bear_num++;
						print_bank();
						animal = 9;
						bought_animals = true;
					}
					else
					{
						cout << "You have insufficiant funds..." << endl;
						animal = 0;
					}
				}

				else
				{
					cout << "You can only buy up to 2. Try again: " << endl;
					animal = 3;
				}
			}
		}
	}

	else 
	{
		cout << "You already baught animals this month. Try again next month." << endl;
	}
}

void Zoo::feed()
{
	float lion_cost;
	float tiger_cost;
	float bear_cost;

	tiger_cost = food * 5;
	tiger_cost = tiger_cost * tiger_num;

	bear_cost = food * 3;
	bear_cost = bear_cost * bear_num;

	lion_cost = food * lion_num;

	bank = bank - tiger_cost;
	bank = bank - bear_cost;
	bank = bank - lion_cost;

	month_cost = tiger_cost + bear_cost + lion_cost;
}

void Zoo::random_occ()
{
	srand(time(NULL));
	rand_occasion = rand() % 3;
}

void Zoo::month_events()
{
	srand(time(NULL));

	int sick_animal;

	random_occ();

	if (check_if_sick() == true)
	{
		cout << "You have a sick animal! You need to help it!" << endl;
	}
	else{
		feed();

		if (rand_occasion == 0)
		{
			month_revenue();
			age_up();
			print_month();
			print_bank();
		}

		else if (rand_occasion == 1)
		{
			sick_animal = rand() % 2;

			if (sick_animal == 0)
			{
				sick_animal = rand() % lion_num;
				lions[sick_animal].get_sick();
			}
			else if (sick_animal == 1)
			{
				sick_animal = rand() % tiger_num;
				tigers[sick_animal].get_sick();
			}
			else
			{
				sick_animal = rand() % bear_num;
				bears[sick_animal].get_sick();
			}

			month_revenue();
			age_up();
			print_month();
			print_bank();
		}
		else
		{
			cout << "Option 3" << endl;
			month_revenue();
			age_up();
			print_month();
			print_bank();
		}
	}
	bought_animals = false;
}

bool Zoo::check_if_sick()
{
	bool is_sick = false;

	for (int i = 0; i < lion_num; i++)
	{
		if (lions[i].if_sick() == true)
			is_sick = true;

		else
			continue;
	}

		for (int i = 0; i < tiger_num; i++)
	{
		if (tigers[i].if_sick() == true)
			is_sick = true;

		else
			continue;
	}

		for (int i = 0; i < bear_num; i++)
	{
		if (bears[i].if_sick() == true)
			is_sick = true;

		else
			continue;
	}

	return is_sick;
}

void Zoo::month_revenue()
{
	revenue = 1500 * tiger_num;

	revenue = revenue + 600 * bear_num;

	revenue = revenue + 120 * lion_num;

	bank = bank + revenue;
}

void Zoo::age_up()
{
	for (int i = 0; i < lion_num; i++)
	{
		lions[i].change_age();
	}

		for (int i = 0; i < tiger_num; i++)
	{
		tigers[i].change_age();
	}

		for (int i = 0; i < bear_num; i++)
	{
		bears[i].change_age();
	}
}

void Zoo::print_month()
{
	cout << "You started the month with $" << bank << endl;
	cout << "You fed you animals for $" << month_cost << endl;
	cout << "You made a total revenue of $" << revenue << endl;

	if (check_if_sick() == true)
	{
		cout << "Also you now have a sick animal!" << endl;
	}
	else
	{
		cout << "" << endl;
	}
}

void Zoo::make_healthy()
{
	float sick_cost;

	for (int i = 0; i < lion_num; i++)
	{
		if (lions[i].if_sick() == true){
			if (bank < 400){
				cout << "You can't save this animal! It has to die..." << endl;
				lions[i].healthy();
				lion_num--;
			}
			else{
				bank = bank - 400;
				cout << "Your animal is now healthy! It was $400" << endl;
			}
		}

		else
			continue;
		
	}

	for (int i = 0; i < tiger_num; i++)
	{
		if (tigers[i].if_sick() == true){
			if (bank < 7500){
				cout << "You can't save this animal! It has to die..." << endl;
				tigers[i].healthy();
				tiger_num--;
			}
			else{
				bank = bank - 7500;
				cout << "Your animal is now healthy! It was $7500" << endl;			}

		}

		else
			continue;
	}

	for (int i = 0; i < bear_num; i++)
	{
		if (bears[i].if_sick() == true){
			if (bank < 1200){
				cout << "You can't save this animal! It has to die..." << endl;
				bears[i].healthy();
				bear_num--;
			}
			else{
				bank = bank - 1200;
				cout << "Your animal is now healthy! It was $1200" << endl;
			}

		}

		else
			continue;
	}
	cout << "Your animal is healthy now! It was $" << sick_cost << endl;
}

bool Zoo::bankrupt()
{
	if (bank <= 0){
		cout << "You are bankrupt!" << endl;
		exit(0);
	}

	else
		return false;
}