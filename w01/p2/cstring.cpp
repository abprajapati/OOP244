
#define CRT_NO_SECURE_WARNINGS
#include "cstring.h"
#include <iostream>
using namespace std;
namespace sdds {

    void strCpy(char* desString, const char* srcString)
    {
        int i;
        i = 0;
        do {

            desString[i] = srcString[i];
            i++;
        } while (srcString[i] != '\0');

        desString[i] = '\0';
    }

    void strnCpy(char* desString, const char* srcString, int length)
    {

        int i;
        i = 0;
        do {

            desString[i] = srcString[i];
            i++;
        } while (i < length);

        if (i < length)
        {
            desString[i] = '\0';
        }
    }
    int strCmp(const char* string1, const char* string2)
    {

        if (string1 < string2)
            return -1;
        else if (string1 > string2)
            return 1;
        else
            return 0;
    }

    int strnCmp(const char* string1, const char* string2, int length)
    {

        int i;
        int info = 0;
        i = 0;
        do {
            if (info == 0)
            {
                if (string1[i] < string2[i])
                    info = -1;
                else if (string1[i] > string2[i])
                    info = 1;
                else
                    info = 0;
            }

            i++;
        } while (i < length);

        if (info == -1)
            return -1;
        else  if (info == 1)
            return 1;
        else
            return 0;
    }
    int strLen(const char* string)
    {

        int i;
        int lengthOfString = 0;
        i = 0;
        while (string[i] != '\0') {
            lengthOfString++;
            i++;
        } 

        return lengthOfString;
    }


    const char* strStr(const char* string1, const char* string2)
    {
        int i; int j;
        int info = 0;
        int record = 0;
        int lengthOfString = strLen(string2);
        i = 0;

        do {
            info = 0;
            j = 0;
            do {

                if (string1[i + j] != string2[j])
                    break;
                else {
                    info++;
                }
                j++;
            } while (string2[j] != '\0');

            if (lengthOfString == info)
            {
                record++;
                break;
            }
            i++;
        } while (string1[i] != '\0');

        if (record <= 0)
            return NULL;
        else
            return &string1[i + j - lengthOfString];
    }


   
 void strCat(char* desString, const char* srcString)
   {
       int lastIndex = 0;
       int i;
       i = 0;
       do {
           lastIndex++;
           i++;
       } while (desString[i] != '\0');

       i = 0;
       do {
           desString[lastIndex] = srcString[i];
           lastIndex++;
           i++;
       } while (srcString[i] != '\0');

       desString[lastIndex] = '\0';
   }
}