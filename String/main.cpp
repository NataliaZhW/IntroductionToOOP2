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
	// Constructors:
	String();
	String(int sizeTemp);
	String(const char* str);
	String(const String& obg);
	
	String(String&& obg);
	~String();
	
	// Геттеры Сеттеры
	int getSize() const ;//количество полей	
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


// Constructors:
String::String() : size(80), data(new char[size] {})
{
	cout << "\nЗапустился 1 контруктор по умолчанию\n";
	//int size{ 80 };
	//char* data = new char[size] {};
}
String::String(int sizeTemp) : size(sizeTemp), data(new char[size] {}) {}
//	cout << "1ArgConstructop: \t" << this << " Size:\t" << this->size << "\t" << "Data: " << data << "\n";
//	cout << "\nЗапустился контруктор, принимает размер\n";
String::String(const char* str) : size(strlen(str) + 1), data(new char[size] {})
{
	cout << "\nЗапустился контруктор, принимает строку, ограничивает длину строки\n";
	//size = strlen(str) + 1;
	//data = new char[size] {};
	strcpy_s(data, size, str);
}
String::String(const String& obg) : String(obg.data)
{
	cout << "\nЗапустился контруктор копирования\n";
	//size = obg.size;
	//data = new char[size] {};//+ 1
	//strcpy_s(data, size, obg.data);
}
String::String(String&& obg)
{
	cout << "\nЗапустился контруктор присваивания\n";
	size = obg.size;
	data = obg.data;
	obg.data = nullptr;
}
String::~String()
{
	delete[] this->data;
	cout << "Destructor:\t\t" << this << endl;
}

// Геттеры Сеттеры
int String::getSize() const { return size; };//количество полей	
void String::setData(const char* text) //Запись в поле, текст
{
	//  1 вариант, работает
	if (this->size != strlen(text) + 1)
	{
		this->size = strlen(text) + 1;//определяем размер введенного текста		
		delete[]this->data;
		data = new char[size] {};
	}
	strcpy_s(data, size, text);
}
const char* String::getData() const { return data; };
char* String::getData() { return data; };
char String::getChar(int i) const { return data[i]; }// поле массива
void String::setChar(char znak, int i) { this->data[i] = znak; }//Запись одного знака

//Операторы
//String& operator= (String&& obg) = delete;
String& String::operator= (const String& obg)
{
	cout << "\nЗапустился оператор копирования\n";
	if (this == &obg) return *this;
	if (this->size != obg.size)
	{
		delete[] data;
		this->size = obg.size;
		this->data = new char[size] {};
	}
	strcpy_s(this->data, this->size, obg.data);
	return *this;
}
String& String::operator= (String&& obg)
{
	cout << "\nЗапустился оператор присваивания\n";
	if (this == &obg) return *this;
	delete[] data;
	this->size = obg.size;
	this->data = obg.data;
	obg.data = nullptr;
	return *this;
}

char& String::operator[](const int& i) { return data[i]; }
const char& String::operator[](const int& i) const { return data[i]; }


//				Methods:
void String::print() const {
	cout << "Size:\t" << this->size << "\t";
	cout << "Data: " << data << "\n";
};

String operator +(const String& obg1, const String& obg2)
{
	int size = obg1.getSize() - 1 + obg2.getSize();
	String Result(size);//;
	//Result.getSize(obg1.getSize() + obg2.getSize());
	int i = 0;
	for (; i < (obg1.getSize() - 1); i++) {
		Result.setChar(obg1.getChar(i), i);
		//cout << obg1.getChar(i);
	}
	//setChar(char znak, int i)
	for (; i < Result.getSize(); i++)
	{
		Result.setChar(obg2.getChar(i - obg1.getSize() + 1), i);
		//cout << obg2.getChar(i - obg1.getSize() + 1);
	}
	//setChar(char znak, int i)
	//cout << "Конкатенация: \t\t" << &Result << "\n";
	cout << i << "\n";
	Result.print();
	return Result;
}
std::ostream& operator << (std::ostream& os, const String& obg)
{
	os << obg.getData();
	return os;
}
String factoryString(int size)
{
	cout << "Factory\n";
	String A(size);
	char* temp = new char[size + 1] {};
	for (int i = 0; i < size; i++)
	{
		temp[i] = 't';
	}
	temp[size] = '\0';

	A.setData(temp);
	return A;
}

#define CAT_CHECK

int main()
{
	setlocale(LC_ALL, "Russian");

	//String str(80);
	//str.print();
	//cout << "\n";
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
	str2.setData("55555");
	str2.print();


	String str3 = str1 + str2;
	str3.print();
	cout << "\n";
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;	//HelloWorld
	cout << "\n";
	String str4 = str1;
	str4.print();
	str4 = str2;
	str4.print();

	cout << "\n";
	String str5 = factoryString(4);
	str5.print();
	str4 = str2;
	str4.print();

	return 0;
}