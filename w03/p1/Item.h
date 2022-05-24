#pragma once
#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
namespace sdds {
    class Item {
        char m_itemName[21];
        double m_price;
        bool m_taxed;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, double price, bool taxed);
        double price()const;
        double tax()const;
        bool isValid()const;
        void display()const;
    };

}

#endif // !SDDS_SUBJECT_H
