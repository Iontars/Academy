#include <iostream>
using namespace std;

int otherArraySize;
template <typename T> void FillRand(T* const array, int const size);
template <typename T> void DisplayMatrix(T* array, int squareSize);
template <typename T> void PushBack(T*& array, int& size, int value);
template <typename T> void PushFront(T*& array, int& size, int value);
template <typename T> void PopBack(T*& array, int& size);
template <typename T> void PopFront(T*& array, int& size);
template <typename T> void Insert(T*& array, int& size, int index, int value);
template <typename T> void Erase(T*& array, int& size, int index);

int main()
{
    int size = 10;

    int* mainArray = new int[size];

    FillRand(mainArray, size);
    DisplayMatrix(mainArray, size);

    PushBack(mainArray, size, 888);
    DisplayMatrix(mainArray, size);

    PushFront(mainArray, size, 888);
    DisplayMatrix(mainArray, size);

    Insert(mainArray, size, 3, 888);  
    DisplayMatrix(mainArray, size);

    PopBack(mainArray, size);
    DisplayMatrix(mainArray, size);

    PopFront(mainArray, size);
    DisplayMatrix(mainArray, size);

    Erase(mainArray, size, 0);
    DisplayMatrix(mainArray, size);

    delete[] mainArray;
}

template <typename T> void FillRand(T* const  array, int const size)
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

template <typename T> void PushBack(T*& array, int& size, int value)
{
    T* newArray = new T[size + 1];
    for (int i = 0; i < size; i++) newArray[i] = array[i];
    newArray[size] = value;
    size++;
    delete[] array;
    array = newArray;
}
template <typename T> void PushFront(T*& array, int& size, int value)
{
    T* newArray = new T[size + 1];
    for (int i = 1; i < size+1; i++) newArray[i] = array[i-1];
    newArray[0] = value;
    size++;
    delete[] array;
    array = newArray;
}
template <typename T> void Insert(T*& array, int& size, int index, int value)
{
    T* newArray = new T[size];
    for (int i = 0; i < size; i++) newArray[i] = array[i];
    newArray[index] = value;
    delete[] array;
    array = newArray;
}

template <typename T> void PopBack(T*& array, int& size)
{
    T* newArray = new T[size - 1];
    for (int i = 0; i < size - 1; i++) newArray[i] = array[i];
    size--;
    delete[] array;
    array = newArray;
}

template <typename T> void PopFront(T*& array, int& size)
{
    T* newArray = new T[size - 1];
    for (int i = 1; i < size ; i++) newArray[i-1] = array[i];
    size--;
    delete[] array;
    array = newArray;
}

template <typename T> void Erase(T*& array, int& size, int index)
{
    T* newArray = new T[size];
    for (int i = 0; i < size; i++) newArray[i] = array[i];
    newArray[index] = 0;
    delete[] array;
    array = newArray;
}