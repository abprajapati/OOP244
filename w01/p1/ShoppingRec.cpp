

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include "ShoppingRec.h"
#include "Utils.h"

// set to false when compling on Linux

using namespace std;
using namespace sdds;

sdds::ShoppingRec sdds::getShoppingRec()
{
    ShoppingRec R = {};
    cout << "Item name: ";
    readCstr(R.m_title, MAX_TITLE_LENGTH);
    cout << "Quantity: ";
    R.m_quantity = readInt(1, MAX_QUANTITY_VALUE);
    return R;
}
void sdds::displayShoppingRec(const ShoppingRec* shp)
{
    cout << "[" << (shp->m_bought ? 'X' : ' ') << "]" << shp->m_title <<
        " qty:(" << shp->m_quantity << ")" << endl;
}
void sdds::toggleBoughtFlag(ShoppingRec* rec)
{
    rec->m_bought = !rec->m_bought;

}
bool sdds::isShoppingRecEmpty(const ShoppingRec* shp)
{
    return shp->m_title[0] == 0;
}