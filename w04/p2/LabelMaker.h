
#ifndef SDDS_LABELMAKER_H_
#define SDDS_LABELMAKER_H_

#include "Label.h"

namespace sdds
{
	class LabelMaker
	{

		int totalLabel;
		Label* nameOfLabel;

	public:

		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();

		~LabelMaker();
	};
}
#endif
