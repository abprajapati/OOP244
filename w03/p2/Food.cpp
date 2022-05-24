
#include<iostream>

#include "Food.h"
#include "cstring.h"

using namespace std;
namespace sdds {

	void Food::setEmpty() {

		m_nameOfFood[0] = '\0';
		m_numberOfCalories = 0;
	}

	void Food::setName(const char* name) {

		strnCpy(m_nameOfFood, name, 30);
	}

	bool Food::isValid()const {

		bool record = true;
		if (m_numberOfCalories == 0 && m_nameOfFood[0] == '\0')
		{
			record = false;
		}
		return record;
	}

	void Food::set(const char* nameOfItems, int cal, int when) {

		if (nameOfItems == NULL || when <= 0 || cal < 0)
		{

			setEmpty();
		}
		else {

			setName(nameOfItems);
			m_numberOfCalories = cal;
			if (when > 0)
				m_consumTime = when;
		}
	}

	int Food::calories()const {

		return m_numberOfCalories;
	}

	int Food::conTime()const {

		return m_consumTime;
	}

	void Food::display() const {

		if (!isValid())
		{

			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
		else
		{

			cout.setf(ios::fixed);

			cout << "| ";
			cout.setf(ios::left);
			cout.width(30);
			cout.fill('.');
			cout << m_nameOfFood << " | ";
			cout.unsetf(ios::left);
			cout.setf(ios::right);
			cout.fill(' ');
			cout.width(4);
			cout << m_numberOfCalories << " | ";
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.fill(' ');
			cout.width(10);

			if (m_consumTime == 1)
			{
			cout << "Breakfast";
		    }
			else if (m_consumTime == 3)
			{
				cout << "Dinner";
			}
			else if (m_consumTime == 2)
			{
				cout << "Lunch";
			}
			else
				cout << "Snack";
			cout << " |";
		    cout << endl;
			cout.unsetf(ios::left);
			cout.unsetf(ios::fixed);
			
		}

	}

}