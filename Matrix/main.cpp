//заполнение матрицы с клавиатуры????
//арифметические операции(+, –, *), поиск максимального и минимального элемента.*/

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
		cout << "\nЗапустился конcтруктор по умолчанию " << this << "\n";
		this->str = 0;
		this->col = 0;
		this->mass = nullptr;
	}
	Matrix(int str, int col) {
		cout << "\nЗапустился конcтруктор с параметрами " << this << "\n";
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
		cout << "\nЗапустился конcтруктор копирования " << this << "\n";
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
		cout << "\nЗапустился деструктор " << this << "\n";
		for (int i = 0; i < str; i++) {
			delete[]mass[i];
		}
		delete[]mass;
	};

	// Геттеры и сеттеры
	int getStr() const { return str; }
	int getCol() const { return col; }
	int getMass(int str, int col) const { return mass[str][col]; }
	void setMass(int str, int col, int data) { mass[str][col] = data; }

	// Операторы
	Matrix& operator =(const Matrix& obg)
	{
		if (this == &obg) return *this;//проверка на самого себя
		if (this->str != obg.str) //Проверка на равенство строк
		{
			// удаляем память
			for (int i = 0; i < this->str; i++) { delete[]mass[i]; }
			delete[]mass;
			// выделяем новую память
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
			if (this->str != obg.str) //Проверка на равенство столбцы
			{
				// удаляем память (часть)
				for (int i = 0; i < this->str; i++) { delete[]mass[i]; }
				// выделяем новую память
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

	// Методы
	// Вывод на экран
	void printMatrix()
	{
		for (int i = 0; i < str; i++) {
			for (int j = 0; j < col; j++) {
				cout << setw(6) << this->mass[i][j]; //6 мест на вывод числа
			}
			cout << endl;
		}
		cout << endl;
	}
	// Заполнение случайными числами
	void inicialis() {
		cout << "\nЗаполнение случайными числами " << this << "\n";

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
};

Matrix operator+ (const Matrix& mat1, const Matrix& mat2)
{
	cout << "+Assigment: \t\t" << "\n"; // << &temp 
	Matrix temp(mat1.getStr(), mat1.getCol());
	// + по математическому правилу
	if (mat1.getStr() != mat2.getStr() && mat1.getCol() != mat2.getCol())
	{
		cout << "\nТипы матриц не совпадают \n";
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
	// + по математическому правилу
	if (mat1.getStr() != mat2.getStr() && mat1.getCol() != mat2.getCol())
	{
		cout << "\nТипы матриц не совпадают \n";
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
	// + по математическому правилу
	if (mat1.getStr() != mat2.getCol() && mat1.getCol() != mat2.getStr())
	{
		cout << "\nТипы матриц не совпадают \n";
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

	Matrix a(4, 4);// создаем новый объект
	a.printMatrix();// выводим объект
	a.inicialis();// заполняем случайными числами
	a.printMatrix();// выводим объект
	Matrix a1 = a;// создаем новый объект
	a1.printMatrix();// выводим объект
	cout << "\nМаксимум " << a.max() << " \n";
	cout << "\nМинимум " << a.min() << " \n";
	Matrix b(4, 4);// создаем новый объект
	b.inicialis();// заполняем случайными числами
	b.printMatrix();// выводим объект
	Matrix c1 = a + b; // суммирование
	c1.printMatrix();
	Matrix c2 = a - b; // разность
	c2.printMatrix();
	Matrix c3 = a * b; // умножаем
	c3.printMatrix();


	return 0;
}