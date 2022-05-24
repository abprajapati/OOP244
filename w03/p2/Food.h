#pragma once

#ifndef  _FOOD_H_
#define _FOOD_H_

#include <iostream>
namespace sdds {
    class Food {

        char m_nameOfFood[30];
        int m_numberOfCalories;
        int m_consumTime;
        void setName(const char* name);

    public:
        void setEmpty();
        bool isValid()const;
        void set(const char* nameOfItems, int cal, int when);
        int conTime()const;
        int calories()const;
        void display()const;
    };

}
#endif