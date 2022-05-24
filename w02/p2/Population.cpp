

#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"

using namespace std;

namespace sdds
{

	int populationNumber;
	Population* postalPopulation;

	void sort()
	{
		int i, j;
		Population record;
		for (i = populationNumber - 1; i > 0; i--)
		{
			for (j = 0; j < i; j++)
			{
				if (postalPopulation[j].populationPostalCode > postalPopulation[j + 1].populationPostalCode)
				{
					record = postalPopulation[j];
					postalPopulation[j] = postalPopulation[j + 1];
					postalPopulation[j + 1] = record;
				}
			}
		}
	}

	bool load(Population& populationNum)
	{
		bool ok = false;
		char name[128];

		if (read(name) == true && read(populationNum.populationPostalCode) == true)
		{

			populationNum.postalCode = new char[strLen(name) + 1];
			strCpy(populationNum.postalCode, name);


			ok = true;

		}
		else
		{
			ok = false;
		}
		return ok;
	}

	bool load(const char filename[])
	{
		bool ok = false;
		int i = 0, count = 0;

		if (openFile(filename))
		{
			populationNumber = noOfRecords();

			Population* popula = new Population[populationNumber];

			while (i < populationNumber)
			{

				if (load(popula[i]) == true)
				{

					count++;
				}
				i++;
			}

			if (count != populationNumber)
			{

				cout << "Error: incorrect number of records read; the data is possibly corrupted";
			}
			else
			{

				ok = true;
			}

			postalPopulation = popula;

			closeFile();

		}
		else
		{
			cout << "Could not open data file: ";
			cout << filename << endl;
		}
		return ok;
	}

	void display(const Population& populationNum)
	{
		static int i = 0;
		cout << i + 1 << "- " << populationNum.postalCode;
		cout << ":  " << populationNum.populationPostalCode << endl;
		i++;

	}

	void display()
	{
		int i;
		int sumPopulation = 0;

		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;

		sort();

		for (i = 0; i < populationNumber; i++)
		{

			display(postalPopulation[i]);

			sumPopulation += postalPopulation[i].populationPostalCode;

		}

		cout << "-------------------------" << endl << "Population of Canada: " << sumPopulation << endl;

	}

	void deallocateMemory()
	{
		int i = 0;

		while (i < populationNumber)
		{
			delete[] postalPopulation[i].postalCode;
			i++;
		}

		delete[] postalPopulation;

	}
}