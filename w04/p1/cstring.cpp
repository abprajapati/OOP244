
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

        int i = 0;;
        do {

            desString[i] = srcString[i];
            i++;
        } while (i < length);

        if (i < length)
        {
            desString[i] = '\0';
        }
        desString[i] = '\0';
    }
    int strCmp(const char* string1, const char* string2)
    {
        int i = 0, keep = 1, result = 0;

        for (i = 0; keep && (string2[i] != '\0' || string1[i] != '\0'); i++)
        {
            if (string1[i] > string2[i])
            {
                result = 1;
                keep = 0;
            }
            else if (string1[i] < string2[i])
            {
                result = -1;
                keep = 0;
            }
            else
            {
                result = 0;
            }

        }
        return result;

    }



    int strnCmp(const char* string1, const char* string2, int length)
    {

        int i = 0, result = 0;

        do
        {
            if (string1[i] > string2[i])
            {
                result = 1;
            }
            else if (string1[i] < string2[i])
            {
                result = -1;
            }
            else
            {
                result = 0;
            }
            i++;
        } while (i < length);
        return result;
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
        const char* readyStr = { 0 };
        int record = 1;

        while (*string1 && record)
        {
            const char* str1 = string1;
            const char* str2 = string2;
            while (((*str1 && *str2) && (*str1 == *str2)))
            {
                str1++;
                str2++;
            }

            if (*str2 == '\0')
            {
                readyStr = string1;
                record = 0;

            }
            else
            {
                readyStr = NULL;
            }
            string1++;
        }
        return readyStr;
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