
#include "Label.h"
#include "cstring.h"

#include <iostream>

using namespace std;

namespace sdds
{
	Label::Label()
	{

		nameOfCharacter = new char[70 + 1];

		strCpy(nameOfCharacter, "");
		strCpy(outerFrame, "+-+|+-+|");
	}

	Label :: Label(const char* frameArg)
	{

		outerFrame[0] = '\0';
		nameOfCharacter = new char[70 + 1];

		strCpy(nameOfCharacter, "");
		strCpy(outerFrame, frameArg);
	}

	Label :: Label(const char* frameArg, const char* content)
	{

		outerFrame[0] = '\0';

		if (frameArg == nullptr || content == nullptr)
		{

			;
		}
		else
			{

				strCpy(outerFrame, frameArg);
				nameOfCharacter = new char[strLen(content) + 1];
				strCpy(nameOfCharacter, content);
			}
		
	}

	void Label::readLabel()
	{

		cin.getline(nameOfCharacter, 70 + 1);

		if (cin.fail())
		{

			cin.ignore(100000, '\n');
		}
	}

	ostream& Label::printLabel()const
	{
		
		if (strLen(nameOfCharacter) == 0 || nameOfCharacter == nullptr)
		{

			;
		}
		else
		{

				cout << outerFrame[0];
				cout.setf(ios::fixed);

				int i ;
				i = 0; 

				while (i < strLen(nameOfCharacter) + 2)
				{

					cout << outerFrame[1];
					i++;
				} 

				cout << outerFrame[2];
				cout << "\n";
				cout << outerFrame[3];

				i = 0;

				while (i < strLen(nameOfCharacter) + 2)
				{

					cout << " ";
					i++;
				}
				cout << outerFrame[3] << "\n" << outerFrame[7] << " ";
				cout << nameOfCharacter << " " << outerFrame[3] << "\n" << outerFrame[7];

				i = 0;

				for(i=0; i < strLen(nameOfCharacter) + 2; i++)
				{

					cout << " ";
				} 
				cout << outerFrame[3] << "\n" << outerFrame[6];

				i = 0;
				do
				{

					cout << outerFrame[5];
					i++;
				} while (i < strLen(nameOfCharacter) + 2);

				cout << outerFrame[4];
				cout.unsetf(ios::fixed);
		}

		return cout;
	}

	Label::~Label()
	{

		delete[] nameOfCharacter;
		nameOfCharacter = nullptr;
	}
}

