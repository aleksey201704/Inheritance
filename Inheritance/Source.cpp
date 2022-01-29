#include <iostream>
#include<string>

using namespace std;

class Humen
{
protected:
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

	Humen(const std::string& last_name, const std::string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "H-Constructo:" << this << endl;
	}
	~Humen()
	{
		cout << "H-Desructor" << this << endl;
	}

	void print()const
	{
		cout << last_name << " " << first_name << " " << age << " лет \n";
	}

};

class Student : public Humen
{
protected:
	std::string speciality;
	std::string group;
	float rating;
	float attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	float get_attendance()const
	{
		return attendance;
	}

	float get_rating()const
	{
		return rating;
	}

	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}

	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(float rating)
	{
		this->rating = rating;
	}
	void set_attendance(float attendance)
	{
		this->attendance = attendance;
	}

	Student(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, float rating, float attendance
		
	) :Humen(last_name,first_name,age)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "S-Constructor: " << this << endl;
	}
	~Student()
	{
		cout <<"S-Destructor" << this<<endl ;
	}

	void print()const
	{
		Humen::print();
		cout << speciality << " " << group << " " << rating 
			<< " " << attendance << endl;
	}
};

class Teacher :public Humen
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
	
	Teacher(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, unsigned int experience
	): Humen(last_name, first_name,age )
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor: " << this << endl;
	}
	~Teacher() 
	{
		cout << "DestructorT" << endl;
	}

	void print()const
	{
		Humen::print();
		cout << speciality << " " << experience << endl;
	}

};

class Gradute :public Student
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

	Gradute(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, float rating, float attendance,
		const std::string& subject
	) :Student(last_name, first_name, age, speciality, group, rating, attendance)
	{
		set_subject(subject);
		cout << "GConstructor: " << this << endl;
	}
	~Gradute()
	{
		cout << "GDestrcuctor " << this << endl;
	}

	void print()const
	{
		Student::print();
		cout << subject << endl;
	}

};

void main()
{
	setlocale(LC_ALL,"");

	Humen human("Tupenko", "Vasya ", 23);
	human.print();
	Student student("Prim", "Dinamo", 20, "RPO", "SPD_121", 90, 85);
	student.print();

	Teacher teacher("White", "Walter", 50, "Chemisrt", 20);
	teacher.print();
		
	Gradute gradute("Scrader", "Hank", 40, "Criminal", "SBD-121", 90, 85, "DIPLOM");
	gradute.print();
	

}