
#include <iostream>
#include "Mark.h"

using namespace std;

namespace sdds
{

	bool Mark::valOfMarks(int info)const
	{

		bool record = true;

		if (info < 0 || info > 100)
		{

			record = false;
		}
		else
		{
			;
		}

		return record;
	}

	Mark::Mark()
	{

		m_marks = 0;
	}

	Mark::Mark(int infoMarks)
	{

		m_marks = infoMarks;
	}

	Mark& Mark:: operator=(int info)
	{

		m_marks = info;
		return *this;
	}


	Mark& Mark::operator+=(int info)
	{

		if (valOfMarks(m_marks) != false)
		{

			m_marks += info;
		}
		else
		{

			m_marks = 0;
		}
		return *this;
	}

	
	Mark::operator int()const
	{
		int valueOfMark = 0;

		if (valOfMarks(m_marks) != false)
		{

			valueOfMark = m_marks;
		}
		else
		{

			valueOfMark = 0;
		}
		return valueOfMark;
	}

	Mark::operator double()const
	{

		double getgpapoint = 0.0;

		if (valOfMarks(m_marks) == false)
		{

			;
		}
		else
		{

			if (m_marks >= 0 && m_marks < 50)
			{

				getgpapoint = 0.0;
			}
			else if (m_marks >= 60 && m_marks < 70)
			{

				getgpapoint = 2.0;
			}
			else if (m_marks >= 70 && m_marks < 80)
			{

				getgpapoint = 3.0;
			}
			else if (m_marks >= 50 && m_marks < 60)
			{

				getgpapoint = 1.0;
			}
			else
			{

				getgpapoint = 4.0;
			}
		}

		return getgpapoint;

	}

	Mark::operator char()const
	{

		char valueOfGrade = '0';

		if (valOfMarks(m_marks) == false)
		{

			valueOfGrade = 'X';
		}
		else
		{
			if (m_marks >= 0 && m_marks < 50)
			{

				valueOfGrade = 'F';
			}
			else if (m_marks >= 60 && m_marks < 70)
			{

				valueOfGrade = 'C';
			}
			else if (m_marks >= 50 && m_marks < 60)
			{

				valueOfGrade = 'D';
			}
			else if (m_marks >= 70 && m_marks < 80)
			{

				valueOfGrade = 'B';
			}
			else
			{

				valueOfGrade = 'A';
			}

			
		}

		return valueOfGrade;

	}

	int operator+=(int& info, const Mark& markvalue)
	{

		if (markvalue.valOfMarks(markvalue.getValueOfMark()) == false)
		{

			;
		}
		else
		{

			info += markvalue.getValueOfMark();
		}

		return info;
	}

	int Mark::getValueOfMark()const
	{

		return m_marks;
	}

	

}

