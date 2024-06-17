
#include"String.h"

// Constructors:
String::String() : size(80), data(new char[size] {})
{
	cout << "\nЗапустился 1 контруктор по умолчанию\n";
}
String::String(int sizeTemp) : size(sizeTemp), data(new char[size] {}) {}
String::String(const char* str) : size(strlen(str) + 1), data(new char[size] {})
{
	cout << "\nЗапустился контруктор, принимает строку, ограничивает длину строки\n";
	strcpy_s(data, size, str);
}
String::String(const String& obg) : String(obg.data)
{
	cout << "\nЗапустился контруктор копирования\n";
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