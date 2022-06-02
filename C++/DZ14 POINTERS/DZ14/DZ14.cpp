#include <iostream>
using namespace std;

int otherArraySize = 0;
void FillRand(int* const array, int const size);
void DisplayMatrix(int* array, int squareSize);
void Even(int*& array, int*& even, int& size);
void Odd(int*& array, int*& even, int& size);

int main()
{
    int size = 10, otherArraySize;

    int* mainArray = new int [size];
    int* evenArray = new int[];
    int* oddArray = new int[];

    FillRand(mainArray, size);
    Even(mainArray, evenArray, size);
    DisplayMatrix(evenArray, otherArraySize);


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


void Even(int*& array, int*& even, int& size)
{
   
}

void Odd(int*& array, int*& odd, int& size)
{

}
