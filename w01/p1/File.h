

#ifndef SDDS_FILE_H // replace with relevant names
#define SDDS_FILE_H

#include "ShoppingRec.h"

// Your header file content goes here
namespace sdds {
	
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);

}



#endif