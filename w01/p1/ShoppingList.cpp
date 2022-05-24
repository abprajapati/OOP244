

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include "ShoppingList.h"
#include "File.h"
#include "Utils.h"

// set to false when compling on Linux

using namespace std;
using namespace sdds;

ShoppingRec recs[MAX_NO_OF_RECS] = {};
int noOfRecs = 0;


bool sdds::loadList()
{
    ShoppingRec shpr = {};
    bool ok = false;
    if (openFileForRead()) {
        ok = true;
        while (noOfRecs < MAX_NO_OF_RECS &&
            freadShoppingRec(&shpr)) {
            recs[noOfRecs++] = shpr;
        }
        closeFile();
    }
    return ok;
}
bool sdds::saveList()
{
    bool ok = false;
    if (openFileForOverwrite()) {
        ok = true;
        for (int i = 0; i < noOfRecs; i++) {
            fwriteShoppintRec(&recs[i]);
        }
        closeFile();
    }
    return ok;
}

void sdds::removeItem(int index)
{
    if (index >= 0 && index < noOfRecs) {
        noOfRecs--;
        for (int i = index; i < noOfRecs; i++) {
            recs[i] = recs[i + 1];
        }
    }
}
void sdds::clearList()
{
    cout << "This will remove all the items from the list;" << endl
        << "Are you sure? (Y)es/(N)o" << endl;
    if (yes()) {
        noOfRecs = 0;
    }
    else {
        cout << "Cancelled!" << endl;
    }
}
void sdds::toggleBought()
{
    cout << "Item number: ";
    toggleBoughtFlag(&recs[readInt(1, noOfRecs) - 1]);
}

void sdds::addItemToList()
{
    if (noOfRecs < MAX_NO_OF_RECS) {
        recs[noOfRecs] = getShoppingRec();
        noOfRecs += !isShoppingRecEmpty(&recs[noOfRecs]);
    }
    else {
        cout << "Shopping List is full!" << endl;
    }
}

void sdds::removeItemfromList()
{
    if (!listIsEmpty()) {
        int value = 0;
        cout << "Item number to delete: ";
        value = readInt(1, noOfRecs);
        cout << "Deleting following item, are you sure?" << endl;
        displayShoppingRec(&recs[value - 1]);
        cout << "(Y)es/(N)o: ";
        if (yes()) {
            removeItem(value - 1);
        }
        else {
            cout << "Cancelled!" << endl;
        }
    }
    else {
        cout << "List is empty!" << endl;
    }

}

bool sdds::listIsEmpty()
{
    return noOfRecs == 0;
}



void sdds::displayList()
{
    for (int i = 0; i < noOfRecs; i++) {
        cout << (i + 1) << "-";
        displayShoppingRec(&recs[i]);
    }
}

void sdds::removeBoughtItems()
{
    if (!listIsEmpty()) {
        cout << "Removing bought items, are you sure?" << endl;
        cout << "(Y)es/(N)o: ";
        if (yes()) {
            for (int i = 0; i < noOfRecs; i++) {
                if (recs[i].m_bought) removeItem(i--);
            }
        }
        else {
            cout << "Cancelled!" << endl;
        }
    }
    else {
        cout << "List is empty!" << endl;
    }
}