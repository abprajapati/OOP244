
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds
{
	void Account::setEmpty()
	{
		m_number = -1;
		m_balance = 0.0;
	}
	// New account
	Account::Account()
	{
		m_number = 0;
		m_balance = 0.0;
	}
	Account::Account(int number, double balance)
	{
		setEmpty();
		if (number >= 10000 && number <= 99999
			&& balance > 0)
		{
			m_number = number;
			m_balance = balance;
		}
	}
	std::ostream& Account::display() const
	{
		if (*this)
		{
			cout << " ";
			cout << m_number;
			cout << " | ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << m_balance;
			cout.unsetf(ios::right);
			cout << " ";
		}
		else if (~*this)
		{
			cout << "  NEW  |         0.00 ";
		}
		else
		{
			cout << "  BAD  |    ACCOUNT   ";
		}
		return cout;
	}

	bool Account::accountValidation(int accountValue)const
	{

		bool record = false;

		if (accountValue >= 10000) 
		{

			if (accountValue <= 99999)
			{

				if (m_balance >= 0)
				{

					record = true;
				}
				else
				{

					record = false;
				}
			}
		}
		else
		{

			record = false;
		}

		return record;
	}

	Account::operator bool() const
	{
		bool record = true;

		if (accountValidation(m_number) == true)
		{

			record = true;
			
		}
		else
		{

			record = false;
		}

		return record;

	}

	Account :: operator int()const
	{

		return m_number;
	}

	Account :: operator double()const
	{

		return m_balance;
	}

	bool Account::operator ~() const
	{
		bool record = false;

		if (m_number == 0)
		{

			record = true;
		}

		return record;
	}

	Account& Account::operator=(int accountNum)
	{
		if (accountValidation(accountNum) == true )
		{

			if (m_number != 0)
			{
				;
			}
			else
			{

				m_number = accountNum;
			}
		}

		else if (accountValidation(accountNum) == false)
		{

			setEmpty();
		}
		
		return *this;

	}

	Account& Account:: operator=(Account& accountValue)
	{
		if ((m_number == 0 || accountValidation(m_number)) && (accountValue.m_number == 0 || accountValidation(accountValue.m_number)))

			{

				m_balance = (double)accountValue;
				m_number = (int)accountValue;

				accountValue.m_number = 0;
				accountValue.m_balance = 0;
			}
		


		return *this;
	}

	Account& Account::operator+=(double accVal)
	{

		if (accountValidation(m_number) != true || accVal < 0.0)
		{

			;
		}
		else
		{

			m_balance += accVal;
		}

		return *this;
	}

	Account& Account::operator<<(Account& accountValue)
	{

		if (accountValidation(m_number) == true)
		{

			if (m_number != accountValue.m_number && accountValue.m_balance >= 0)
			{

				m_balance += accountValue.m_balance;
				accountValue.m_balance = 0;
			}
		}

		return *this;
	}

	Account& Account::operator-=(double accVal)
	{

		if ((accountValidation(m_number) != true) || (accVal < 0.0 || m_balance < accVal))
			{

				;
			}
		
		
		else
		{

			m_balance -= accVal;
		}
		

		return *this;
	}

	double operator +(const Account& accountValue1, const Account& accountValue2)
	{

		double total;

		if ((int)accountValue1 == (int)accountValue2)
		{
			if ((double)accountValue1 < 0 || (double)accountValue2 < 0.0)
			{

				total = 0.0;
			}
		}

		else
		{

			total = (double)accountValue1 + (double)accountValue2;
		}

		return total;
	}

	Account& Account::operator>>(Account& accountValue)
	{
		if (accountValue.m_balance < 0 || (accountValidation(m_number) != true))
		{

			if (m_number == accountValue.m_number)
			{

				;
			}
		} 
		else
		{
			accountValue.m_balance += m_balance;
			m_balance = 0;
		}

		return *this;
	}

	

	double operator +=(double& sum, const Account& accVal)
	{

		double record;

		record = sum += (double)accVal;
		return record;
	}

}