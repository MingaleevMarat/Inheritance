//Academy
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
#define HUMAN_TAKE_PARAMETRS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETRS last_name, first_name, age



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
	Human(HUMAN_TAKE_PARAMETRS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		std::cout << "HConstructor:\t" << this << std::endl;
	}
	virtual ~Human()
	{
		std::cout << "HDestructor:\t" << this << std::endl;
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
	virtual ifstream& scan(ifstream& is)
	{
		is >> last_name >> first_name >> age;
		return is;
	}
	friend ifstream& operator>>(ifstream& is, Human& obj)
	{
		return obj.scan(is);
	}
};
#define STUDENT_TAKE_PARAMETRS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETRS speciality, group, rating, attendance
class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	//					Constructors:
	Student
	(HUMAN_TAKE_PARAMETRS,STUDENT_TAKE_PARAMETRS) :Human(HUMAN_GIVE_PARAMETRS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		std::cout << "SConstructor:\t" << this << std::endl;
	}
	~Student()
	{
		std::cout << "SDestructor:\t" << this << std::endl;
	}

	virtual std::ostream& print(std::ostream& os)const override
	{
		Human::print(os) << " ";
		os.width(10);
		os << " ";
		os << speciality;
		os << " "; 
		os<< group;
		os << " "; 
		os<< rating;
		os << " "; 
		os<< attendance;
		
		return os;
	}
	virtual std::ofstream& print(std::ofstream& os)const override
	{
		Human::print(os) << " ";
		os.width(10);
		os << speciality << group << rating << attendance;
		return os;
	}
	virtual ifstream& scan(ifstream& is)
	{
		Human::scan(is);
		is >> speciality >> group >> rating >> attendance;
		return is;
	}
	
};
#define TEACHER_TAKE_PARAMETRS const std::string& speciality, unsigned int experience
class Teacher :public Human
{
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//				Constructor
	Teacher
	(HUMAN_TAKE_PARAMETRS,TEACHER_TAKE_PARAMETRS) :Human(HUMAN_GIVE_PARAMETRS)
	{
		set_speciality(speciality);
		set_experience(experience);
		std::cout << "TConstructor:\t" << this << std::endl;
	}
	~Teacher()
	{
		std::cout << "TDestructor:\t" << this << std::endl;
	}
	//					Methods
	virtual std::ostream& print(std::ostream& os)const override
	{
		Human::print(os) << " ";
		os << speciality;
		os << " ";
		os<< experience;
		return os;
	}
	virtual std::ofstream& print(std::ofstream& os)const override
	{
		Human::print(os) << " ";
		os << right;
		os.width(10);
		os << speciality << experience;
		return os;
	}
	virtual ifstream& scan(ifstream& is)
	{
		Human::scan(is);
		is >> speciality >> experience;
		return is;
	}
		

};
#define GRADUATE_TAKE_PARAMETRS const std::string& subject
class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	//						Constructors:
	Graduate(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS, GRADUATE_TAKE_PARAMETRS) :Student(HUMAN_GIVE_PARAMETRS,STUDENT_GIVE_PARAMETRS)
	{
		set_subject(subject);
		std::cout << "GConstructor:\t" << this << std::endl;
	}
	~Graduate()
	{
		std::cout << "GDestructor:\t" << this << std::endl;
	}
	//						Methods:
	virtual std::ostream& print(std::ostream& os)const override
	{
		Student::print(os) << " ";
		os << subject;
		return os;
	}
	virtual std::ofstream& print(std::ofstream& os)const override
	{
		Student::print(os) << " ";
		os.width(5);
		os << right;
		os << subject;
		return os;
	}
	virtual ifstream& scan(ifstream& is)
	{
		Student::scan(is);
		is >> subject;
		return is;
	}
		
	
};
Human* HumanFactory(const string& type)
{
	if (type.find("Teacher") != std::string::npos)return new class Teacher("", "", 0, "", 0);
	if (type.find("Student") != std::string::npos)return new class Student("", "", 0, "", "", 0,0);
	if (type.find("Graduate") != std::string::npos)return new class Graduate("", "", 0, "", "", 0, 0,"");
}

//Resharper

//#define INHERITANCE 
//#define SAVE_TO_FILE
void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE 
	Human human("Connor", "John", 18);
	human.print();

	Student stud("Pinkman", "Jessie", 25, "Chemistry", "WW_123", 85, 95);
	stud.print();

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.print();

	Graduate grad("Shreder", "Hank", 40, "Cryminalistic", "WW_123", 90, 75, "How to catch Heizenberg");
	grad.print();
#endif // INHERITANCE 
	//generalisation(Upcast)
#ifdef SAVE_TO_FILE
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_123", 85, 95),
	new Teacher("White", "Walter", 50, "Chemistry", 25),
	new Graduate("Shreder", "Hank", 40, "Cryminalistic", "WW_123", 90, 75, "How to catch Heizenberg"),
	new Student("Vercetti","Tomas",30,"City business","Vice",98,99),
	new Teacher("Diaz", "Ricardo", 55, "Weapons distribution", 30),
	new Student("Montana", "Antonio", 30, "Cryminalistic", "Vice", 90, 80)

	};
	double total_salary = 0;
	std::cout << sizeof(group) / sizeof(Human*) << std::endl;
	for (int i = 0; i < sizeof(group)/sizeof(Human*); i++)
	{
		std::cout << typeid(*group[i]).name() << std::endl;
		std::cout << *group[i] << std::endl;
		std::cout << "\n---------------------------------------\n";
	}

	ofstream fout("file.txt");
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		fout.width(30);
		fout << left;
		fout << string(typeid(*group[i]).name()) + ": ";
		fout << *group[i] << endl;
	}
	fout.close();
	system("start notepad file.txt");
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
#endif // SAVE_TO_FILE

	Human** group = nullptr;
	int n = 0;

	ifstream fin("file.txt");
	if (fin.is_open())
	{
		string human_type;
		for (; !fin.eof(); n++)
		{
			getline(fin, human_type);
		}
		n--;
		cout << n << endl;
		group = new Human * [n] {};
		cout << fin.tellg() << endl;
		fin.clear();
		fin.seekg(0);
		cout << fin.tellg() << endl;

		for (int i = 0; i < n; i++)
		{
			getline(fin, human_type, ':');
			group[i] = HumanFactory(human_type);
			fin >> *group[i];
		}
		fin.close();
	}
	else
	{
		cerr << "Error: file not found" << endl;
	}
	for (int i = 0; i < n; i++)
	{
		cout << *group[i] << endl;
	}
	for (int i = 0; i < n; i++)
	{
		delete group[i];
	}

	delete[] group;
	

}