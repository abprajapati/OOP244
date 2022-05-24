
#include "Rectangle.h"

namespace sdds 
{
	Rectangle::Rectangle() : LblShape()
	{
		m_height = 0;
		m_width = 0;

	}
	
	Rectangle::Rectangle(const char* string, int widthOfRectangle, int heightOfRectangle) : LblShape(string)
	{
		m_height = heightOfRectangle;
		m_width = widthOfRectangle;
		
	}

	void Rectangle::draw(std::ostream& ostr)const
	{
		if (label() == nullptr || m_height <= 2 || m_width <= 2)
		{
			;
		}
		else
		{
			int drawWidth = m_width - 2;
			ostr << "+";
			for (int i = 0; i < drawWidth; i++)
			{
				ostr << "-";
			}
			ostr << "+\n";
			ostr << "|";
			ostr.setf(std::ios::left);
			ostr.width(drawWidth);
			ostr.fill(' ');
			ostr << label();
			ostr.unsetf(std::ios::left);
			ostr << "|\n";
			for (int i = 0; i < m_height - 3; i++)
			{

				ostr << "|";
				for (int i = 0; i < drawWidth; i++)
				{

					ostr << " ";
				}
				ostr << "|\n";
			}
			ostr << "+";
			for (int i = 0; i < drawWidth; i++)
			{

				ostr << "-";
			}

			ostr << "+";
		}
	}
	
	void Rectangle::getSpecs(std::istream& istr) 
	{

		LblShape::getSpecs(istr);
		istr >> m_width;

		istr.ignore(1000, ',');
		istr >> m_height;

		istr.ignore(1000, '\n');
	}
	
}