#pragma once
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds
{
	class Account
	{

		int m_number;
		double m_balance;
		void setEmpty();
	public:

		Account();
		Account(int number, double balance);
		std::ostream& display()const;

		operator bool() const;
		operator double()const;
		operator int()const;
		bool accountValidation(int accountValue)const;
		bool operator ~() const;

		Account& operator=(int accountNum);
		Account& operator=(Account& accountValue);
		Account& operator-=(double accVal);
		Account& operator+=(double accVal);
		Account& operator<<(Account& accountValue);
		Account& operator>>(Account& accountValue);

	};

	double operator +=(double& value, const Account& accVal);
	double operator +(const Account& accountValue1, const Account& accountValue2);
}
#endif // SDDS_ACCOUNT_H_