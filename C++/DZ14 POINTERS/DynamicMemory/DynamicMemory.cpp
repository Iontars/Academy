#include <iostream>
using namespace std;

int otherArraySize;
void FillRand(int* const array, int const size);
void DisplayMatrix(int* array, int squareSize);
void PushBack(int*& array, int& size, int value);
void PushFront(int*& array, int& size, int value);
void PopBack(int*& array, int& size);
void PopFront(int*& array, int& size);
void Insert(int*& array, int& size, int index, int value);
void Erase(int*& array, int& size, int index);



int main()
{
    int size = 10;

    int* mainArray = new int[size];

    FillRand(mainArray, size);
    DisplayMatrix(mainArray, size);

    PushBack(mainArray, size, 8);
    DisplayMatrix(mainArray, size);

    PushFront(mainArray, size, 8);
    DisplayMatrix(mainArray, size);

    Insert(mainArray, size, 3, 8);  
    DisplayMatrix(mainArray, size);

    PopBack(mainArray, size);
    DisplayMatrix(mainArray, size);

    PopFront(mainArray, size);
    DisplayMatrix(mainArray, size);

    Erase(mainArray, size, 0);
    DisplayMatrix(mainArray, size);


    delete[] mainArray;
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

void PushBack(int*& array, int& size, int value)
{
    int* newArray = new int[size + 1];
    for (int i = 0; i < size; i++) newArray[i] = array[i];
    newArray[size] = value;
    size++;
    delete[] array;
    array = newArray;
}
void PushFront(int*& array, int& size, int value)
{
    int* newArray = new int[size + 1];
    for (int i = 1; i < size+1; i++) newArray[i] = array[i-1];
    newArray[0] = value;
    size++;
    delete[] array;
    array = newArray;
}
void Insert(int*& array, int& size, int index, int value)
{
    int* newArray = new int[size];
    for (int i = 0; i < size; i++) newArray[i] = array[i];
    newArray[index] = value;
    delete[] array;
    array = newArray;
}

void PopBack(int*& array, int& size)
{
    int* newArray = new int[size - 1];
    for (int i = 0; i < size - 1; i++) newArray[i] = array[i];
    size--;
    delete[] array;
    array = newArray;
}

void PopFront(int*& array, int& size)
{
    int* newArray = new int[size - 1];
    for (int i = 1; i < size ; i++) newArray[i-1] = array[i];
    size--;
    delete[] array;
    array = newArray;
}

void Erase(int*& array, int& size, int index)
{
    int* newArray = new int[size];
    for (int i = 0; i < size; i++) newArray[i] = array[i];
    newArray[index] = 0;
    delete[] array;
    array = newArray;
}