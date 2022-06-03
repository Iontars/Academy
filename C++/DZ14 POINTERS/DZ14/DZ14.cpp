#include <iostream>
#include <time.h>
using namespace std;

int otherArraySize = 0;
template <typename T> void FillRand(T*  array, int  size);
template <typename T> void DisplayMatrix(T* array, int squareSize);
template <typename T> void Even(T*& array, T*& even, int& size, int& evenSize);
template <typename T> void Odd(T*& array, T*& even, int& size, int& oddSize);
template <typename T>  void DeleteDynamicArray(T* array); //(1) не знаю удаляется ли массив если его загнать в метод

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
    DisplayMatrix(evenArray, dynamicArraySize); // Здесь evenArray уже ссылается на новый массив в куче.
    cout << endl;
      
    Odd(mainArray, oddArray, size, dynamicArraySize);
    DisplayMatrix(oddArray, dynamicArraySize);
    cout << endl;
 
    delete[] mainArray; //(1) поэтому сделал так )
    delete[] evenArray;
    delete[] oddArray;
}

template <typename T> void FillRand(T* array, int  size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 10;
    }
}

template <typename T> void DisplayMatrix(T* const array, int const size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
}

//работаем со ссылками, позволяет вернуть из метода множество значений
template <typename T> void Even(T*& array, T*& even, int& size, int& evenSize)
{
    int matchCounter = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0)
        {
            matchCounter++;
        }
    }
    T* evenTemp = new T[matchCounter];
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
    delete[] even; //(1) поэтому сделал так )
    even = evenTemp; // перезапись ссылки на массив 
}

template <typename T> void Odd(T*& array, T*& odd, int& size, int& oddSize)
{
    int matchCounter = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 != 0)
        {
            matchCounter++;
        }
    }
    T* oddTemp = new T[matchCounter];
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

