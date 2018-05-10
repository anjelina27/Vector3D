#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector_3d.h"
#include "vector_functions.h"

using namespace std;

const int kMaxNumberOfVectors = 10001;

int main()
{
	Vector3D array_of_vectors[kMaxNumberOfVectors];
	int number_of_vect;
	char sign;
	cin >> sign;///����������� �� ����������� �� ������ ���� ������ � ������ ���� ����� � ��������,
	///����������� ������� ������:
	if (IsPlus(sign))///������ +
	{
		cin >> number_of_vect;
		if (number_of_vect == 0) return 0;
		EnterArr(number_of_vect, array_of_vectors);
		cout << SumVectors(number_of_vect, array_of_vectors);
	}
	else if (IsMinus(sign))///������ -
	{
		cin >> number_of_vect;
		if (number_of_vect == 0) return 0;
		EnterArr(number_of_vect, array_of_vectors);
		cout << DiffVectors(number_of_vect, array_of_vectors);
	}
	else if (IsNeg(sign))///������ N
	{///���� ���� �����, �� ������� ������� ������ � "N",
		char e, g;///���� ����� ����������, ����� �� ���� �������� ���������� "NEG",
		cin >> e >> g; ///������ ����������� �� ����� �������� ��� 2 ������� - ������� � � g
		cin >> number_of_vect;
		if (number_of_vect == 0) return 0;
		EnterArr(number_of_vect, array_of_vectors);
		Negative(number_of_vect, array_of_vectors);
	}
	else if (IsStar(sign))///������ *
	{
		float NUM;
		cin >> NUM;
		cin >> number_of_vect;
		if (number_of_vect == 0) return 0;
		EnterArr(number_of_vect, array_of_vectors);
		ProdNumAndVect(NUM, number_of_vect, array_of_vectors);

	}
	else///���� ������
	{   ///��� ���� ��������, �� ������ � �������,
		///��� �� � � ���� ���� �� ���������� ������, �� ���������� �� ����� � ����.
		char number[10]; ///��������� ����� �� char-���, �� ����� ����������� 
		number[0] = sign;///�� �������� � ����� ������ ����� ������� ������
		int i = 1;
		do
		{
			cin >> number[i];
			i++;
		} while (number[i - 1] != '*');///��������� ���������� ������� �� �������,
		number[i-1] = '\0';///���� �������� ������������� ���� �� ������� �� '*', �� �� �� �� ���� �� ��� ���������� �� ������ ��� ����� float
		const char* kConstNumberString = number;///�������� ������ �� ������� ��� ����� � ������� �������
		float NUM;
		NUM = atof(kConstNumberString);
		cin >> number_of_vect;
		if (number_of_vect == 0) return 0;
		EnterArr(number_of_vect, array_of_vectors);
		ProdVectAndNum(NUM, number_of_vect, array_of_vectors);
	} 
	return 0;
}



