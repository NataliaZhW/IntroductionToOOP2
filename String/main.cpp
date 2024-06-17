// String.cpp : This file contains the 'main' function. Program execution begins and ends there.
////String

#include"String.h"



String operator +(const String& obg1, const String& obg2)
{
	int size = obg1.getSize() - 1 + obg2.getSize();
	String Result(size);//;
	int i = 0;
	for (; i < (obg1.getSize() - 1); i++) {
		Result.setChar(obg1.getChar(i), i);
	}
	for (; i < Result.getSize(); i++)
	{
		Result.setChar(obg2.getChar(i - obg1.getSize() + 1), i);
	}
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