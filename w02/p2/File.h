
#pragma once
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();

	bool read(char* postalCOde);
	bool read(int& totalPopulation);
}
#endif