#pragma once
#include <iostream>
using namespace std;

#define delimiter			"\n-----------------------------------\n"
#define double_delimiter	"\n===================================\n"

class Fraction // �����
{
private:
	int numerator; // ���������
	int denominater; // �����������
public:
	//������������ � ����������
	Fraction();
	explicit Fraction(int numerator);
	Fraction(double numeratorObg);
	Fraction(int numerator, int denominater);
	Fraction(const Fraction& obg);
	~Fraction();

	// ������� � �������
	int getNumerator() const;
	void setNumerator(int numerator);
	int getDenominater() const;
	// � ��������� �� 0
	void setDenominater(int denominater);

	//���������
	explicit operator int() const;
	explicit operator double() const;


	Fraction& operator =(const Fraction& obg);
	Fraction& operator =(int obg);
	Fraction& operator =(double obg);


	Fraction& operator +=(int obg);
	Fraction& operator -=(int obg);
	Fraction& operator *=(int obg);
	// � ��������� �� 0
	Fraction& operator /=(int obg);


	Fraction& operator +=(double numeratorObg);
	Fraction& operator -=(double numeratorObg);
	Fraction& operator *=(double numeratorObg);
	// � ��������� �� 0
	Fraction& operator /=(double numeratorObg);


	Fraction& operator +=(Fraction& obg);
	Fraction& operator -=(Fraction& obg);
	Fraction& operator *=(Fraction& obg);
	Fraction& operator /=(Fraction& obg);


	Fraction& operator ++();
	Fraction operator ++(int);
	Fraction& operator --();
	Fraction operator --(int);

	//������
	// ����� �� �����
	void printFraction() const;
	void printProperFraction();//�������������� � ���������� ����� ��� ������
	
	//���������� �����
	void reduceFraction();
};

//������� �������
bool operator ==(Fraction& obg1, Fraction& obg2); //����� ����� �������� - ���������
bool operator !=(Fraction& obg1, Fraction& obg2); //����� ����� �������� - ���������
bool operator > (const Fraction& obg1, const Fraction& obg2);
bool operator < (const Fraction& obg1, const Fraction& obg2);
bool operator >= (const Fraction& obg1, const Fraction& obg2);
bool operator <= (const Fraction& obg1, const Fraction& obg2);

// �������, ������� ���������� �����, ��������� �������� ������
Fraction operator +(const Fraction& obg1, const Fraction& obg2);
// ��������� ��������� ������
Fraction operator -(const Fraction& obg1, const Fraction& obg2);
// ��������� ������������ ������
Fraction operator *(const Fraction& obg1, const Fraction& obg2);
// ��������� ������� ������
Fraction operator /(const Fraction& obg1, const Fraction& obg2);
std::ostream& operator << (std::ostream& os, const Fraction& obg);
std::istream& operator >> (std::istream& is, Fraction& obg);

