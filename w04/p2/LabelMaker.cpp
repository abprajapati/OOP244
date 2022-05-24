
#include <iostream>
#include "LabelMaker.h"

using namespace std;

namespace sdds
{

	LabelMaker::LabelMaker(int noOfLabels)
	{

		totalLabel = noOfLabels;
		nameOfLabel = new Label[totalLabel];
	}

	void LabelMaker::printLabels()
	{

		int i;
		for( i=0; i < totalLabel; i++)
		{
			nameOfLabel[i].printLabel();
			cout << "\n";
		}
		
	}

	void LabelMaker::readLabels()
	{

		int i;
		cout << "Enter " << totalLabel;
		cout << " labels:" << "\n";
		i = 0;

		while (i < totalLabel)
		{

			cout << "Enter label number " << i + 1 << "\n" << "> ";
			nameOfLabel[i].readLabel();

			i++;
		}
	}

	LabelMaker :: ~LabelMaker()
	{

		delete[] nameOfLabel;
		nameOfLabel = nullptr;
	}
}