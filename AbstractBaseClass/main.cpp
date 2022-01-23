#include <iostream>


class Vehicle
{
public:
	virtual void move() = 0;

};

class GroundVehicle : private Vehicle{};
class Car :public GroundVehicle
{
public:
	void move()
	{
		std::cout << "������ ���� �� 4-� ������" << std::endl;
	}
};

class Bike : public GroundVehicle
{
public:
	void move()
	{
		std::cout << "�������� ���� �� 2-� ������" << std::endl;
	}
};
void main()
{
	setlocale(LC_ALL, " ");
	//Vehicle v;
	/*GroundVehicle gv;*/
	Car BMW;
	BMW.move();
	Bike HarleyDavidson;
}