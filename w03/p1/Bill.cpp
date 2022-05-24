#include <iostream>
#include "cstring.h"
#include "Bill.h"

using namespace std;
namespace sdds
{
	void Bill::init(const char* title, int noOfItems)
	{
		if (noOfItems != 0 || title != nullptr)
		{

			m_noOfItems = noOfItems;
			m_itemsAdded = 0;

			strnCpy(m_title, title, 36);
			m_items = new Item[m_noOfItems];

			for (int i = 0; i < m_noOfItems; i++)
			{

				m_items[i].setEmpty();
			}
		}
		else
		{

			setEmpty();
		}
	}


	bool Bill::add(const char* item_name, double price, bool taxed)
	{

		bool record = false;

		if (m_itemsAdded >= m_noOfItems || item_name == nullptr || price <= 0)
		{
			m_items[m_itemsAdded].setEmpty();
			m_itemsAdded++;
		}

		else
		{
			record = true;
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
		}
		return record;
	}

	void Bill::setEmpty()
	{
		m_items = nullptr;
		m_title[0] = '\0';
	}

	bool Bill::isValid()const
	{
		int i;
		bool record = true;

		if (m_items != nullptr) 
		{
			if (m_title[0] != '\0')
			
				{

					i = 0;
					while (i < m_noOfItems)
					{
						if (!m_items[i].isValid())
						{
							record = false;

						}
						i++;
					}
				}
			
		}
		return record;
	}

	double Bill::totalTax()const
	{

		int i =0;
		double allTax = 0.0;

		while (i < m_noOfItems) {
			allTax += m_items[i].tax();
			i++;
		}

		return allTax;
	}

	double Bill::totalPrice()const
	{

		int i=0;
		double sumAllPrice = 0.0;

		while (i < m_noOfItems)
		{

			sumAllPrice += m_items[i].price();
			i++;
		}

		return sumAllPrice;

	}

	void Bill::Title()const
	{

		cout.setf(ios::fixed);
		cout << "+--------------------------------------+" << endl;

		if (isValid())
		{
			cout << "| ";
			cout.setf(ios::left);
			cout.fill(' ');
			cout.width(36);
			cout << m_title;
			cout.unsetf(ios::left);
			cout << " |" << endl;
		}
		else
		{
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+----------------------+---------+-----+" << endl << "| Item Name            | Price   + Tax |" << endl << "+----------------------+---------+-----+" << endl;

	}

	void Bill::footer()const
	{

		cout.setf(ios::fixed);
		cout << "+----------------------+---------+-----+" << endl;

		if (!isValid())
		{
			cout << "| Invalid Bill                         |" << endl;
		}

		else
		{
			cout << "|                Total Tax: ";
			cout.setf(ios::right);
			cout.fill(' ');
			cout.width(10);
			cout.precision(2);
			cout << totalTax();
			cout << " |" << endl<< "|              Total Price: ";
			cout.fill(' ');
			cout.width(10);
			cout.precision(2);
			cout << totalPrice();
			cout << " |" << endl << "|          Total After Tax: ";
			cout.setf(ios::right);
			cout.fill(' ');
			cout.width(10);
			cout.precision(2);
			cout << totalTax() + totalPrice();
			cout << " |" << endl;
			cout.unsetf(ios::right);
			
		}
		cout << "+--------------------------------------+" << endl;
	}


	void Bill::display()const
	{
		int i = 0;

		Title();
		while (i < m_noOfItems)
		{

			m_items[i].display();
			i++;
		}
		
		footer();

	}

	void Bill::deallocate()
	{
		delete[] m_items;
	}
}