
#include <iostream>
#include "CalorieList.h"
#include "Food.h"

using namespace std;
namespace sdds {

	void CalorieList::setEmpty() {

		m_itemsOfFood = NULL;
	}

	bool CalorieList::isValid()const {

		int i = 0;
		bool record = true;
		
		if (m_itemsOfFood != NULL)
		{
			do
			{
				
				if (!m_itemsOfFood[i].isValid())
				{
					record = false;
				}
				i++;

			} while (i < m_numberOfItems);
		}
		return record;
	}

	void CalorieList::Title()const {

		cout.setf(ios::fixed);
		cout << "+----------------------------------------------------+" << endl;

		if (!isValid())
		{

			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		else
		{

			cout << "| ";
			cout.setf(ios::left);
			cout.fill(' ');
			cout.width(50);
			cout << " Daily Calorie Consumption";
			cout.unsetf(ios::left);
			cout << " |" << endl;
		}

		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}

	int CalorieList::totalcalories()const {

		int i = 0;
		int total = 0;
		
		while(i < m_numberOfItems)
		{
			total += m_itemsOfFood[i].calories();
			i++;
		}

		return total;
	}

	
	void CalorieList::footer()const
	{

		cout.setf(ios::fixed);
		cout << "+--------------------------------+------+------------+" << endl;

		if (!isValid())
		{

			cout << "|    Invalid Calorie Consumption list                |";
			cout << endl;
		}
		else
		{

			cout << "|    Total Calories for today:   ";
			cout.setf(ios::right);
			cout.fill(' ');
			cout.width(6);
			cout << totalcalories() << " |            |";
			cout << endl;
			cout.unsetf(ios::right);
		}
		cout << "+----------------------------------------------------+" << endl;
	}

	void CalorieList::init(int size) {
		if (size != 0)
		{

			m_addedItems = 0;
			m_numberOfItems = size;
			m_itemsOfFood = new Food[m_numberOfItems + 1];
			for (int i = 0; i < m_numberOfItems; i++)
			{
				m_itemsOfFood[i].setEmpty();
			}
		}
		else
		{

			setEmpty();
		}

	}

	bool CalorieList::add(const char* item_name, int calories, int when)
	{

		bool record = false;
		if (item_name != NULL && m_addedItems < m_numberOfItems && when > 0 && calories > 0 )
		{

			record = true;
			m_itemsOfFood[m_addedItems].set(item_name, calories, when);
			m_addedItems++;
		}
		else
		{

			m_itemsOfFood[m_addedItems].setEmpty();
			m_addedItems++;
		}

		return record;
	}

	void CalorieList::display()const {
		int i = 0;
		Title();
	
		while(i < m_numberOfItems)
		{

			m_itemsOfFood[i].display();
			i++;
		}
		footer();
	}

	void CalorieList::deallocate() {

		delete[] m_itemsOfFood;
	}
}