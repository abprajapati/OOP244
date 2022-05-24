
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

#include<iostream>

namespace sdds
{
	class Label
	{
		char outerFrame[8 + 1];
		char* nameOfCharacter;

	public:

		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		void readLabel();
		std::ostream& printLabel()const;
		~Label();
	};
}
#endif 
