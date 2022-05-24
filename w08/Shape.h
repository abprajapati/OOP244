
#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>

namespace sdds {

	class Shape {

	public:
		virtual void draw(std::ostream&)const = 0;
		virtual void getSpecs(std::istream&) = 0;
		virtual ~Shape();
	}; 

	std::ostream& operator<<(std::ostream&, const Shape&);
	std::istream& operator>>(std::istream&, Shape&);
}
#endif // !LBISHAPE_H_
