#pragma once

#ifndef _TRUCK_H_
#define _TRUCK_H_

#include <iostream>
#include "MotorVehicle.h"

namespace sdds {

	class Truck : public MotorVehicle 
	{

		double loadCapcity;
		double cWeight;

	public:

		Truck(const char numPlate[], int yearOfReg, double capOfTruck, const char curAddress[]);

		bool addCargo(double cargo);
		bool unloadCargo();

		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};

	std::ostream& operator<<(std::ostream& ostr, const Truck& truckVehicle);
	std::istream& operator>>(std::istream& istr, Truck& truckVehicle);
}

#endif // !_MOTORVEHICLE_H_
