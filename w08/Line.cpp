#include "Line.h"
#include <cstring>
namespace sdds {
	Line::Line() : LblShape() 
	{
		m_length = 0;
	}
	
	Line::Line(const char* string, int info) : LblShape(string)
	{
		m_length = info;
	}

	void Line::getSpecs(std::istream& istr) 
	{

		LblShape::getSpecs(istr);
		istr >> m_length;
		istr.ignore(1000, '\n');
	}
	void Line::draw(std::ostream& ostr)const 
	{

		if (m_length <= 0 || label() == nullptr)
		{
			;
		}
		else
		{
			ostr << label() << "\n";
			for (int i = 0; i < m_length; i++)
			{
				ostr << "=";
			}
		}
	}
}