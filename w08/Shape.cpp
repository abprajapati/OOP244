
#include "Shape.h"

namespace sdds {
	 
	 Shape::~Shape() {}
	 
	 std::ostream& operator<<(std::ostream& ostr,const Shape& object) 
	 {

		 object.draw(ostr);
		 return ostr;
	 }

	 std::istream& operator>>(std::istream& istr, Shape& object) 
	 {

		 object.getSpecs(istr);
		 return istr;
	 }
}