#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "Item.h"

using namespace std;
namespace sdds
{

	void Item::setName(const char* name)
	{

		strnCpy(m_itemName, name, 20);
		m_itemName[20] = 0;
	}

	void Item::setEmpty()
	{

		m_price = 0.0;
		m_itemName[0] = '\0';
	}

	void Item::set(const char* name, double price, bool taxed)
	{

		if (price > 0)
		{
			if (name[0] != '\0')
			{
				{
					setEmpty();
				}

				setName(name);
				m_price = price;
				m_taxed = taxed;
			}
		}
	}

	double Item::price()const
	{

		return m_price;
	}


	bool Item::isValid()const
	{
		bool record = false;

		if (m_itemName == nullptr || (m_price <= 0.0 || m_itemName[0] == '\0'))
		{
			record = false;	
		}
		else
		{
			record = true;
		}
		return record;

	}

	double Item::tax()const
	{
		double rate = 0.0;
		const double rateOfTax = 0.13;
		if (!m_taxed)
		{
			rate = 0.0;
		}
		else
		{
			rate = m_price * rateOfTax;

		}
		return rate;
	}

	void Item::display()const
	{
		if (!isValid())
		{
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
		else
		{
			cout.setf(ios::fixed);
			cout << "| ";
			cout.setf(ios::left);
			cout.width(20);
			cout.fill('.');
			cout << m_itemName << " | ";
			cout.unsetf(ios::left);
			cout.setf(ios::right);
			cout.fill(' ');
			cout.width(7);
			cout.precision(2);
			cout << m_price << " | ";
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(3);

			if (m_taxed != true)
			{
				cout << "No";
			}
			else
			{
				cout << "Yes";
			}

			cout << " |" << endl;
			cout.unsetf(ios::left);
			cout.unsetf(ios::fixed);
			
		}
	}
}