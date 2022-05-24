
#ifndef LINE_H_
#define LINE_H_

#include <iostream>
#include "LblShape.h"

namespace sdds {

	class Line : public LblShape{

		int m_length;
	public:

		Line();
		Line(const char*, int info);
		void getSpecs(std::istream&);
		void draw(std::ostream&)const;
	};
}
#endif // !LBISHAPE_H_
