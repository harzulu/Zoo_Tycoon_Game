#include <string>
#include <iostream>
#include "tiger.h"

using namespace std;

Tiger::Tiger()
{
	babies = 3;
}

void Tiger::new_tiger()
{
	age = 0;
	is_sick = false;
	babies = 0;
}