#include <string>
#include <iostream>
#include "animal.h"

using namespace std;

Animal::Animal()
{
	age = 0;
	is_sick = false;
}

void Animal::change_age()
{
	age++;
}

void Animal::get_sick()
{
	is_sick = true;
}

bool Animal::if_sick()
{
	return is_sick;
}

void Animal::healthy()
{
	is_sick = false;
}