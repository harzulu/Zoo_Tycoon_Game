#include <string>
#include <iostream>
#include "sealion.h"

using namespace std;

SeaLion::SeaLion()
{
		babies = 1;
}

void SeaLion::new_lion()
{
	age = 0;
	is_sick = false;
	babies = 0;
}