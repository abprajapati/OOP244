
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"  
#include "Employee.h"
#include "File.h"
using namespace std;

namespace sdds
{
	int noOfEmployees;
	Employee* employees;

	void sort()
	{
		int i, j;
		Employee temp;

		for (i = noOfEmployees - 1; i > 0; i--)
		{

			for (j = 0; j < i; j++)
			{

				if (employees[j].m_empNo > employees[j + 1].m_empNo)
				{

					temp = employees[j];
					employees[j] = employees[j + 1];
					employees[j + 1] = temp;
				}
			}
		}
	}


	bool load()
	{
		int i = 0, count = 0;
		bool ok = false;

		if (openFile(DATAFILE))
		{

			noOfEmployees = noOfRecords();

			Employee* empInfo = new Employee[noOfEmployees];
			i = 0;
			while (i < noOfEmployees)
			{

				if (load(empInfo[i]) == true)
				{

					count++;
				}
				i++;
			}

			if (count != noOfEmployees)
			{

				cout << "Error: incorrect number of records read; the data is possibly corrupted";
			}
			else
			{

				ok = true;
			}

			employees = empInfo;

			closeFile();

		}
		else
		{
			cout << "Could not open data file: ";
			cout << DATAFILE << endl;
		}
		return ok;
	}


	bool load(Employee& employeesInformation)
	{
		bool ok = false;
		char name[128];

		if (read(employeesInformation.m_empNo) == true && read(employeesInformation.m_salary) == true && read(name) == true)
		{

			employeesInformation.m_name = new char[strLen(name) + 1];
			strCpy(employeesInformation.m_name, name);


			ok = true;

		}
		else
		{
			ok = false;
		}
		return ok;
	}


	void display(const Employee& employeesInformation)
	{

		static int i = 0;
		cout << i + 1;
		cout << "- " << employeesInformation.m_empNo;
		cout << ": " << employeesInformation.m_name;
		cout << ", " << employeesInformation.m_salary << endl;
		i++;

	}

	void display()
	{

		cout << "Employee Salary report, sorted by employee number" << endl << "no- Empno, Name, Salary" << endl;
		cout << "------------------------------------------------" << endl;
		sort();

		int i = 0;
		do {

			display(employees[i]);
			i++;
		} while (i < noOfEmployees);


	}

	void deallocateMemory()
	{

		int i = 0;

		while (i < noOfEmployees) {

			delete[] employees[i].m_name;
			i++;
		}
		delete[] employees;

	}
}