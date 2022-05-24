
#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <cstdlib>
#include "Utils.h"

// set to false when compling on Linux


using namespace std;
using namespace sdds;



void sdds::flushkeys()
{
    while (cin.get() != '\n');
}

bool sdds::ValidYesResponse(char ch)
{

    return ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n';
}

bool sdds::yes()
{
    char ch = 0;
    do {
        cin >> ch;
        flushkeys();
    } while (!ValidYesResponse(ch) && cout << "Only (Y/y) or (N/n) is acceptable: ");
    return ch == 'y' || ch == 'Y';
}

void sdds::readCstr(char cstr[], int len)
{

    char buf[1024] = {};
    int i;
    cin.getline(buf, 1024);
    for (i = 0; i < len && buf[i]; i++) {
        cstr[i] = buf[i];
    }
    cstr[i] = 0;
}

int sdds::readInt(int min, int max)
{

    int value = 0;
    bool done = false;
    while (!done) {
        cin >> value;
        if (!cin) {
            cin.clear();
            cout << "Bad integer, try agian: ";
        }
        else {
            if (value >= min && value <= max) {
                done = true;
            }
            else {
                cout << "Value out of range (" << min << "<=value<=" << max << "): ";
            }
        }
        flushkeys();
    }
    return value;
}
