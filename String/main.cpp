// String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class String
{
private:
	static const int MAX_Lenght = 80;
	char* data;
	int length;
public:
	String()
	{
		cout << "\nЗапустился 1 контруктор по умолчанию\n";
		data = new char[MAX_Lenght + 1] {};
		length = MAX_Lenght;
	}
	String(int sise)
	{
		cout << "\nЗапустился 2 контруктор, принимает размер и обрезает лишние символы\n";
		data = new char[sise + 1] {};
		length = sise;
	}
	String(const char* str) {
		cout << "\nЗапустился 3 контруктор, принимает строку, ограничивает длину строки\n";
		length = strlen(str);
		data = new char[length + 1] {};
		strcpy_s(data, length + 1, str);
	}
	String(const String& obg)
	{
		cout << "\nЗапустился 4 контруктор, копирования\n";
		length = obg.length;
		data = new char[length + 1] {};
		strcpy_s(data, length, obg.data);
	}
	~String()
	{
		delete[] data;
	}
	/*void input() {
		cout << "Введите строку: ";
		cin.getline(data, length + 1);
	}*/


	int getLength() const { return length; };//количество полей
	void setData(const char str) { this->data = data; };
	char getChar(int i) const { return data[i]; };// поле массива
	void setChar(char znak, int i) { this->data[i] = znak; };//Запись одного знака

	void print() const {
		cout << "Ваша строка: " << data << "\n";
		cout << this->length << " размер строки\n";
	};

};

String operator +(const String& obg1, const String& obg2)
{
	String Result;//(obg1.getLength()+obg2.getLength());
	for (int i = 0; i < Result.getLength(); i++)
	{
		int index;
		bool flag = 0;
		if (i < obg1.getLength() && !flag) {
			index = i;
			if (!flag)
			{
				if (obg1.getChar(index) != '\0')
					cout << obg1.getChar(index) << "\n";
				Result.setChar(obg1.getChar(index), i);//setChar(char znak, int i)
			}
		}
		else
		{
			index = i - obg1.getLength();
			Result.setChar(obg2.getChar(index), i);
		}
		cout << i << "\n";
	}
	//Result.setData('a',3);
	cout << "Конкатенация: \t\t" << &Result << "\n";
	return Result;
}
int main()
{
	setlocale(LC_ALL, "Russian");

	String str;
	str.print();
	cout << "\n";
	String str1 = "Hello";
	str1.print();
	str1.setChar('3', 0);
	str1.print();
	for (int i = 0; i < str1.getLength(); i++)
	{
		cout << str1.getChar(i);
	}
	String str2("World");
	str2.print();

	String str3 = str + str;
	str3.print();

	//String str4(str1);
	//str4.print();
	return 0;
}