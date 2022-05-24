
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>

#include "MotorVehicle.h"
#include "cstring.h"

using namespace std;

namespace sdds {

	MotorVehicle::MotorVehicle(const char plateNum[], int yearOfReg) 
	{
		strCpy(m_numPlate, plateNum);
		strCpy(m_addressOfVehicle, "Factory");
		m_yearOfReg = yearOfReg;
	}

	void MotorVehicle:: moveTo(const char* movingAddress)
	{
		if (strCmp(m_addressOfVehicle, movingAddress))
		{

			cout << "|";
			cout.setf(ios::right);
			cout.width(8);
			cout.fill(' ');
			cout << m_numPlate << "|" << " |";
			cout.width(20);
			cout.fill(' ');
			cout << m_addressOfVehicle << " ---> ";
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(20);
			cout.fill(' ');
			cout << movingAddress << "|" << endl;
			strCpy(m_addressOfVehicle, movingAddress);
		}
	}

	std::ostream& MotorVehicle::write(std::ostream& os)const 
	{

		os << "| " << m_yearOfReg << " | " << m_numPlate << " | " << m_addressOfVehicle;

		return os;
	}

	std::istream& MotorVehicle::read(std::istream& in) 
	{
		
		string plateNum;

		cout << "Built year: ";
		in >> m_yearOfReg;
		cout << "License plate: ";
		in >> m_numPlate;
		cout << "Current location: ";
		in >> m_addressOfVehicle;

		return in;
	}

	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& vehicle) 
	{
		vehicle.write(ostr);

		return ostr;
	}
	std::istream& operator>>(std::istream& istr, MotorVehicle& vehicle) 
	{
		vehicle.read(istr);

		return istr;
	}	

}