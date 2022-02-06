#include <iostream>

using namespace std;

class Figure
{
	unsigned int length;
	unsigned int radius;
public:
	virtual void Square() = 0; // Абстрактное подсчет площади
	virtual void Perimeter() = 0;
	//=========== get и set для изменения переменных==========
	unsigned int get_length()const
	{
		return length;
	}
	void set_length(unsigned int length)
	{
		this->length = length;
	}
	//=========== get и set для изменения переменных==========
	
	//========Constructors=============
	Figure(unsigned int length) 
	{
		set_length(length);
		
	}
		
	~Figure() {}
	//========Constructors=============
};

class Area : public Figure // Квадрат
{
public:
	
	Area(unsigned int length):Figure(length)
	{
		cout << "S-Constructor" << endl;
	}
	
	~Area(){}

	void Square() 
	{
		int lengthSq;
		lengthSq = get_length() * get_length();
		cout << "Squery area: " << lengthSq << endl;
	}

	void Perimeter()
	{
		int lengthPer;
		lengthPer=get_length() + get_length();
		cout << "Perimetr area: " << lengthPer << endl;
	}

	void print()
	{
		char Ascii[256];
		int s;
		s = 218;	
		Ascii[s] = s;
		cout << Ascii[s];

		s = 196;
		Ascii[s] = s;
		for (int i = 0; i < get_length(); i++) cout << Ascii[s];
	
		s = 191;
		Ascii[s] = s;
		cout << Ascii[s] << endl;

		s = 179;
		Ascii[s] = s;

		for (int l = 0; l < (get_length() / 2)-1; l++)
		{
			for (int j = 0; j < get_length()+1; j++)
			{
				for (int i = 0; i < get_length(); i++)
				{
					if (j == 0) {
						cout << Ascii[s];
						break;
					}
					else { cout << " "; break; }
					//cout << Ascii[s] << endl;
				}
				if (j == get_length()) cout << Ascii[s]<<endl;
			}
		}

		s = 192;
		Ascii[s] = s;
		cout <<Ascii[s];

		s = 196;
		Ascii[s] = s;
		for (int i = 0; i < get_length(); i++) cout << Ascii[s];

		s = 217;
		Ascii[s] = s;
		cout << Ascii[s]<<endl;

		cout << "Side Length: " << get_length()<<endl;

		
	}

};





void main()
{
	//Figure Kvadrat();
	Area Kvadrat(19);
	Kvadrat.Square();
	Kvadrat.Perimeter();
	Kvadrat.print();


}