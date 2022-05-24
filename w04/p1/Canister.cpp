
#define _CRT_SECURE_NO_WARNINGS

#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"

using namespace std;
namespace sdds
{
	const double PI = 3.14159265;

	void Canister::setToDefault()
	{

		m_contentName = nullptr;

		m_diameter = 10.0;
		m_height = 13.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	bool Canister::hasSameContent(const Canister& C)const
	{

		bool record = false;

		if (m_contentName != nullptr)
		{

			if (C.m_contentName == nullptr)
			{

				;
			}
			else
			{	
				if (strCmp(m_contentName, C.m_contentName) == 0)
				{

					record = true;
				}
			}
		}

		return record;

	}

	Canister& Canister::setContent(const char* contentName)
	{

		if (contentName == nullptr)
		{

			m_usable = false;
		}
		else if (isEmpty() == true)
		{

			setName(contentName);
		}

		else if (strCmp(m_contentName, contentName) != 0)
		{

			m_usable = false;
		}

		return *this;

	}

	void Canister::setName(const char* Cstr)
	{
		if (Cstr != nullptr)
		{

			if (m_usable != true)
			{
				;
			}
			else
			{

				delete[] m_contentName;
				m_contentName = new char[strLen(Cstr) + 1];
				strCpy(m_contentName, Cstr);
			}
		}
	}

	bool Canister::isEmpty()const
	{

		bool record = false;

		if (m_contentVolume < 0.00001)
		{

			record = true;
		}
		
		return record;
	}

	Canister::Canister()
	{

		setToDefault();
	}


	Canister::Canister(double height, double diameter, const char* contentName)
	{
		setToDefault();

		if (height < 10.0 || diameter < 10.0)
		{

			m_usable = false;
		}
		else
		{

			if (height > 40 || diameter > 30)
			{

				m_usable = false;
			}
			else
			{

				m_height = height;
				m_diameter = diameter;
				m_contentVolume = 0.0;
				setName(contentName);
			}
			
		}
	}

	Canister::Canister(const char* contentName)
	{

		setToDefault();
		setName(contentName);
	}


	Canister :: ~Canister()
	{

		delete[] m_contentName;
		m_contentName = nullptr;
	}

	double Canister::volume()const
	{

		return m_contentVolume;
	}

	double Canister::capacity()const
	{

		double count;
		count = PI * (m_height - 0.267);
		count =  count * (m_diameter / 2) * (m_diameter / 2);
		return count;
	}

	void Canister::clear()
	{

		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;

		m_usable = true;

	}

	Canister& Canister::pour(double quantity)
	{

		double sum;
		if (quantity <= capacity())
		{
			sum = quantity + volume();

			if (m_usable != true || quantity < 0.0 || sum > capacity())
			{

				m_usable = false;
			}
			else
			{

				m_contentVolume += quantity;
			}
		}
		return *this;
	}

	Canister& Canister::pour(Canister& C)
	{

		if (capacity() < 0.0 || m_contentVolume < 0.0)
		{

			m_usable = false;

			setToDefault();
			clear();
		}

		else
		{
			setContent(C.m_contentName);

			if (C.volume() <= (capacity() - volume()))
			{

				pour(C.m_contentVolume);
				C.m_contentVolume = 0.0;
			}

			else
			{
				C.m_contentVolume -= capacity() - volume();
				m_contentVolume = capacity();	
			}
		}

		return *this;
	}

	std::ostream& Canister::display() const
	{
		cout.setf(ios::fixed);
		cout.fill(' ');
		cout.width(7);

		cout.precision(1);

		cout << capacity() << "cc (" << m_height << "x";
		cout << m_diameter << ") Canister";
		cout.unsetf(ios::fixed);

		if (m_usable == false)
		{

			cout << " of Unusable content, discard!";
		}
		
		else if (m_contentName != nullptr)
		{

			cout.setf(ios::fixed);
			cout << " of ";

			cout.fill(' ');
			cout.width(7);
			cout.precision(1);

			cout<< volume() << "cc   " << m_contentName;

			cout.unsetf(ios::fixed);
		}

		return cout;
	}
}