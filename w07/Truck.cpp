

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>

#include "MotorVehicle.h"
#include "Truck.h"

using namespace std;

namespace sdds {

	Truck::Truck(const char numPlate[], int yearOfReg, double capOfTruck, const char curAddress[]) : MotorVehicle(numPlate, yearOfReg) 
	{

		loadCapcity = capOfTruck;
		cWeight = 0;
		MotorVehicle::moveTo(curAddress);
	}

	bool Truck::addCargo(double cargo) {

		bool record;
		double CargoLoad = cWeight + cargo;

		if (cWeight != loadCapcity)
		{

			if (CargoLoad < loadCapcity)
			{

				cWeight += cargo;
			}
			else
			{

				cWeight = loadCapcity;
			}

			record = true;
		}
		else
		{

			record = false;
		}
		return record;
	}

	bool Truck::unloadCargo() {

		bool record;

		if (cWeight != 0) {
			cWeight = 0;
			record = true;
		}
		else
		{
			record = false;
		}
		
		return record;
	}

	std::ostream& Truck::write(std::ostream& os)const {

		MotorVehicle::write(os);
		os << " | " << cWeight << "/" << loadCapcity;

		return os;
	}

	std::istream& Truck::read(std::istream& in) {

		MotorVehicle::read(in);
		cout << "Capacity: ";
		cin >> loadCapcity;
		cout << "Cargo: ";
		cin >> cWeight;
		return in;
	}


	std::ostream& operator<<(std::ostream& ostr, const Truck& truckVehicle) {

		truckVehicle.write(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Truck& truckVehicle) {

		truckVehicle.read(istr);
		return istr;
	}
}