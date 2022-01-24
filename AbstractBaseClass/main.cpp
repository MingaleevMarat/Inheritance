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

class WaterVehicle : private Vehicle{};
class SpeedBoat : public WaterVehicle
{
public:
	void move()
	{
		std::cout << "����� ������ �� ����" << std::endl;
	}
};
class Yacht: public WaterVehicle
{
public:
	void move()
	{
		std::cout << "���� ������ �� ����" << std::endl;
	}
};
class AirVehicle : private Vehicle {};
class Airplane : public AirVehicle
{
public:
	void move()
	{
		std::cout << "������ ����� ������� ��������(�������)" << std::endl;
	}
};
class Helicopter : public AirVehicle
{
public:
	void move()
	{
		std::cout << "������� ����� ��������� �������(�������)" << std::endl;
	}
};
void main()
{
	setlocale(LC_ALL, "rus");
	//Vehicle v;
	/*GroundVehicle gv;*/
	Car BMW;
	BMW.move();
	Bike HarleyDavidson;
	HarleyDavidson.move();
	SpeedBoat Beneteau_Antares_9_OB;
	Beneteau_Antares_9_OB.move();
	Yacht Bertram_61;
	Bertram_61.move();
	Airplane Extra_EA_300;
	Extra_EA_300.move();
	Helicopter Bell_407GXP;
	Bell_407GXP.move();
}