#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
	private:

	public:
		int age;
		bool is_sick;

		Animal();

		void change_age();

		void get_sick();

		bool if_sick();

		void healthy();

};

#endif
