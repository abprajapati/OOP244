#pragma once

#ifndef _MOTORVEHICLE_H_
#define _MOTORVEHICLE_H_

#include <iostream>

namespace sdds {

	class MotorVehicle {

		char m_numPlate[9];
		char m_addressOfVehicle[64];
		int m_yearOfReg;

	public:
		MotorVehicle(const char plateNum[], int yearOfReg);

		void moveTo(const char* movingAddress);

		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};

	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& vehicle);
	std::istream& operator>>(std::istream& istr, MotorVehicle& vehicle);
}

#endif // !_MOTORVEHICLE_H_
