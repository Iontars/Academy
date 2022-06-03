#include <iostream>
#include <time.h>
using namespace std;

int otherArraySize = 0;
void FillRand(int* const array, int const size);
void DisplayMatrix(int* array, int squareSize);
void Even(int*& array, int*& even, int& size, int& evenSize);
void Odd(int*& array, int*& even, int& size, int& oddSize);
void DeleteDynamicArray(int* array); //(1) �� ���� ��������� �� ������ ���� ��� ������� � �����

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int size = 10, dynamicArraySize = 0;

    int* mainArray = new int [size];
    int* evenArray = new int[dynamicArraySize];
    int* oddArray = new int[dynamicArraySize];


    FillRand(mainArray, size);   
    DisplayMatrix(mainArray, size);
    cout << endl;

    Even(mainArray, evenArray, size, dynamicArraySize);
    DisplayMatrix(evenArray, dynamicArraySize); // ����� evenArray ��� ��������� �� ����� ������ � ����.
    cout << endl;
    
    
    Odd(mainArray, oddArray, size, dynamicArraySize);
    DisplayMatrix(oddArray, dynamicArraySize);
    cout << endl;
 
    delete[] mainArray; //(1) ������� ������ ��� )
    delete[] evenArray;
    delete[] oddArray;
}

void FillRand(int* const  array, int const size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 10;
    }
}

void DisplayMatrix(int* const array, int const size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}

//�������� �� ��������, ��������� ������� �� ������ ��������� ��������
void Even(int*& array, int*& even, int& size, int& evenSize) 
{
    int matchCounter = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0)
        {
            matchCounter++;
        }
    }
    int* evenTemp = new int[matchCounter];
    matchCounter = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0)
        {
            evenTemp[matchCounter] = array[i];
            matchCounter++;
        }
    }
    evenSize = matchCounter;
    delete[] even; //(1) ������� ������ ��� )
    even = evenTemp; // ���������� ������ �� ������ 
}

void Odd(int*& array, int*& odd, int& size, int& oddSize)
{
    int matchCounter = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 != 0)
        {
            matchCounter++;
        }
    }
    int* oddTemp = new int[matchCounter];
    matchCounter = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 != 0)
        {
            oddTemp[matchCounter] = array[i];
            matchCounter++;
        }
    }
    oddSize = matchCounter;
    delete[] odd;
    odd = oddTemp;
}

