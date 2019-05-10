#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
class matrix
{
private: int row; // row of matrix
private: int col; // column
private:	float** data;
public:	matrix()
{
	row = col = 0;
}
public:	matrix(int n, int m)
{
	this->row = n;
	this->col = m;
	data = new float* [row];
	for (int i = 0; i < n; i++)
	{
		data[i] = new float[this->col];
	}
}
public: void nhap()
{
	cout << "Nhap so cot: "; cin >> row;
	cout << "Nhap so hang: "; cin >> col;
	data = new float* [row];
	for (int i = 0; i < row; i++)
	{
		data[i] = new float[col];
	}
	for (int i=0; i<row; i++)
		for (int j = 0; j < col; j++)
		{
			cout << "Nhap ma tran[" << i + 1 << "][" << j + 1 << "]=" << endl;
			cin >> data[i][j];
		}
}
public: matrix(const matrix& a)
{
	row = a.row;
	col = a.col;
	data = new float* [row];
	for (int i = 0; i < row; i++)
	{
		data[i] = new float[col];
	}
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			data[i][j] = a.data[i][j];
}
public: matrix operator+(matrix& B)
{
	matrix temp(row,col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			temp.data[i][j] = this->data[i][j] + B.data[i][j];
	return temp;
}
public: matrix operator-(matrix& B)
{
	matrix temp(row, col);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			temp.data[i][j] = this->data[i][j] + B.data[i][j];
}

public: int operator==(matrix& that)
{
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j <this->col; j++)
		{
			this->data[i][j] = that.data[i][j];
		}
	}
}
public: matrix operator*(matrix& that)
{
	if (this->col != that.row)
	{
		cout << "Error operation!\n";
		return *this;
	}
	matrix tmpMat(this->row, that.col);
	//cout<<tmpMat;
	for (int i = 0; i < tmpMat.row; i++)
	{
		for (int j = 0; j < tmpMat.col; j++)
		{
			for (int k = 0; k < this->col; k++)
			{
			    //cout<<this->data[i][k]<<","<<that.data[k][j];
				tmpMat.data[i][j] += (this->data[i][k]) * (that.data[k][j]);
				//cout<<tmpMat.data[i][j];
			}
		}
	}
	return tmpMat;
}
public: void display()
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
	{
		cout << "Ma tran da tao: ";
		cout << "[" << this->data[i][j] << "]" << endl;
	}
}
friend ostream& operator<<(ostream&, const matrix&);
};
ostream& operator<<(ostream&out, const matrix&that)
{
	for (int i = 0; i < that.row; i++)
	{
		out << "[";
		for (int j = 0; j < that.col; j++)
		{
			out << that.data[i][j]<<",";
		}
		out << "]" << endl;
	}
	return out;
}






int main()
{
	matrix mt;
	matrix m1(2, 3);
	matrix m2(2, 3);
	m1.nhap();
	m2.nhap();
	m1.display();
	m2.display();
	cout << "Here are 2 example matrixes: ";
	cout << ">matrix A: \n";
	cout << m1;
	cout << endl<<">matrix B: \n";
	cout << m2;
	cout << ">>Testing the multiply operation: \n";
	cout << "m1*m2 = \n" << m1 * m2;
	
}
