#include <string>
#include <iostream>

using namespace std;

class Departament 
{
	std::string nameDep;
public:
	const std::string& get_nameDep()const
	{
		return nameDep;
	}
	void set_nameDep(const std::string& nameDep)
	{
		this->nameDep = nameDep;
	}
	
	Departament (const std::string& nameDep)
	{
		set_nameDep(nameDep);
	}

	~Departament() {};


};

class Human
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

	Human(const std::string& last_name, const std::string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		/*cout << "H-Constructo:" << this << endl;*/
	}
	~Human()
	{
		/*cout << "H-Desructor" << this << endl;*/
	}

	void print()const
	{
		cout << last_name << " " << first_name << " " << age << " лет \n";
	}

};

class PermanentEmployee: public Departament,  public Human // с постоянной оплатой
{

	int PerPaymant;
public:
	//==========Set Get==============
	int get_PerPaymant()const
	{
		return PerPaymant;
	}
	void set_PerPaymant(int PerPaymant)
	{
		this->PerPaymant = PerPaymant;
	}
	//==========Constructors==========
	
	PermanentEmployee (
		const std::string& nameDep,
		const std::string& last_name, const std::string& first_name, unsigned int age,
		int PerPaymant
	):Departament(nameDep),Human(last_name,first_name,age)
	{
		set_PerPaymant(PerPaymant);
	}
	~PermanentEmployee(){}
	
	//==========Method================
	void print()const
	{
		Human::print();
		cout << "Постоянная зарплата: " << PerPaymant << endl;
	}
};

class HourlyEmployee : public Departament, public Human // (с почасовой оплатой)
{
	int HEmplo; // Оплата за час
	int Tday; // Количество часов отработанных
public:
	//==========Set Get==============
	int get_HEmplo()const
	{
		return HEmplo;
	}
	int get_Tday()const
	{
		return Tday;
	}
	void set_HEmplo(int HEmplo)
	{
		this->HEmplo = HEmplo;
	}
	void set_Tday(int Tday)
	{
		this->Tday = Tday;
	}
	//==========Constructors==========
	HourlyEmployee(const std::string& nameDep,
		const std::string& last_name, const std::string& first_name, unsigned int age,
		int HEmplo, int Tday
	) :Departament(nameDep) ,Human(last_name, first_name, age)
	{
		set_HEmplo(HEmplo);
		set_Tday(Tday);
	}
	~HourlyEmployee(){}
	//==========Method================
	int Paymant()const // Зарплата почасовой оплаты
	{
		int pay;
		pay = HEmplo * Tday;
		return pay;
	}

	void print()const
	{
		Human::print();
		cout << "Час оплата: " << HEmplo << " Количесвто часов: " << Tday << endl;
		cout <<"Зарплата: " << Paymant()<<endl;
	}
};

class TotalDepartament: public PermanentEmployee, public HourlyEmployee
{
	int sum;
public:
	int get_sum()const
	{
		return sum;
	}
	void set_sum(int sum)
	{
		this->sum = sum;
	}
	
	~TotalDepartament() {};
	

	int TotalSum()
	{
		sum = get_PerPaymant() + HourlyEmployee::Paymant();
		return sum;
	}
};

void main()
{
	setlocale(LC_ALL,"");
	
	PermanentEmployee perHuman1("Departament","Dark", "Folor", 35, 5000);
	HourlyEmployee perHuman2("Departament", "Black", "Raid", 45, 10, 5);


	Human* Depart[] =
	{ 
		new PermanentEmployee ("Departament","Dark", "Folor", 35, 5000),
		new HourlyEmployee ("Departament","White", "Folor", 40,10,2),
		new HourlyEmployee ("Departament","Reder", "Rafain", 18,10,4),

	};

		

	/*perHuman1.print();
	perHuman2.print();*/
}

