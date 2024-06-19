
#include"Fraction.h"
using namespace std;

//Внешние функции
bool operator ==(Fraction& obg1, Fraction& obg2) //дроби будем изменять - сокращать
{
	obg1.reduceFraction();
	obg2.reduceFraction();
	return obg1.getNumerator() == obg2.getNumerator() && obg1.getDenominater() == obg2.getDenominater();
}
bool operator !=(Fraction& obg1, Fraction& obg2) //дроби будем изменять - сокращать
{
	obg1.reduceFraction();
	obg2.reduceFraction();
	return obg1.getNumerator() != obg2.getNumerator() || obg1.getDenominater() != obg2.getDenominater();
}
bool operator > (const Fraction& obg1, const Fraction& obg2)
{
	return obg1.getNumerator() * obg2.getDenominater() > obg2.getNumerator() * obg1.getDenominater();
}
bool operator < (const Fraction& obg1, const Fraction& obg2)
{
	return obg1.getNumerator() * obg2.getDenominater() < obg2.getNumerator() * obg1.getDenominater();
}
bool operator >= (const Fraction& obg1, const Fraction& obg2)
{
	return obg1.getNumerator() * obg2.getDenominater() > obg2.getNumerator() * obg1.getDenominater();
}
bool operator <= (const Fraction& obg1, const Fraction& obg2)
{
	return obg1.getNumerator() * obg2.getDenominater() <= obg2.getNumerator() * obg1.getDenominater();
}

// функция, которая возвращает дробь, результат сложения дробей
Fraction operator +(const Fraction& obg1, const Fraction& obg2)
{
	Fraction Result;
	// числитель и знаменатель: по математическому правилу
	Result.setNumerator(obg1.getNumerator() * obg2.getDenominater() + obg2.getNumerator() * obg1.getDenominater());
	Result.setDenominater(obg1.getDenominater() * obg2.getDenominater());
	Result.reduceFraction(); //сокращаем
	//cout << "+Assigment: \t\t" << &Result << "\n";
	return Result;
}
// результат вычитания дробей
Fraction operator -(const Fraction& obg1, const Fraction& obg2)
{
	Fraction Result;
	// числитель и знаменатель: по математическому правилу
	Result.setNumerator(obg1.getNumerator() * obg2.getDenominater() - obg2.getNumerator() * obg1.getDenominater());
	Result.setDenominater(obg1.getDenominater() * obg2.getDenominater());
	Result.reduceFraction(); //сокращаем
	//cout << "-Assigment: \t\t" << &Result << "\n";
	return Result;
}
// результат произведения дробей
Fraction operator *(const Fraction& obg1, const Fraction& obg2)
{
	Fraction Result;
	// числитель и знаменатель: по математическому правилу
	Result.setNumerator(obg1.getNumerator() * obg2.getNumerator());
	Result.setDenominater(obg1.getDenominater() * obg2.getDenominater());
	Result.reduceFraction(); //сокращаем    
	//cout << "*Assigment: \t\t" << &Result << "\n";
	return Result;
}
// результат деления дробей
Fraction operator /(const Fraction& obg1, const Fraction& obg2)
{
	Fraction Result;
	if (obg2.getNumerator() == 0)
	{
		cout << " Error \n division by zero (Деление на ноль - операция не выполнена)\n";
	}
	// числитель и знаменатель: по математическому правилу
	else
	{
		Result.setNumerator(obg1.getNumerator() * obg2.getDenominater());
		Result.setDenominater(obg1.getDenominater() * obg2.getNumerator());
		Result.reduceFraction(); //сокращаем    
	}
	//cout << "/Assigment: \t\t" << &Result << "\n";
	return Result;
}

std::ostream& operator << (std::ostream& os, const Fraction& obg)
{
	if (obg.getNumerator() / obg.getDenominater() != 0)
		os << obg.getNumerator() / obg.getDenominater() << " ";

	// выводим дробную часть, если она есть 
	// провераем числитель дробной части, если =0 то дробной части нет
	if (obg.getNumerator() - (obg.getNumerator() / obg.getDenominater()) * obg.getDenominater() != 0)
	{
		//Если перед этим была целая часть, выводим скобки
		if (obg.getNumerator() / obg.getDenominater() > 0) { os << "("; }
		os << obg.getNumerator() % obg.getDenominater() << "/" << obg.getDenominater(); //Дробная часть
		if (obg.getNumerator() / obg.getDenominater() > 0) { os << ")"; }
	}
	return os;
}
std::istream& operator >> (std::istream& is, Fraction& obg)
{
	int numerator;
	int denominater;
	is >> numerator >> denominater;
	obg.setNumerator(numerator);
	obg.setDenominater(denominater);
	return is;
}


//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS_CHECK
//#define STREAMS_CHECK
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHER
//#define CONVERSIONS_TASK_1
#define CONVERSIONS_TASK_2


int main()
{
	setlocale(LC_ALL, "Russian");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;		//Default constructor
	A.print();

	Fraction B = 5;	//Single-argument constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(3, 4);
	D.print();

	Fraction E = D;
	E.print();

	Fraction F;
	F = E;
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	//double a = 2;
//double b = 3;
//double c = a * b;

	Fraction A(3, 4);
	A.print();

	Fraction B(4, 5);
	B.print();

	/*Fraction C = A / B;
	C.print();
	(C++).print();
	C.print();

	A.print();
	B.print();*/

	A *= B;		//A = A*B;
	A.print();

	A /= B;
	A.print();

	//int a = 2;
	//int* pa = &a;
	////a = pa;
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++a;
	////a++++++++++++++++++++++++++++++++++++++++++++++++++++++++++;
	//cout << a << endl;  
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef COMPARISON_OPERATORS_CHECK
	//cout << (2 == 3) << endl;
	cout << (Fraction(1, 3) >= Fraction(5, 11)) << endl;
#endif // COMPARISON_OPERATORS_CHECK

#ifdef STREAMS_CHECK
	Fraction A(3, 4);
	cout << "Введите простую дробь: "; cin >> A;

	cout << A << endl;
#endif // STREAMS_CHECK

#ifdef TYPE_CONVERSIONS_BASICS
	//(type)value;	C-like notation		(C-подобная форма записи)
//type(value);	Functional notation	(Функицональная форма записи)
//int a = 2.5;
//C4244: Conversion from 'type_1' to 'type_2', possible loss of data;
//		l-value = r-value;

	int a = 2;		//No conversions
	double b = 3;	//Conversion from less to more
	int c = b;		//Conversion from more to less without data loss
	int d = 2.5;	//Conversion from more to less with data loss
	cout << sizeof(int) << endl;
	cout << sizeof(double) << endl;
#endif // TYPE_CONVERSIONS_BASICS

#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
	/*
----------------------------------
1. From other to Class:
	- Single-argument constructor;
	- CopyAssignment;
2. From Class to other;
----------------------------------
*/
	Fraction A = (Fraction)5;	//Convertion from 'int' to 'Fraction'
	//Single-Argument constructor
	cout << A << endl;

	cout << double_delimiter << endl;

	Fraction B;	//Default constructor
	cout << delimiter << endl;
	B = Fraction(8);		//Convertion from 'int' to Fraction
	//Single-Argument constructor
	//Copy assignment
	cout << delimiter << endl;
	cout << B << endl;

	cout << double_delimiter << endl;
#endif // CONVERSIONS_FROM_OTHER_TO_CLASS

#ifdef CONVERSIONS_TASK_1
	Fraction A(3, 4);
	cout << A << endl;

	//int a = (int)A;
	double a = (double)A;
	cout << a << endl;

#endif // CONVERSIONS_TASK_1

#ifdef CONVERSIONS_TASK_2
	Fraction B = 2.76;
	cout << B << endl;
#endif // CONVERSIONS_TASK_2


	//cout << "Первая, вторая и третья дроби.\n";
	//Fraction drob1;
	//drob1.printFraction();
	//drob1.printProperFraction();

	Fraction drob2;
	double a3 = sqrt(2);
	cout << a3 << "\n";
	drob2 = Fraction(a3);
	//drob2.printProperFraction();
	drob2.printFraction();
	int a1 = (int)drob2;
	double d = (double)drob2;
	cout << a1 << "\n";
	cout << d << "\n";
	cout << (double)2 / 3 << "\n";

	//drob2 += drob1;
	//drob2.printFraction();
	////drob2.printProperFraction();
	//Fraction drob3(2, 3);
	//drob3.printFraction();
	//
	//drob2 /= drob3;
	//drob2.printFraction();
	//
	//drob2 /= 0;
	//drob2.printFraction();
	//cout << "\n" << (drob2 >= drob2) << "\n";
	//
	//drob3.printProperFraction();
	//
	//cout << "Четвертая дробь.\n";
	//Fraction drob4 = drob3 + drob2;
	//cout << "\nЧетвертая дробь, как сумма третьей и второй.\n";
	//drob4.printFraction();
	//drob4.printProperFraction();
	//
	////cout << "Пятая дробь.\n";
	//Fraction drob5 = drob4 - drob1;
	//cout << "\nПятая дробь, как разность четвертой и первой.\n";
	//drob5.printFraction();
	//drob5.printProperFraction();
	//
	////cout << "Шестая дробь.\n";
	//Fraction drob6 = drob3 * drob2;
	//cout << "\nШестая дробь, как произведение третьей и второй.\n";
	//drob6.printFraction();
	//
	////cout << "Седьмая дробь.\n";
	//Fraction drob7;
	//drob7 = drob4 / drob5;
	//cout << "\nСедьмая дробь, как частное четвертой и пятой.\n";
	//drob7.printFraction();
	//
	//cout << "\nВосьмая дробь.\n";
	//Fraction drob8(-200, -40);
	//drob8.printFraction();
	//cout << "сокращаем\n";
	//drob8.reduceFraction();
	//drob8.printFraction();
	//
	//cout << "\nДевятая дробь, без дробной части.\n";
	//Fraction drob9(-200, -200);
	//drob9.printFraction();
	//drob9.printProperFraction();
	//cin >> drob9;
	//drob9.printFraction();
	//cout << drob3 << "\n\n";
}
