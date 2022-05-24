#pragma once

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_

namespace sdds
{

	class Mark
	{

		int m_marks = 0;
	public:

		bool valOfMarks(int info)const;
		Mark();
                Mark(int infoMarks);
		

		operator double()const;
                operator int()const;
		operator char()const;

		Mark& operator+=(int info);
                Mark& operator=(int info);
		int getValueOfMark()const;
	};

	int operator+=(int& info, const Mark& markValue);
}


#endif