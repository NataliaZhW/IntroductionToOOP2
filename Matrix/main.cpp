//���������� ������� � ����������????
//�������������� ��������(+, �, *), ����� ������������� � ������������ ��������.*/

#include <iostream>
#include <iomanip>

using namespace std;

class Matrix
{
	int str = 0;
	int col = 0;
	int** mass = nullptr;
public:
	Matrix()
	{
		cout << "\n���������� ���c������� �� ��������� " << this << "\n";
		this->str = 0;
		this->col = 0;
		this->mass = nullptr;
	}
	Matrix(int str, int col) {
		cout << "\n���������� ���c������� � ����������� " << this << "\n";
		this->str = str;
		this->col = col;
		this->mass = new int* [str];
		for (int i = 0; i < str; i++)
		{
			mass[i] = new int[col] {};
		}
	}
	Matrix(const Matrix& obg)
	{
		cout << "\n���������� ���c������� ����������� " << this << "\n";
		this->str = obg.str;
		this->col = obg.col;
		this->mass = new int* [str];
		for (int i = 0; i < str; i++) {
			mass[i] = new int[col] {};
			for (int j = 0; j < col; j++)
			{
				mass[i][j] = obg.mass[i][j];
			}
		}
	}
	~Matrix() {
		cout << "\n���������� ���������� " << this << "\n";
		for (int i = 0; i < str; i++) {
			delete[]mass[i];
		}
		delete[]mass;
	};

	// ������� � �������
	int getStr() const { return str; }
	int getCol() const { return col; }
	int getMass(int str, int col) const { return mass[str][col]; }
	void setMass(int str, int col, int data) { mass[str][col] = data; }

	// ���������
	Matrix& operator =(const Matrix& obg)
	{
		if (this == &obg) return *this;//�������� �� ������ ����
		if (this->str != obg.str) //�������� �� ��������� �����
		{
			// ������� ������
			for (int i = 0; i < this->str; i++) { delete[]mass[i]; }
			delete[]mass;
			// �������� ����� ������
			this->str = obg.str;
			this->col = obg.col;
			this->mass = new int* [this->str];
			for (int i = 0; i < this->str; i++) {
				mass[i] = new int[this->col] {};
				for (int j = 0; j < col; j++)
				{
					mass[i][j] = obg.mass[i][j];
				}
			}
			return *this;
		}
		else
		{
			if (this->str != obg.str) //�������� �� ��������� �������
			{
				// ������� ������ (�����)
				for (int i = 0; i < this->str; i++) { delete[]mass[i]; }
				// �������� ����� ������
				this->col = obg.col;
				for (int i = 0; i < this->str; i++) {
					mass[i] = new int[this->col] {};
					for (int j = 0; j < col; j++)
					{
						mass[i][j] = obg.mass[i][j];
					}
				}
			}
			return *this;
		}
		for (int i = 0; i < str; i++)
		{
			for (int j = 0; j < col; j++)
			{
				mass[i][j] = obg.mass[i][j];
			}
		}
		return *this;
	}

	// ������
	// ����� �� �����
	void printMatrix()
	{
		for (int i = 0; i < str; i++) {
			for (int j = 0; j < col; j++) {
				cout << setw(6) << this->mass[i][j]; //6 ���� �� ����� �����
			}
			cout << endl;
		}
		cout << endl;
	}
	// ���������� ���������� �������
	void inicialis() {
		cout << "\n���������� ���������� ������� " << this << "\n";

		for (int i = 0; i < this->str; i++)
		{
			for (int j = 0; j < this->col; j++)
			{
				mass[i][j] = rand() % 100;
			}
		}
	};
	int max()
	{
		int max = mass[0][0];
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
	int min()
	{
		int min = mass[0][0];
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
	//Matrix(Matrix& mat1, Matrix& mat2, char oper) {
	//	cout << "\n���������� ���c������� � ���������� " << this << "\n";
	//	if (typeid(mat1.mass).name() != typeid(mat2.mass).name())
	//	{
	//		cout << "\n���� ������ �� ��������� \n";
	//	}
	//	else
	//		switch (oper) {
	//		case '+':
	//		{
	//			if (mat1.str != mat2.str && mat1.col != mat2.col)
	//			{
	//				cout << "\n���� ������ �� ��������� \n";
	//			}
	//			else
	//			{
	//				this->str = mat1.str;
	//				this->col = mat1.col;
	//				this->mass = new int* [str];
	//				for (int i = 0; i < str; i++) {
	//					mass[i] = new int[col] {};
	//					for (int j = 0; j < col; j++)
	//					{
	//						mass[i][j] = mat1.mass[i][j] + mat2.mass[i][j];
	//					}
	//				}
	//			}
	//			break;
	//		}
	//
	//		case '-':
	//		{
	//			if (mat1.str != mat2.str && mat1.col != mat2.col)
	//			{
	//				cout << "\n���� ������ �� ��������� \n";
	//			}
	//			else
	//			{
	//				this->str = mat1.str;
	//				this->col = mat1.col;
	//				this->mass = new int* [str];
	//				for (int i = 0; i < str; i++) {
	//					mass[i] = new int[col] {};
	//					for (int j = 0; j < col; j++)
	//					{
	//						mass[i][j] = mat1.mass[i][j] - mat2.mass[i][j];
	//					}
	//				}
	//			}
	//			break;
	//		}
	//
	//		case '*':
	//		{
	//			if (mat1.str != mat2.col && mat1.col != mat2.str)
	//			{
	//				cout << "\n���� ������ �� ��������� \n";
	//			}
	//			else
	//			{
	//				this->str = mat1.str;
	//				this->col = mat2.col;
	//				this->mass = new int* [str];
	//				for (int i = 0; i < str; i++) {
	//					mass[i] = new int[col] {};
	//				}
	//				for (int i = 0; i < str; i++)
	//				{
	//					for (int j = 0; j < mat2.str; j++)
	//					{
	//						for (int k = 0; k < col; k++)
	//						{
	//							this->mass[i][j] += mat1.mass[i][k] * mat2.mass[k][j];
	//						}
	//					}
	//				}
	//				break;
	//			}
	//		}
	//		default:
	//		{
	//			cout << "\n����������� �������� \n";
	//			break;
	//		}
	//		}
	//}
};

Matrix operator+ (const Matrix& mat1, const Matrix& mat2)
{
	cout << "+Assigment: \t\t" << "\n"; // << &temp 
	Matrix temp(mat1.getStr(), mat1.getCol());
	// + �� ��������������� �������
	if (mat1.getStr() != mat2.getStr() && mat1.getCol() != mat2.getCol())
	{
		cout << "\n���� ������ �� ��������� \n";
	}
	else
	{
		for (int i = 0; i < temp.getStr(); i++) {
			for (int j = 0; j < temp.getCol(); j++)
			{
				temp.setMass(i, j, mat1.getMass(i, j) + mat2.getMass(i, j));
			}
		}
	}
	return temp;
}
Matrix operator- (const Matrix& mat1, const Matrix& mat2)
{
	cout << "-Assigment: \t\t" << "\n";// << &temp 
	Matrix temp(mat1.getStr(), mat1.getCol());
	// + �� ��������������� �������
	if (mat1.getStr() != mat2.getStr() && mat1.getCol() != mat2.getCol())
	{
		cout << "\n���� ������ �� ��������� \n";
	}
	else
	{
		for (int i = 0; i < temp.getStr(); i++) {
			for (int j = 0; j < temp.getCol(); j++)
			{
				temp.setMass(i, j, mat1.getMass(i, j) - mat2.getMass(i, j));
			}
		}
	}
	return temp;
}
Matrix operator* (const Matrix& mat1, const Matrix& mat2)
{
	cout << "*Assigment: \t\t" << "\n";// << &temp 
	Matrix temp(mat1.getStr(), mat2.getCol());
	// + �� ��������������� �������
	if (mat1.getStr() != mat2.getCol() && mat1.getCol() != mat2.getStr())
	{
		cout << "\n���� ������ �� ��������� \n";
	}
	else
	{
		for (int i = 0; i < temp.getStr(); i++)
		{
			for (int j = 0; j < mat2.getStr(); j++)
			{
				for (int k = 0; k < temp.getCol(); k++)
				{
					temp.setMass(i, j, temp.getMass(i, j) + mat1.getMass(i, k) * mat2.getMass(k, j));
				}
			}
		}
	}
	return temp;
}


int main()
{
	setlocale(LC_ALL, "Russian");

	Matrix a(4, 4);// ������� ����� ������
	a.printMatrix();// ������� ������
	a.inicialis();// ��������� ���������� �������
	a.printMatrix();// ������� ������
	Matrix a1 = a;// ������� ����� ������
	a1.printMatrix();// ������� ������
	cout << "\n�������� " << a.max() << " \n";
	cout << "\n������� " << a.min() << " \n";
	Matrix b(4, 4);// ������� ����� ������
	b.inicialis();// ��������� ���������� �������
	b.printMatrix();// ������� ������
	Matrix c1 = a + b; // ������������
	//Matrix c1(a, b, '+'); // ������������
	c1.printMatrix();
	Matrix c2 = a - b; // ��������
	//Matrix c2(a, b, '-'); // ��������
	c2.printMatrix();
	Matrix c3 = a * b; // ��������
	//Matrix c3(a, b, '*'); // ��������
	c3.printMatrix();


	return 0;
}