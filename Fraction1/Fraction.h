#pragma once
#include <iostream>
using namespace std;

#define delimiter			"\n-----------------------------------\n"
#define double_delimiter	"\n===================================\n"

class Fraction // Дробь
{
private:
	int numerator; // Числитель
	int denominater; // Знаменатель
public:
	//конструкторы и деструктор
	Fraction();
	explicit Fraction(int numerator);
	Fraction(double numeratorObg);
	Fraction(int numerator, int denominater);
	Fraction(const Fraction& obg);
	~Fraction();

	// Геттеры и сеттеры
	int getNumerator() const;
	void setNumerator(int numerator);
	int getDenominater() const;
	// с проверкой на 0
	void setDenominater(int denominater);

	//Операторы
	explicit operator int() const;
	explicit operator double() const;


	Fraction& operator =(const Fraction& obg);
	Fraction& operator =(int obg);
	Fraction& operator =(double obg);


	Fraction& operator +=(int obg);
	Fraction& operator -=(int obg);
	Fraction& operator *=(int obg);
	// с проверкой на 0
	Fraction& operator /=(int obg);


	Fraction& operator +=(double numeratorObg);
	Fraction& operator -=(double numeratorObg);
	Fraction& operator *=(double numeratorObg);
	// с проверкой на 0
	Fraction& operator /=(double numeratorObg);


	Fraction& operator +=(Fraction& obg);
	Fraction& operator -=(Fraction& obg);
	Fraction& operator *=(Fraction& obg);
	Fraction& operator /=(Fraction& obg);


	Fraction& operator ++();
	Fraction operator ++(int);
	Fraction& operator --();
	Fraction operator --(int);

	//Методы
	// дробь на экран
	void printFraction() const;
	void printProperFraction();//Преобразование в правильную дробь для печати
	
	//сокращение дроби
	void reduceFraction();
};

//Внешние функции
bool operator ==(Fraction& obg1, Fraction& obg2); //дроби будем изменять - сокращать
bool operator !=(Fraction& obg1, Fraction& obg2); //дроби будем изменять - сокращать
bool operator > (const Fraction& obg1, const Fraction& obg2);
bool operator < (const Fraction& obg1, const Fraction& obg2);
bool operator >= (const Fraction& obg1, const Fraction& obg2);
bool operator <= (const Fraction& obg1, const Fraction& obg2);

// функция, которая возвращает дробь, результат сложения дробей
Fraction operator +(const Fraction& obg1, const Fraction& obg2);
// результат вычитания дробей
Fraction operator -(const Fraction& obg1, const Fraction& obg2);
// результат произведения дробей
Fraction operator *(const Fraction& obg1, const Fraction& obg2);
// результат деления дробей
Fraction operator /(const Fraction& obg1, const Fraction& obg2);
std::ostream& operator << (std::ostream& os, const Fraction& obg);
std::istream& operator >> (std::istream& is, Fraction& obg);

