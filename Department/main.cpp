#include <iostream>
#define $ this->
class Employee
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_last_name() const
	{
		return last_name;
	}
	const std::string& get_first_name() const
	{
		return first_name;
	}
	unsigned int get_age()
	{
		return age;
	}
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()
	{
		return experience;
	}
	void set_last_name(const std::string& last_name)
	{
		$ last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		$ first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		$ age = age;
	}
	void set_speciality(const std::string& speciality)
	{
		$ speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		$ experience = experience;
	}

	//            Constructors:
	Employee(const std::string& last_name, const std::string& first_name, unsigned int age, const std::string& speciality, unsigned int experience)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		set_speciality(speciality);
		set_experience(experience);
		std::cout << "EConstructor:\t" << this << std::endl;
	}

	virtual ~Employee()
	{
		std::cout << "EDestructor:\t" << this << std::endl;
	}

	//               Methods:
	virtual void print()const
	{
		std::cout << last_name << " " << first_name << " " << age << " лет " << speciality << " " << experience << std::endl;
	}
};

class employee1 :public Employee
{
	int hourly_chargeable;
public:
	int get_hourly_chargeable()
	{
		return hourly_chargeable;
	}
	void set_hourly_chargeable(int hourly_chargeable)
	{
		$ hourly_chargeable = hourly_chargeable;
	}
	//                Constructors:
	employee1(const std::string& last_name, const std::string& first_name, unsigned int age, const std::string& speciality, unsigned int experience, int hourly_chargeable) : Employee(last_name, first_name, age, speciality, experience)
	{
		set_hourly_chargeable(hourly_chargeable);
		std::cout << "e1Constructor:\t" << this << std::endl;
	}
	~employee1()
	{
		std::cout << "e1Destructor:\t" << this << std::endl;
	}
	//              Methods:
	void print()const
	{
		Employee::print();
		std::cout << hourly_chargeable << " рублей в час" << std::endl;
	}
};

class employee2 :public Employee
{
	int permanent_salary;
public:
	int get_permanent_salary()
	{
		return permanent_salary;
	}
	void set_permanent_salary(int permanent_salary)
	{
		$ permanent_salary = permanent_salary;
	}
	//           Constructors:
	employee2(const std::string& last_name, const std::string& first_name, unsigned int age, const std::string& speciality, unsigned int experience, int permanent_salary) : Employee(last_name, first_name, age, speciality, experience)
	{
		set_permanent_salary(permanent_salary);
		std::cout << "e2Constructor:\t" << this << std::endl;
	}
	~employee2()
	{
		std::cout << "e2Destructor:\t" << this << std::endl;
	}
	//             Methods:
	void print()const
	{
		Employee::print();
		std::cout << permanent_salary << " рублей в мес€ц" << std::endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Employee* group[] =
	{
		new employee1("Hudson","Steven",29,"Programmer",9,200),
		new employee1("Horton","Alannah",25,"Programmer",7,100),
		new employee2("Cain","Michael",32,"Programmer",14,70000),
		new employee2("Hicks","Kristina",27,"Programmer",9,60000)
	};
	std::cout << sizeof(group) / sizeof(Employee*) << std::endl;
	for (int i = 0; i < sizeof(group) / sizeof(Employee*); i++)
	{
		std::cout << typeid(*group[i]).name() << std::endl;
		group[i]->print();
		std::cout << "\n---------------------------------------\n";
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
}