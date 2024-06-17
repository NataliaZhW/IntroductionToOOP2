
#include"String.h"

// Constructors:
String::String() : size(80), data(new char[size] {})
{
	cout << "\n���������� 1 ���������� �� ���������\n";
}
String::String(int sizeTemp) : size(sizeTemp), data(new char[size] {}) {}
String::String(const char* str) : size(strlen(str) + 1), data(new char[size] {})
{
	cout << "\n���������� ����������, ��������� ������, ������������ ����� ������\n";
	strcpy_s(data, size, str);
}
String::String(const String& obg) : String(obg.data)
{
	cout << "\n���������� ���������� �����������\n";
}
String::String(String&& obg)
{
	cout << "\n���������� ���������� ������������\n";
	size = obg.size;
	data = obg.data;
	obg.data = nullptr;
}
String::~String()
{
	delete[] this->data;
	cout << "Destructor:\t\t" << this << endl;
}

// ������� �������
int String::getSize() const { return size; };//���������� �����	
void String::setData(const char* text) //������ � ����, �����
{
	//  1 �������, ��������
	if (this->size != strlen(text) + 1)
	{
		this->size = strlen(text) + 1;//���������� ������ ���������� ������		
		delete[]this->data;
		data = new char[size] {};
	}
	strcpy_s(data, size, text);
}
const char* String::getData() const { return data; };
char* String::getData() { return data; };
char String::getChar(int i) const { return data[i]; }// ���� �������
void String::setChar(char znak, int i) { this->data[i] = znak; }//������ ������ �����

//���������
String& String::operator= (const String& obg)
{
	cout << "\n���������� �������� �����������\n";
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
	cout << "\n���������� �������� ������������\n";
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