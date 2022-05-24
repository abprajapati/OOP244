

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include "File.h"


namespace sdds
{
	FILE* fptr;
	bool openFile(const char filename[])
	{

		fptr = fopen(filename, "r");
		return fptr != NULL;
	}
	int noOfRecords()
	{
		int noOfRecs = 0;
		char ch;
		while (fscanf(fptr, "%c", &ch) == 1)
		{
			noOfRecs += (ch == '\n');
		}
		rewind(fptr);
		return noOfRecs;
	}
	void closeFile()
	{
		if (fptr) fclose(fptr);
	}



	bool read(char* salaryOfemp)
	{
		bool analyze = false;
		int info = fscanf(fptr, "%[^\n]\n",
			salaryOfemp) == 1;


		if (info <= 0)
		{
			analyze = false;
		}
		else
		{
			analyze = true;
		}


		return analyze;
	}


	bool read(int& empNum)
	{
		bool analyze = false;
		int info = fscanf(fptr, "%d,",
			&empNum) == 1;

		if (info <= 0)
		{
			analyze = false;
		}
		else
		{
			analyze = true;
		}


		return analyze;
	}

	bool read(double& salaryOfemp)
	{
		bool analyze = false;
		int info = fscanf(fptr, "%lf,",
			&salaryOfemp) == 1;

		if (info <=0)
		{
			analyze = false;
		}
		else
		{
			analyze = true;
		}


		return analyze;
	}

}