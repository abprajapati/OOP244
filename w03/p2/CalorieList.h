
#ifndef _CALORIELIST_H_
#define _CALORIELIST_H_

#include <iostream>
#include "Food.h"
namespace sdds {

    class CalorieList {
        Food* m_itemsOfFood;
        int m_numberOfItems;
        int m_addedItems;
        void setEmpty();
        int totalcalories()const;
        void Title()const;
        void footer()const;

        bool isValid()const;
    public:
        void init(int size);
        bool add(const char* item_name, int calories, int when);
        void display()const;
        void deallocate();
    };
}


#endif // !_CALORIELIST_H_
