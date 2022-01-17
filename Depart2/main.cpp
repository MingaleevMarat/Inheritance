#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age	//Принимаемые переметры конструктора Human
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//					Constructors:
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//				Methods:
	friend std::ostream& operator<<(std::ostream& os, const Human& obj)
	{
		return obj.print(os);
	}
	virtual std::ostream& print(std::ostream& os)const
	{
		/*os << last_name << " " << first_name << " " << age << " лет" << endl;
		return os;*/
		
		os << left;
		os.width(10);
		os << last_name;
		os.width(10);
		os << first_name;
		os.width(3);
		os << age << " лет";
		return os;
	}
friend ofstream& operator<<(std::ofstream& os, const Human& obj)
{
	return obj.print(os);
}
	virtual std::ofstream& print(std::ofstream& os)const
	{
		/*os << last_name << " " << first_name << " " << age << " лет" << endl;
		return os;*/

		os << left;
		os.width(10);
		os << last_name;
		os.width(10);
		os << first_name;
		os.width(3);
		os << age;
		return os;
	}
};
#define EMPLOYEE_TAKE_PARAMETERS	const std::string& position
#define EMPLOYEE_GIVE_PARAMETERS	position

class Employee :public Human	//Наследование
{
	std::string position;
public:
	const std::string& get_position()const
	{
		return position;
	}
	void set_position(const std::string& position)
	{
		this->position = position;
	}
	virtual double get_salary()const = 0;

	Employee(HUMAN_TAKE_PARAMETERS, EMPLOYEE_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)//Делегирование
	{
		set_position(position);
		cout << "EConstructor:\t" << this << endl;
	}
	~Employee()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	virtual std::ostream& print(std::ostream& os)const override
	{
		Human::print(os)<<" ";
		os.width(10);
		os << position;
		return os;
	}
	virtual std::ofstream& print(std::ofstream& os)const override
	{
		Human::print(os) << " ";
		os.width(10);
		os << position;
		return os;
	}

};
#define PERMANENT_EMPLOYEE_TAKE_PARAMETERS double salary
#define PERMANENT_EMPLOYEE_GIVE_PARAMETERS salary
class PermanentEmployee : public Employee
{
	double salary;
public:
	double get_salary()const
	{
		return salary;
	}
	void set_salary(double salary)
	{
		this->salary = salary;
	}
	PermanentEmployee(HUMAN_TAKE_PARAMETERS, EMPLOYEE_TAKE_PARAMETERS, PERMANENT_EMPLOYEE_TAKE_PARAMETERS) : Employee(HUMAN_GIVE_PARAMETERS, EMPLOYEE_GIVE_PARAMETERS)
	{
		set_salary(salary);
		std::cout << "PEConstructor:\t" << this << std::endl;
	}
	~PermanentEmployee()
	{
		std::cout << "PEDestructor:\t" << this << std::endl;
	}
	//             Methods:
		virtual std::ostream& print(std::ostream& os)const override
		{
			Employee::print(os) << " ";
			
			os << salary;
			return os;
		}
		virtual std::ofstream& print(std::ofstream& os)const override
		{
			Employee::print(os) << " ";
			os << right;
			os.width(10);
			os << salary;
			return os;
		}
};
#define HOURLY_EMPLOYEE_TAKE_PARAMETERS double rate, int hours
#define HOURLY_EMPLOYEE_GIVE_PARAMETERS rate, hours
class HourlyEmployee :public Employee
{
	double rate;
	int hours;
public:
	double get_rate()const
	{
		return rate;
	}
	int get_hours()const
	{
		return hours;
	}
	double get_salary()const
	{
		return rate* hours;
	}
	void set_rate(double rate)
	{
	    this->rate = rate;
	}
	void set_hours(int hours)
	{
		this->hours = hours;
	}
	
	//                Constructors:
	HourlyEmployee(
		HUMAN_TAKE_PARAMETERS, EMPLOYEE_TAKE_PARAMETERS,HOURLY_EMPLOYEE_TAKE_PARAMETERS)
		: Employee(HUMAN_GIVE_PARAMETERS, EMPLOYEE_GIVE_PARAMETERS)
	{
		set_rate(rate);
		set_hours(hours);
		std::cout << "HEConstructor:\t" << this << std::endl;
	}
	~HourlyEmployee()
	{
		std::cout << "HEDestructor:\t" << this << std::endl;
	}
	//              Methods:
	virtual std::ostream& print(std::ostream& os)const override
	{
		Employee::print(os) << " ";
		os << "Тариф: ";
		os.width(5);
		os<<right;
		os<< rate << ", отработано:";
		os.width(3);
			os<< hours <<", итого: "<<get_salary();	
		return os;
	}
	virtual std::ofstream& print(std::ofstream& os)const override
	{
		Employee::print(os) << " ";
		os.width(5);
		os << right;
		os << rate;
		os.width(3);
		os << hours;
		return os;
	}
};


void main()
{
	setlocale(LC_ALL, "");
	Employee* department[] =
	{
		new PermanentEmployee ("Hudson","Steven",29,"Programmer",70000),
		new PermanentEmployee ("Horton","Alannah",25,"Programmer",50000),
		new HourlyEmployee("Cain","Michael",32,"Programmer",700,8),
		new HourlyEmployee("Hicks","Kristina",27,"Programmer",500,8)
	};
	double total_salary = 0;
	std::cout << sizeof(department) / sizeof(Employee*) << std::endl;
	for (int i = 0; i < sizeof(department) / sizeof(Employee*); i++)
	{
		std::cout << typeid(*department[i]).name() << std::endl;
		//department[i]->print();
		std::cout << *department[i] << std::endl;
		
		total_salary += department[i]->get_salary();
		std::cout << "\n---------------------------------------\n";
	}
	std::cout << "Общая зарплата всего отдела: " << total_salary << std::endl;
	std::cout << "\n---------------------------------------\n";

	ofstream fout("file.txt");
	for (int i = 0; i < sizeof(department) / sizeof(Employee*); i++)
	{
		fout.width(30);
		fout << left;
		fout << string(typeid(*department[i]).name()) + ": ";
		fout<< *department[i] << endl;
	}
	fout.close();
	system("start notepad file.txt");
	for (int i = 0; i < sizeof(department) / sizeof(department[0]); i++)
	{
		delete department[i];
	}
}
