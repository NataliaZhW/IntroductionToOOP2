// Fraction1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#define delimiter			"\n-----------------------------------\n"
#define double_delimiter	"\n===================================\n"


class Fraction;
bool operator ==(Fraction& obg1, Fraction& obg2);
bool operator !=(Fraction& obg1, Fraction& obg2);
bool operator > (const Fraction& obg1, const Fraction& obg2);
bool operator < (const Fraction& obg1, const Fraction& obg2);
bool operator >= (const Fraction& obg1, const Fraction& obg2);
bool operator <= (const Fraction& obg1, const Fraction& obg2);

Fraction operator +(const Fraction& obg1, const Fraction& obg2);
Fraction operator -(const Fraction& obg1, const Fraction& obg2);
Fraction operator *(const Fraction& obg1, const Fraction& obg2);
Fraction operator /(const Fraction& obg1, const Fraction& obg2);



class Fraction // Дробь
{
private:
	int numerator; // Числитель
	int denominater; // Знаменатель
public:
	//конструкторы и деструктор
	Fraction() { numerator = denominater = 1; cout << "DefaultConstructop: \t" << this << "\n"; } //
	explicit Fraction(int numerator)
	{
		setNumerator(numerator);
		denominater = 1;
		cout << "1ArgConstructop: \t" << this << "\n";
	}
	Fraction(double numeratorObg)
	{
		this->denominater = 1e+7;
		numerator = denominater * numeratorObg;
		cout << (int)1e+9 << "\n";

		//this->denominater = 1;		
		//for (int i = 1; (int)numeratorObg != numeratorObg && i < 10; i++, denominater *= 10, numeratorObg *= 10) {};
		//// тоже самое, чтобы посмотреть расчеты в отладчике
		///*for (int i = 1; (int)numeratorObg != numeratorObg && i < 10; )
		//{
		//	i++;
		//	denominater *= 10;
		//	numeratorObg *= 10;
		//};*/
		//numerator = (int)numeratorObg;//в этот момент уже нет дробной части
		reduceFraction();
		cout << "1ArgConstructop double: \t" << this << "\n";
	}
	Fraction(int numerator, int denominater)
	{
		setNumerator(numerator);
		setDenominater(denominater);
		cout << "2ArgConstructop: \t" << this << "\n";
	}
	Fraction(const Fraction& obg)
	{
		this->numerator = obg.numerator;
		this->denominater = obg.denominater;

	}
	~Fraction() { cout << "Destructop: \t\t" << this << "\n"; } //

	// Геттеры и сеттеры
	int getNumerator() const { return numerator; }
	void setNumerator(int numerator) { this->numerator = numerator; }
	int getDenominater() const { return denominater; }
	// с проверкой на 0
	void setDenominater(int denominater)
	{
		if (denominater != 0) {
			this->denominater = denominater;
		}
		else
		{
			cout << " Error:  denominater should not be equal 0 (!=0) (Не должен быть равен 0)\n";
			this->denominater = 1;
		}
	}

	//Операторы
	explicit operator int() const { return (int)(numerator / denominater); }
	explicit operator double() const { return (double)numerator / (double)denominater; }


	Fraction& operator =(const Fraction& obg)
	{
		this->numerator = obg.numerator;
		this->denominater = obg.denominater;
		//cout << "CopyAssigment: \t\t" << this << "\n";
		return *this;
	}
	Fraction& operator =(int obg)
	{
		this->numerator = obg;
		this->denominater = 1;
		//cout << "CopyAssigment: \t\t" << this << "\n";
		return *this;
	}
	Fraction& operator =(double obg)
	{
		Fraction temp(obg);
		return *this;
	}


	Fraction& operator +=(int obg)
	{
		numerator += (denominater * obg);
		reduceFraction();
		//cout << "Assigment +=: \t\t" << this << "\n";
		return *this;
	}
	Fraction& operator -=(int obg)
	{
		numerator -= denominater * obg;
		reduceFraction();
		//cout << "Assigment -=: \t\t" << this << "\n";
		return *this;
	}
	Fraction& operator *=(int obg)
	{
		numerator = numerator * obg;
		//cout << "Assigment *=: \t\t" << this << "\n";
		return *this;
		reduceFraction();
	}
	// с проверкой на 0
	Fraction& operator /=(int obg)
	{
		if (obg != 0) {
			denominater = denominater * obg;
			reduceFraction();
			//cout << "Assigment /*: \t\t" << this << "\n";			
		}
		else
		{
			cout << " Error: divizion by zero \n Деление на ноль, операция не выполнена!\n";
		}
		return *this;
	}


	Fraction& operator +=(double numeratorObg)
	{
		Fraction temp(numeratorObg);
		this->numerator = this->numerator * temp.getDenominater() + temp.getNumerator() * this->denominater;
		this->denominater = this->denominater * temp.getDenominater();
		reduceFraction(); //сокращаем
		return *this;
	}
	Fraction& operator -=(double numeratorObg)
	{
		Fraction temp(numeratorObg);
		this->numerator = this->numerator * temp.getDenominater() + temp.getNumerator() * this->denominater;
		this->denominater = this->denominater * temp.getDenominater();
		reduceFraction(); //сокращаем
		return *this;
	}
	Fraction& operator *=(double numeratorObg)
	{
		Fraction temp(numeratorObg);
		this->numerator *= temp.getNumerator();
		this->denominater *= temp.getDenominater();
		reduceFraction();
		return *this;
	}
	// с проверкой на 0
	Fraction& operator /=(double numeratorObg)
	{
		if (numeratorObg != 0) {
			Fraction temp(numeratorObg);
			this->numerator *= temp.getDenominater();
			this->denominater *= temp.getNumerator();
			reduceFraction();

			// // Первые варианты то же самое, но без временного объекта
			//int denominatorObg = 1;
			//for (; (int)numeratorObg != numeratorObg; denominatorObg *= 10, numeratorObg *= 10) {};

			//reduceFraction();
			//this->numerator *= denominatorObg;
			//this->denominater *= (int)numeratorObg;
		}
		else
		{
			cout << " Error: divizion by zero \n Деление на ноль, операция не выполнена!\n";
		}
		//cout << "Assigment /=: \t\t" << this << "\n";
		return *this;
	}


	Fraction& operator +=(Fraction& obg)
	{
		//reduceFraction();//сокращаем
		//obg.reduceFraction();//сокращаем
		this->numerator = this->numerator * obg.getDenominater() + obg.getNumerator() * this->denominater;
		this->denominater = this->denominater * obg.getDenominater();
		reduceFraction(); //сокращаем
		//cout << "Assigment+=: \t\t" << this << "\n";
		return *this;
	}
	Fraction& operator -=(Fraction& obg)
	{
		//reduceFraction();//сокращаем
		//obg.reduceFraction();//сокращаем
		this->numerator = this->numerator * obg.getDenominater() - obg.getNumerator() * this->denominater;
		this->denominater = this->denominater * obg.getDenominater();
		reduceFraction(); //сокращаем
		//cout << "Assigment+=: \t\t" << this << "\n";
		return *this;
	}
	Fraction& operator *=(Fraction& obg)
	{
		//reduceFraction();
		//obg.reduceFraction();
		this->numerator *= obg.getNumerator();
		this->denominater *= obg.getDenominater();
		//cout << "Assigment*=: \t\t" << this << "\n";
		reduceFraction();
		return *this;
	}
	Fraction& operator /=(Fraction& obg)
	{
		reduceFraction();
		obg.reduceFraction();
		this->numerator *= obg.getDenominater();
		this->denominater *= obg.getNumerator();
		//cout << "Assigment /=: \t\t" << this << "\n";
		return *this;
	}


	Fraction& operator ++()
	{
		reduceFraction();
		numerator += denominater;
		//cout << "Assigment++: \t\t" << this << "\n";
		return *this;
	}
	Fraction operator ++(int)
	{
		reduceFraction();
		Fraction old = *this;
		this->numerator += this->denominater;
		//cout << "++Assigment: \t\t" << &old << "\n";
		return old;
	}
	Fraction& operator --()
	{
		reduceFraction();
		numerator -= denominater;
		//cout << "Assigment++: \t\t" << this << "\n";
		return *this;
	}
	Fraction operator --(int)
	{
		reduceFraction();
		Fraction old = *this;
		this->numerator -= this->denominater;
		//cout << "++Assigment: \t\t" << &old << "\n";
		return old;
	}

	//Методы
	// дробь на экран
	void printFraction() const { cout << numerator << "/" << denominater << " \n"; }
	void printProperFraction() //Преобразование в правильную дробь для печати
	{
		reduceFraction();
		cout << "Правильная дробь с целой частью:\t";

		// выводим целую часть, если она есть (она может быть отрицательной)
		if (numerator / denominater != 0)
			cout << numerator / denominater << " ";

		// выводим дробную часть, если она есть 
		// провераем числитель дробной части, если =0 то дробной части нет
		if (numerator - (numerator / denominater) * denominater != 0)
		{
			//Если перед этим была целая часть, выводим скобки
			if (numerator / denominater > 0) { cout << "("; }
			cout << numerator % denominater << "/" << denominater; //Дробная часть
			if (numerator / denominater > 0) { cout << ")"; }
		}
		cout << " \n";
	}
	//сокращение дроби
	void reduceFraction()
	{
		//если числитель = 0, то знаминатель устанавливаем =1 
		// для упрощения последующих расчетов
		if (this->numerator == 0)
		{
			denominater = 1;
		}
		//убираем отрицательность
		if (this->denominater < 0)
		{
			numerator *= -1;
			denominater *= -1;
		}
		//сокращаем по методу архимеда 
		int more, less, rest;
		if (numerator > denominater)more = numerator, less = denominater;
		else more = denominater, less = numerator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;	//GCD - Greatest Common Divesor
		numerator /= GCD;
		denominater /= GCD;
		//return *this;


	////сокращаем
	//for (int i = 2; (i <= numerator && i <= denominater); i++)
	//{
	//	if ((numerator % i == 0) && (denominater % i == 0))
	//	{
	//		numerator /= i;
	//		denominater /= i;
	//		i = 1;
	//	}
	//}
	//Если подобных расчетов много, то можно создать массив простых чисел (побольше, чем в примере)
	// arr[10]{2,3,5,7,11,13,17,19,23,29}
	// в цикле проверять не все числа, а только простые примерно так:

 /* for (int i = 0; (arr[i] <= numerator && arr[i] <= denominater); )
	{
		if ((numerator % arr[i] == 0) && (denominater % arr[i] == 0))
		{
			numerator /= arr[i];
			denominater /= arr[i];
		else
			i++; //к следующему простому числу переходим только,
				 //если if получил ложь, иначе проверяем еще раз деление на этот же множитель
		}
	}*/
	}
};

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
	//
//	// //istream - input stream (поток ввода)
////cin - Console In
//	{
//		/*
//		----------------------------
//		5
//		1/2
//		2 3/4
//		2(3/4)
//		2+3/4
//		----------------------------
//		*/
//		const int SIZE = 64;
//		char buffer[SIZE]{};
//		//is >> buffer;
//		is.getline(buffer, SIZE);
//		int number[3];
//		int n = 0;
//		const char delimiters[] = "(/) +";
//		for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
//			//Функция strtok() разделяет строку на токены:
//			//https://legacy.cplusplus.com/reference/cstring/strtok/
//				//	!!! ФУНКЦИЯ strtok() ИЗМЕНЯЕТ ВХОДНУЮ СТРОКУ !!!
//			number[n++] = atoi(pch);
//		//pch - Pointer to Character (Указатель на символ)
//		//Функция atoi() - "ASCII string to int" принимает строку, и взвращает значение типа 'int' найденное в этой строке
//		//https://legacy.cplusplus.com/reference/cstdlib/atoi/
//		//for (int i = 0; i < n; i++)cout << number[i] << "\t"; cout << endl;
//
//		switch (n)
//		{
//		case 1:	obj = Fraction(number[0]); break;
//		case 2: obj = Fraction(number[0], number[1]); break;
//		case 3: obj = Fraction(number[0], number[1], number[2]); break;
//		}
//
//		return is;
	//https://legacy.cplusplus/reference/cstring/strtok
	//const int SIZE = 32;
	//char buffer[SIZE]{};
	//is >> buffer;
	//int number[3];
	//int n = 0;
	//const char delimiters[] = "(/) +";
	//for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	//	number[n++] = atoi(pch);

	//	//for (int i = 0; i< n;i++) cout << number[i] <<"\t"; cout << endl;
	//	switch (n)
	//	{
	//	case 1:obg = Fraction(number[0]); break;
	//	case 2:obg = Fraction(number[0], number[1]); break;
	//	case 3:obg = Fraction(number[0], number[1], number[2]); break;
	//	default:
	//		break;
	//	}
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
