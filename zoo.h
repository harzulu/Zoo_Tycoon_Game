#ifndef ZOO_H
#define ZOO_H

#include "sealion.h"
#include "tiger.h"
#include "bear.h"
#include "animal.h"

class Zoo
{
	private:
		float bank;
		int rand_occasion;
		SeaLion *lions;
		int lion_num;
		Tiger *tigers;
		int tiger_num;
		Bear *bears;
		int bear_num;
		bool bought_animals;
		float food;
		float month_cost;
		float revenue;

	public:

		Zoo();

		void print_bank();

		void buy();

		void feed();

		void random_occ();

		void month_events();

		bool check_if_sick();

		void month_revenue();

		void age_up();

		void print_month();

		void make_healthy();

		bool bankrupt();

};

#endif
