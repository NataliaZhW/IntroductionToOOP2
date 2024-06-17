#pragma once

#include <iostream>
using namespace std;

class String
{
private:
	int size;//Размер строки в Байтах
	char* data;//Адрес строки в динамической памяти	
public:
	// Constructors:
	String();
	String(int sizeTemp);
	String(const char* str);
	String(const String& obg);

	String(String&& obg);
	~String();

	// Геттеры Сеттеры
	int getSize() const;//количество полей	
	void setData(const char* text);
	const char* getData() const;
	char* getData();
	char getChar(int i) const;// поле массива
	void setChar(char znak, int i);//Запись одного знака

	//Операторы
	String& operator= (const String& obg);
	String& operator= (String&& obg);

	char& operator[](const int& i);
	const char& operator[](const int& i) const;


	//				Methods:
	void print() const;
};

String operator +(const String& obg1, const String& obg2);
std::ostream& operator << (std::ostream& os, const String& obg);
String factoryString(int size);