// String.cpp : This file contains the 'main' function. Program execution begins and ends there.
////String

#include <iostream>
using namespace std;

class String
{
private:
	int size;//Размер строки в Байтах
	char* data;//Адрес строки в динамической памяти	
public:
	//			Constructors:
	String()
	{
		cout << "\nЗапустился 1 контруктор по умолчанию\n";
		int size{ 80 };
		char* data = new char[size] {};
	}
	String(int size)
	{
		this->size = size;
		this->data = new char[size] {};
		cout << "1ArgConstructop: \t" << this << " Size:\t" << this->size << "\t" << "Data: " << data << "\n";


		//cout << "\nЗапустился 2 контруктор, принимает размер\n";

	}
	String(const char* str) {
		cout << "\nЗапустился 3 контруктор, принимает строку, ограничивает длину строки\n";
		size = strlen(str) + 1;
		data = new char[size] {};
		strcpy_s(data, size, str);
	}
	String(const String& obg)
	{
		cout << "\nЗапустился 4 контруктор, копирования\n";
		size = obg.size;
		data = new char[size] {};//+ 1
		strcpy_s(data, size, obg.data);
	}
	~String()
	{
		delete[] this->data;
		cout << "Destructor:\t\t" << this << endl;
	}
	/*void input() {
		cout << "Введите строку: ";
		cin.getline(data, size + 1);
	}*/


	int getSize() const { return size; };//количество полей
	void setData(const char str) { this->data = data; };
	char getChar(int i) const { return data[i]; };// поле массива
	void setChar(char znak, int i) { this->data[i] = znak; };//Запись одного знака

	//				Methods:
	void print() const {
		cout << "Size:\t" << this->size << "\t";
		cout << "Data: " << data << "\n";
	};
	char* printLight() const {
		return data;
	};

};

String operator +(const String& obg1, const String& obg2)
{
	int size = obg1.getSize() - 1 + obg2.getSize();
	String Result(size);//;
	//Result.getSize(obg1.getSize() + obg2.getSize());
	int i = 0;
	for (; i < (obg1.getSize() - 1); i++) {
		Result.setChar(obg1.getChar(i), i);
		cout << obg1.getChar(i);
	}//setChar(char znak, int i)
	for (; i < Result.getSize(); i++)
	{
		Result.setChar(obg2.getChar(i - obg1.getSize() + 1), i);
		cout << obg2.getChar(i - obg1.getSize() + 1);
	}//setChar(char znak, int i)
	cout << i << "\n";
	Result.print();
	return Result;
}
std::ostream& operator << (std::ostream& os, const String& obg)
{
	os << obg.printLight();
	return os;
}

//cout << "Конкатенация: \t\t" << &Result << "\n";

int main()
{
	setlocale(LC_ALL, "Russian");

	String str(80);
	str.print();
	cout << "\n";
	String str1 = "Hello";
	str1.print();
	//str1.setChar('3', 0);
	//str1.print();
	/*for (int i = 0; i < str1.getSize(); i++)
	{
		cout << str1.getChar(i);
	}*/
	String str2("World");
	str2.print();

	String str3 = str1 + str2;
	str3.print();
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;	//HelloWorld
	//String str4(str1);
	//str4.print();
	return 0;
}



//	//String str;
//	//str.print();
//
//	String str1 = "Hello";
//	String str2 = "World";
//	
//	String str3 = str1 + str2;
//	
//}