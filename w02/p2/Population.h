#pragma once

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds
{
	struct Population
	{
		char* postalCode;
		int populationPostalCode;
	};
	void sort();

	bool load(const char filename[]);

	bool load(Population& populationNum);

	void display();

	void display(const Population& populationNum);

	void deallocateMemory();
}
#endif 