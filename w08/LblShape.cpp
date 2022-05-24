#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include <string>
#include <cstring>

using namespace std;

namespace sdds {

	char* LblShape::label()const 
	{
		return m_label;
	}

	LblShape::LblShape()
	{
		m_label = nullptr;
	}

	LblShape::LblShape(const char* string) 
	{
		int record = strlen(string) + 1;
		m_label = new char[record];
		strcpy(m_label, string);
	}

	LblShape::~LblShape() 
	{
		delete[] m_label;
		m_label = nullptr;
	}

	void LblShape::getSpecs(std::istream& istr) 
	{
		string keep;

		getline(istr, keep, ',');
		delete[] m_label;

		m_label = nullptr;
		m_label = new char[keep.length() + 1];
		strcpy(m_label, keep.c_str());
	}


}