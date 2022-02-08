#include <iostream>

using namespace std;

class Figure
{
	unsigned int length;
	unsigned int lengthtwo;
	unsigned int radius;
public:
	virtual void Square() = 0; // Абстрактное подсчет площади
	virtual void Perimeter() = 0;
	//=========== get и set для изменения переменных==========
	unsigned int get_length()const
	{
		return length;
	}
	unsigned int get_lengthtwo()const
	{
		return lengthtwo;
	}
	void set_length(unsigned int length)
	{
		this->length = length;
	}
	void set_lengthtwo(unsigned int lengthtwo)
	{
		this->lengthtwo = lengthtwo;
	}
	//=========== get и set для изменения переменных==========
	
	//========Constructors=============
	Figure(unsigned int length) 
	{
		set_length(length);
		
	}

	Figure(unsigned int length, unsigned int lengthtwo)
	{
		set_length(length);
		set_lengthtwo(lengthtwo);
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

class Rectangle:Figure
{
public:
	Rectangle(unsigned int length,unsigned int lengthtwo):Figure(length,lengthtwo) {}
	~Rectangle(){}

	void Square()
	{ 
		int lengthSq;
		lengthSq = get_length() * get_lengthtwo();
		cout << "Squre Rectangle: " << lengthSq << endl;
	}

	void Perimeter()
	{
		int lengthPer;
		lengthPer = get_length() + get_lengthtwo();
		cout << "Perimetr Rectangle: " << lengthPer << endl;
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

		for (int l = 0; l < get_lengthtwo()/2; l++)
		{
			for (int j = 0; j < get_length() + 1; j++)
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
				if (j == get_length()) cout << Ascii[s] << endl;
			}
		}

		s = 192;
		Ascii[s] = s;
		cout << Ascii[s];

		s = 196;
		Ascii[s] = s;
		for (int i = 0; i < get_length(); i++) cout << Ascii[s];

		s = 217;
		Ascii[s] = s;
		cout << Ascii[s] << endl;

	}
};




void main()
{
	//Figure Kvadrat();
	Area Kvadrat(9);
	Kvadrat.Square();
	Kvadrat.Perimeter();
	Kvadrat.print();

	// Figure Rectangle

	Rectangle Pramougol(20, 10);
	Pramougol.Square();
	Pramougol.Perimeter();
	Pramougol.print();


}