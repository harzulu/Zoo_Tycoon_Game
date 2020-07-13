#include <string>
#include <iostream>
#include "bear.h"

using namespace std;

Bear::Bear()
{
		babies = 2;
}

void Bear::new_bear()
{
	age = 0;
	is_sick = false;
	babies = 0;
}