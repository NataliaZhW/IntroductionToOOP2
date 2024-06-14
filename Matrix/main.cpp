// ������������ ��������� ������, ������� ������,
//���������� ������� � ����������, ���������� ���������� ����������, ����������� �������,
//�������������� ��������(+, �, *), ����� ������������� � ������������ ��������.*/

#include <iostream>
#include <iomanip>
//#include <string.h>
//#include <typeinfo>

using namespace std;

template <class T>
class Matrix
{
public:
	int str = 0;
	int col = 0;
	T** mass = nullptr;
	Matrix()
	{
		cout << "\n���������� ���c������� �� ��������� " << this << "\n";

		this->str = 3;
		this->col = 3;
		this->mass = new T * [str];
		for (int i = 0; i < str; i++) {
			mass[i] = new T[col]{};
		}
	};
	Matrix(int str, int col) {
		cout << "\n���������� ���c������� � ����������� " << this << "\n";
		this->str = str;
		this->col = col;
		this->mass = new T * [str];
		for (int i = 0; i < str; i++) {
			mass[i] = new T[col]{};
		}
	};
	~Matrix() {
		cout << "\n���������� ���������� " << this << "\n";
		for (int i = 0; i < str; i++) {
			delete[]mass[i];
		}
		delete[]mass;
	};
	// ����� �� �����
	void printMatrix()
	{
		for (int i = 0; i < str; i++) {
			for (int j = 0; j < col; j++) {
				cout << setw(4) << this->mass[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	// ���������� ���������� �������
	void inicialis() {
		for (int i = 0; i < this->str; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				mass[i][j] = rand() % 10;
			}
		}
	};
	T max()
	{
		T max = mass[0][0];
		for (int i = 0; i < str; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (max < mass[i][j])
				{
					max = mass[i][j];
				}
			}
		}
		return max;
	}
	T min()
	{
		T min = mass[0][0];
		for (int i = 0; i < str; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (min > mass[i][j])
				{
					min = mass[i][j];
				}
			}
		}
		return min;
	}

	//���������� � ����������

	Matrix(Matrix& mat1, Matrix& mat2, char oper) {
		cout << "\n���������� ���c������� � ���������� " << this << "\n";
		if (typeid(mat1.mass).name() != typeid(mat2.mass).name())
		{
			cout << "\n���� ������ �� ��������� \n";
		}
		else
			switch (oper) {
			case '+':
			{
				if (mat1.str != mat2.str && mat1.col != mat2.col)
				{
					cout << "\n���� ������ �� ��������� \n";
				}
				else
				{
					this->str = mat1.str;
					this->col = mat1.col;
					this->mass = new T * [str];
					for (int i = 0; i < str; i++) {
						mass[i] = new T[col]{};
						for (int j = 0; j < col; j++)
						{
							mass[i][j] = mat1.mass[i][j] + mat2.mass[i][j];
						}
					}
				}
				break;
			}

			case '-':
			{
				if (mat1.str != mat2.str && mat1.col != mat2.col)
				{
					cout << "\n���� ������ �� ��������� \n";
				}
				else
				{
					this->str = mat1.str;
					this->col = mat1.col;
					this->mass = new T * [str];
					for (int i = 0; i < str; i++) {
						mass[i] = new T[col]{};
						for (int j = 0; j < col; j++)
						{
							mass[i][j] = mat1.mass[i][j] - mat2.mass[i][j];
						}
					}
				}
				break;
			}

			case '*':
			{
				if (mat1.str != mat2.col && mat1.col != mat2.str)
				{
					cout << "\n���� ������ �� ��������� \n";
				}
				else
				{
					this->str = mat1.str;
					this->col = mat2.col;
					this->mass = new T * [str];
					for (int i = 0; i < str; i++) {
						mass[i] = new T[col]{};
					}
					for (int i = 0; i < str; i++)
					{
						for (int j = 0; j < mat2.str; j++)
						{
							for (int k = 0; k < col; k++)
							{
								this->mass[i][j] += mat1.mass[i][k] * mat2.mass[k][j];
							}
						}
					}
					break;
				}
			};
			default:
			{
				cout << "\n����������� �������� \n";
				break;
			};
			};
	};
}

; int main()
{
	setlocale(LC_ALL, "Russian");

	Matrix <int>a(4, 4);// ������� ����� ������
	a.printMatrix();// ������� ������
	a.inicialis();// ��������� ���������� �������
	a.printMatrix();// ������� ������
	cout << "\n�������� " << a.max() << " \n";
	cout << "\n������� " << a.min() << " \n";
	Matrix <int>b(4, 4);// ������� ����� ������
	b.inicialis();// ��������� ���������� �������
	b.printMatrix();// ������� ������
	Matrix <int>c1(a, b, '+'); // ������������
	c1.printMatrix();
	Matrix <int>c2(a, b, '-'); // ��������
	c2.printMatrix();
	Matrix <int>c3(a, b, '*'); // ��������
	c3.printMatrix();


	return 0;
}