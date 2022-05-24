#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	const int hardArraySize = 10;
	int newArray[hardArraySize * 2];
	int hardArray[hardArraySize];
	int checkArray[hardArraySize];
	int i, j, minValue, maxValue, shiftValue;
	bool isMatch = true, noMatch = true;
	int number = 0;
	float sum = 0;

	//���������� �������
	cout << "\t" << "���������� �������" << endl;
	for (i = 0; i < hardArraySize; i++)
	{
		cout << "������� " << i + 1 << " ������� �������: ";
		cin >> hardArray[i];
	}

	//����� ���� �������� �������
	cout << endl << "\t" << "����� ���� ��������� �������" << endl;
	for (i = 0; i < hardArraySize; i++)	cout << hardArray[i] << "\t";


	//����� ���� �������� ������� (������)
	cout << endl << "\t" << "����� ���� ��������� ������� (������)" << endl;
	for (i = hardArraySize - 1; i >= 0; i--) cout << hardArray[i] << "\t";


	//����������
	cout << endl << endl << "\t" << "����������" << endl;
	for (i = 0; i < hardArraySize; i++)
	{
		sum += hardArray[i];
		if (i == hardArraySize - 1)
		{
			cout << "����� ��������� ������� �����: " << sum << endl;
			cout << "������� �������������� �������: " << sum / hardArraySize << endl << endl;
		}
	}

	//�����������/������������ �������� �������
	cout << endl << "\t" << "�����������/������������ �������� �������" << endl;
	for (i = 0; i < hardArraySize; i++)
	{
		if (i == 0)
		{
			minValue = hardArray[i];
			maxValue = hardArray[i];
		}
		if (hardArray[i] < minValue) minValue = hardArray[i];
		if (hardArray[i] > maxValue) maxValue = hardArray[i];
		if (i == hardArraySize - 1) // ��������� ��������
		{
			cout << "����������� ��������: " << minValue << endl;
			cout << "������������ ��������: " << maxValue << endl << endl;
		}
	}

	//����� ������������� ��������
	cout << endl << "\t" << "����� ������������� ��������" << endl;
	for (i = 0; i < hardArraySize; i++)
	{
		isMatch = true;
		for (int q = 0; q < hardArraySize; q++) // �������� �� ��������� ����� �����
		{
			if (hardArray[i] == checkArray[q])	isMatch = false;
		}
		for (j = 0; j < hardArraySize && isMatch; j++) // �������� �������� �������� ������� �� ����� �� ��������
		{
			if (hardArray[i] == hardArray[j])
			{
				checkArray[i] = hardArray[i]; number++; // ����������� �����	
			}
		}
		if (number > 1) // ����� �� ����� ����� ���� ��� ���������� ���������� >= 2 
		{
			cout << "�����: " << checkArray[i] << " �����������: " << number - 1 << " ��� " << endl;
			noMatch = false;
		}
		number = 0;
		if (noMatch && i == hardArraySize - 1) cout << "��������� ���" << endl;
	}

	//����� ������� ������
	cout << endl << "\t" << "����� ������� ������" << endl;
	cout << "�� ������� ������� �������� ������?: ";
	cin >> shiftValue;
	int tempCounter = 0, counter = 0;
	for (i = 0; i < hardArraySize; i++)
	{
		newArray[i + shiftValue] = hardArray[i];
		tempCounter = i + shiftValue;
		if (tempCounter >= hardArraySize)
		{
			newArray[counter] = hardArray[i]; counter++;
		}
	}
	for (i = 0; i < hardArraySize; i++)	cout << hardArray[i] << "\t";
	cout << endl;
	for (i = 0; i < hardArraySize; i++) cout << newArray[i] << "\t";
	cout << endl;
}
