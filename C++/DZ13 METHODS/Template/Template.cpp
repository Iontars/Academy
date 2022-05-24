#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
int tuskCounter;
#define Tusk "\t ����� " + to_string(tuskCounter) + ": "
int const globalSize = 5;
void TuskCounter();
void Message(int value);
template <typename T> void FillRand(T inputArr[globalSize]);
//template <typename T> void FillRand(T inputArr[globalSize], int minRand = 0, int MaxRand = 100);
template <typename T> void FillRand(T inputArr[globalSize][globalSize]);
template <typename T> void Screen(T inputArr[globalSize]);
template <typename T> void Screen(T inputArr[globalSize][globalSize]);
template <typename T> double Sum(T inputArr[globalSize]);
template <typename T> double Sum(T inputArr[globalSize][globalSize]);
template <typename T> double Avg(T inputArr[globalSize]);
template <typename T> double Avg(T inputArr[globalSize][globalSize]);

template <typename T> T MinValueIn(T inputArr[globalSize]);
template <typename T> T MinValueIn(T inputArr[globalSize][globalSize]);
template <typename T> T MaxValueIn(T inputArr[globalSize]);
template <typename T> T MaxValueIn(T inputArr[globalSize][globalSize]);

template <typename T>void ShiftRight(T inputArr[], int size);
template <typename T>void ShiftLeft(T inputArr[], int size);
template <typename T>void Sort(T inputArr[globalSize]);
//template <typename T>void Sort(T inputArr[globalSize][globalSize]);

template <typename T> void Display(T input);
template <typename T> void Display(T inputArr[globalSize]);
template <typename T> void Display(T inputArr[globalSize][globalSize]);


int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "");
    float arrDigit1[globalSize];
    int arrDigit2[globalSize][globalSize];

    FillRand(arrDigit1);
    FillRand(arrDigit2);
    Screen(arrDigit1);
    Screen(arrDigit2);
    Display(Sum(arrDigit1));
    Display(Sum(arrDigit2));
    Display(Avg(arrDigit1));
    Display(Avg(arrDigit2));
    Display(MinValueIn(arrDigit1));
    Display(MaxValueIn(arrDigit1));
    Display(MinValueIn(arrDigit2));
    Display(MaxValueIn(arrDigit2));
    Sort(arrDigit1);
    ShiftRight(arrDigit1, globalSize);
    ShiftLeft(arrDigit1, globalSize);
}

void Message(int value)
{
    switch (value)
    {
    case 1:
        cout << Tusk + "���������� ������ ��������" << endl; break;
    case 2:
        cout << Tusk + "��������� ������ ��������" << endl; break;
    case 3:
        cout << Tusk + "����� ����������� ������� �� �����" << endl; break;
    case 4:
        cout << Tusk + "����� ���������� ������� �� �����" << endl; break;
    case 5:
        cout << Tusk + "����� ��������� ����������� �������" << endl; break;
    case 6:
        cout << Tusk + "����� ��������� ���������� �������" << endl; break;
    case 7:
        cout << Tusk + "������� �������������� ��������� ����������� �������" << endl; break;
    case 8:
        cout << Tusk + "������� �������������� ��������� ���������� �������" << endl; break;
    case 9:
        cout << Tusk + "����������� �������� � ���������� �������" << endl; break;
    case 10:
        cout << Tusk + "����������� �������� � ��������� �������" << endl; break;
    case 11:
        cout << Tusk + "������������ �������� � ���������� �������" << endl; break;
    case 12:
        cout << Tusk + "������������ �������� � ��������� �������" << endl; break;
    case 13:
        cout << Tusk + "���������� ����������� ������� � ������� �����������, ��� ������ ��������� ������" << endl; break;
    case 14:
        cout << Tusk + "����������� ����� ������� �� �������� ����� ��������� ������" << endl; break;
    case 15:
        cout << Tusk + "����������� ����� ������� �� �������� ����� ��������� �����" << endl; break;
    default: break;
    }
}

void TuskCounter()
{
    tuskCounter++;
    Message(tuskCounter);
}

template <typename T> void FillRand(T inputArr[globalSize])//��������� ������
{
    TuskCounter();
    for (int i = 0; i < globalSize; i++) inputArr[i] = rand() % 100;
    cout << endl;
}
template <typename T> void FillRand(T inputArr[globalSize][globalSize])//��������� 2������ ������
{
    TuskCounter();

    for (int i = 0; i < globalSize; i++)
    {
        for (int j = 0; j < globalSize; j++)
        {
            inputArr[i][j] = rand() % 100;
        }
    }
    cout << endl;
}

template <typename T> void Screen(T inputArr[globalSize])
{
    TuskCounter();
    Display(inputArr);
}

template <typename T> void Screen(T inputArr[globalSize][globalSize])
{
    TuskCounter();
    Display(inputArr);
}

template <typename T> double Sum(T inputArr[globalSize])//����� 
{
    int sum = 0;
    TuskCounter();
    for (int i = 0; i < globalSize; i++) sum += inputArr[i];
    return sum;
}

template <typename T> double Sum(T inputArr[globalSize][globalSize])//����� 
{
    int sum = 0;
    TuskCounter();
    for (int i = 0; i < globalSize; i++)
    {
        for (int j = 0; j < globalSize; j++) sum += inputArr[i][j];
    }
    return sum;
}

template <typename T> double Avg(T inputArr[globalSize])//������� ��������������
{
    double sum = 0;
    TuskCounter();
    for (int i = 0; i < globalSize; i++) sum += inputArr[i];
    return sum / globalSize;
}

template <typename T> double Avg(T inputArr[globalSize][globalSize])//������� ��������������
{
    double sum = 0;
    TuskCounter();
    for (int i = 0; i < globalSize; i++)
    {
        for (int j = 0; j < globalSize; j++) sum += inputArr[i][j];
    }
    return (sum / (globalSize * globalSize));
}

template <typename T> T MinValueIn(T inputArr[globalSize])//��� ��������
{
    TuskCounter();
    T minValue = inputArr[0];
    for (int i = 0; i < globalSize; i++) if (inputArr[i] < minValue) minValue = inputArr[i];
    return minValue;
}

template <typename T> T MinValueIn(T inputArr[globalSize][globalSize])//��� ��������
{
    TuskCounter();
    T minValue = inputArr[0][0];
    for (int i = 0; i < globalSize; i++)
    {
        for (int j = 0; j < globalSize; j++) if (inputArr[i][j] < minValue) minValue = inputArr[i][j];
    }
    return minValue;
}

template <typename T> T MaxValueIn(T inputArr[globalSize])//���� ��������
{
    TuskCounter();
    T maxValue = inputArr[0];
    for (int i = 0; i < globalSize; i++) if (inputArr[i] > maxValue) maxValue = inputArr[i];
    return maxValue;
}

template <typename T> T MaxValueIn(T inputArr[globalSize][globalSize])//���� ��������
{
    TuskCounter();
    T maxValue = inputArr[0][0];
    for (int i = 0; i < globalSize; i++)
    {
        for (int j = 0; j < globalSize; j++) if (inputArr[i][j] > maxValue) maxValue = inputArr[i][j];
    }
    return maxValue;
}

//����� �� �����
template <typename T> void Display(T inputArr[globalSize])
{
    for (int i = 0; i < globalSize; i++) cout << inputArr[i] << "\t";
    cout << endl;
}
template <typename T> void Display(T input)
{
    cout << input << endl;
}
template <typename T> void Display(T inputArr[globalSize][globalSize])
{
    for (int i = 0; i < globalSize; i++)
    {
        for (int j = 0; j < globalSize; j++)
        {
            cout << inputArr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

//����� �����

template <typename T> void ShiftRight(T inputArr[], int size)
{
    TuskCounter();
    int shiftValue;
    const int newSize = 20;
    int newArray[newSize];
    cout << "�� ������� ������� ������ �������� ������?: ";
    cin >> shiftValue;
    int tempCounter = 0, counter = 0;
    for (int i = 0; i < size; i++)
    {
        newArray[i + shiftValue] = inputArr[i];
        tempCounter = i + shiftValue;
        if (tempCounter >= size)
        {
            newArray[counter] = inputArr[i]; counter++;
        }
    }
    Display(newArray);
    cout << endl;
}

//����� ������
template <typename T> void ShiftLeft(T inputArr[], int size)
{
    TuskCounter();
    int shiftValue;
    const int newSize = 20;
    int newArray[newSize];
    cout << "�� ������� ������� ����� �������� ������?: ";
    cin >> shiftValue;
    int tempCounter = 0, counter = size;
    for (int i = size - 1; i >= 0; i--)
    {
        newArray[i - shiftValue] = inputArr[i];
        tempCounter = i - shiftValue;
        if (tempCounter <= 0)
        {
            newArray[counter] = inputArr[i]; counter--;
        }
    }
    Display(newArray);
    cout << endl;
}

//����������
template <typename T> void Sort(T inputArr[globalSize])
{
    TuskCounter();
    for (int i = 0; i < globalSize - 1; i++)
    {
        int currentMinValue = i;
        for (int j = i + 1; j < globalSize; j++) if (inputArr[j] < inputArr[currentMinValue]) currentMinValue = j;
        if (currentMinValue != i) swap(inputArr[i], inputArr[currentMinValue]);

    }
    Display(inputArr);
    cout << endl;
}
