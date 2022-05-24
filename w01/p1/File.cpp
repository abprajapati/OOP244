

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include "File.h"

// set to false when compling on Linux

using namespace std;
using namespace sdds;
const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";
FILE* sfptr = nullptr;

bool sdds::openFileForRead() {
   sfptr = fopen(SHOPPING_DATA_FILE, "r");
   return sfptr != NULL;
}

bool sdds::openFileForOverwrite() {
   sfptr = fopen(SHOPPING_DATA_FILE, "w");
   return sfptr != NULL;
}

void sdds::closeFile() {
   if (sfptr) fclose(sfptr);
}

bool sdds::freadShoppingRec(ShoppingRec* rec) {
   int flag = 0;
   bool success = fscanf(sfptr, "%[^,],%d,%d\n",
      rec->m_title, &rec->m_quantity, &flag) == 3;
   rec->m_bought = !!flag;
   return success;
}

void sdds::fwriteShoppintRec(const ShoppingRec* rec) {
   fprintf(sfptr, "%s,%d,%d\n", rec->m_title, rec->m_quantity, rec->m_bought);
}
