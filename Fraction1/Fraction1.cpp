#include"Fraction.h"
using namespace std;

	//конструкторы и деструктор
Fraction::Fraction() { numerator = denominater = 1; cout << "DefaultConstructop: \t" << this << "\n"; } //
Fraction::Fraction(int numerator)
{
	setNumerator(numerator);
	denominater = 1;
	cout << "1ArgConstructop: \t" << this << "\n";
}
Fraction::Fraction(double numeratorObg)
{
	this->denominater = 1e+7;
	numerator = denominater * numeratorObg;
	cout << (int)1e+9 << "\n";
	reduceFraction();
	cout << "1ArgConstructop double: \t" << this << "\n";
}
Fraction::Fraction(int numerator, int denominater)
{
	setNumerator(numerator);
	setDenominater(denominater);
	cout << "2ArgConstructop: \t" << this << "\n";
}
Fraction::Fraction(const Fraction& obg)
{
	this->numerator = obg.numerator;
	this->denominater = obg.denominater;

}
Fraction::~Fraction() { cout << "Destructop: \t\t" << this << "\n"; } //

// Геттеры и сеттеры
int Fraction::getNumerator() const { return numerator; }
void Fraction::setNumerator(int numerator) { this->numerator = numerator; }
int Fraction::getDenominater() const { return denominater; }
// с проверкой на 0
void Fraction::setDenominater(int denominater)
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
 Fraction::operator int() const { return (int)(numerator / denominater); }
 Fraction::operator double() const { return (double)numerator / (double)denominater; }


Fraction& Fraction::operator =(const Fraction& obg)
{
	this->numerator = obg.numerator;
	this->denominater = obg.denominater;
	//cout << "CopyAssigment: \t\t" << this << "\n";
	return *this;
}
Fraction& Fraction::operator =(int obg)
{
	this->numerator = obg;
	this->denominater = 1;
	//cout << "CopyAssigment: \t\t" << this << "\n";
	return *this;
}
Fraction& Fraction::operator =(double obg)
{
	Fraction temp(obg);
	return *this;
}


Fraction& Fraction::operator +=(int obg)
{
	numerator += (denominater * obg);
	reduceFraction();
	//cout << "Assigment +=: \t\t" << this << "\n";
	return *this;
}
Fraction& Fraction::operator -=(int obg)
{
	numerator -= denominater * obg;
	reduceFraction();
	//cout << "Assigment -=: \t\t" << this << "\n";
	return *this;
}
Fraction& Fraction::operator *=(int obg)
{
	numerator = numerator * obg;
	//cout << "Assigment *=: \t\t" << this << "\n";
	return *this;
	reduceFraction();
}
// с проверкой на 0
Fraction& Fraction::operator /=(int obg)
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


Fraction& Fraction::operator +=(double numeratorObg)
{
	Fraction temp(numeratorObg);
	this->numerator = this->numerator * temp.getDenominater() + temp.getNumerator() * this->denominater;
	this->denominater = this->denominater * temp.getDenominater();
	reduceFraction(); //сокращаем
	return *this;
}
Fraction& Fraction::operator -=(double numeratorObg)
{
	Fraction temp(numeratorObg);
	this->numerator = this->numerator * temp.getDenominater() + temp.getNumerator() * this->denominater;
	this->denominater = this->denominater * temp.getDenominater();
	reduceFraction(); //сокращаем
	return *this;
}
Fraction& Fraction::operator *=(double numeratorObg)
{
	Fraction temp(numeratorObg);
	this->numerator *= temp.getNumerator();
	this->denominater *= temp.getDenominater();
	reduceFraction();
	return *this;
}
// с проверкой на 0
Fraction& Fraction::operator /=(double numeratorObg)
{
	if (numeratorObg != 0) {
		Fraction temp(numeratorObg);
		this->numerator *= temp.getDenominater();
		this->denominater *= temp.getNumerator();
		reduceFraction();
	}
	else
	{
		cout << " Error: divizion by zero \n Деление на ноль, операция не выполнена!\n";
	}
	//cout << "Assigment /=: \t\t" << this << "\n";
	return *this;
}


Fraction& Fraction::operator +=(Fraction& obg)
{
	this->numerator = this->numerator * obg.getDenominater() + obg.getNumerator() * this->denominater;
	this->denominater = this->denominater * obg.getDenominater();
	reduceFraction(); //сокращаем
	//cout << "Assigment+=: \t\t" << this << "\n";
	return *this;
}
Fraction& Fraction::operator -=(Fraction& obg)
{
	this->numerator = this->numerator * obg.getDenominater() - obg.getNumerator() * this->denominater;
	this->denominater = this->denominater * obg.getDenominater();
	reduceFraction(); //сокращаем
	//cout << "Assigment+=: \t\t" << this << "\n";
	return *this;
}
Fraction& Fraction::operator *=(Fraction& obg)
{
	this->numerator *= obg.getNumerator();
	this->denominater *= obg.getDenominater();
	//cout << "Assigment*=: \t\t" << this << "\n";
	reduceFraction();
	return *this;
}
Fraction& Fraction::operator /=(Fraction& obg)
{
	reduceFraction();
	obg.reduceFraction();
	this->numerator *= obg.getDenominater();
	this->denominater *= obg.getNumerator();
	//cout << "Assigment /=: \t\t" << this << "\n";
	return *this;
}


Fraction& Fraction::operator ++()
{
	reduceFraction();
	numerator += denominater;
	//cout << "Assigment++: \t\t" << this << "\n";
	return *this;
}
Fraction Fraction::operator ++(int)
{
	reduceFraction();
	Fraction old = *this;
	this->numerator += this->denominater;
	//cout << "++Assigment: \t\t" << &old << "\n";
	return old;
}
Fraction& Fraction::operator --()
{
	reduceFraction();
	numerator -= denominater;
	//cout << "Assigment++: \t\t" << this << "\n";
	return *this;
}
Fraction Fraction::operator --(int)
{
	reduceFraction();
	Fraction old = *this;
	this->numerator -= this->denominater;
	//cout << "++Assigment: \t\t" << &old << "\n";
	return old;
}

//Методы
// дробь на экран
void Fraction::printFraction() const { cout << numerator << "/" << denominater << " \n"; }
void Fraction::printProperFraction() //Преобразование в правильную дробь для печати
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
void Fraction::reduceFraction()
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
}


