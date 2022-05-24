
#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include <iostream>
#include "LblShape.h"

namespace sdds {

	class Rectangle : public LblShape{

		int m_width;
		int m_height;

	public:

		Rectangle();
		Rectangle(const char*, int widthOfRectangle, int heightOfRectangle);
		void draw(std::ostream&)const;
		void getSpecs(std::istream&);
	};
}
#endif // !LBISHAPE_H_
