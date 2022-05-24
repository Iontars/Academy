#include <iostream>
using namespace std;

int main()
{
    //setlocale(LC_ALL, "ru");
    char space = ' ';
    char rightDirection = '/';
    char leftDirection = '\\';
    int outerLoop, insideLoop, size = 0;
    //
    string symbol_1 = "+ ";
    string symbol_2 = "- ";
    char star = '*';
    //
    cout << "Enter the size ";
    cin >> size;
    cout << endl;

    // Квадрат
    for (outerLoop = 1; outerLoop <= size; outerLoop++)
    {
        for (insideLoop = 0; insideLoop < size; insideLoop++)
            cout << star;
        cout << endl;
    }
    cout << endl;

    // Треугольники
    for (outerLoop = 1; outerLoop <= size; outerLoop++)
    {
        for (insideLoop = (size - outerLoop); insideLoop > 0; insideLoop--)
            cout << space;
        for (insideLoop = 1; insideLoop < outerLoop + 1; insideLoop++)
            cout << star;
        cout << endl;
    }
    cout << endl;
    for (outerLoop = 1; outerLoop <= size; outerLoop++)
    {
        for (insideLoop = 1; insideLoop < outerLoop; insideLoop++)
            cout << space;
        for (insideLoop = (size + 1 - outerLoop); insideLoop > 0; insideLoop--)
            cout << star;
        cout << endl;
    }
    cout << endl;
    for (outerLoop = 1; outerLoop <= size; outerLoop++)
    {
        for (insideLoop = 1; insideLoop < outerLoop + 1; insideLoop++)
            cout << star;
        cout << endl;
    }
    cout << endl;
    for (outerLoop = 1; outerLoop <= size; outerLoop++)
    {
        for (insideLoop = (size + 1 - outerLoop); insideLoop > 0; insideLoop--)
            cout << star;
        cout << endl;
    }
    cout << endl;

    // Ромб включающий в себя все простые треугольники
    for (outerLoop = 1; outerLoop <= size; outerLoop++)
    {
        for (insideLoop = (size + 1 - outerLoop); insideLoop > 0; insideLoop--)
            cout << space;
        for (insideLoop = 1; insideLoop < outerLoop + 1; insideLoop++)
            cout << rightDirection;
        for (insideLoop = 1; insideLoop < outerLoop + 1; insideLoop++)
            cout << leftDirection;
        cout << endl;
    }
    for (outerLoop = 1; outerLoop <= size; outerLoop++)
    {
        for (insideLoop = 1; insideLoop < outerLoop + 1; insideLoop++)
            cout << space;
        for (insideLoop = (size + 1 - outerLoop); insideLoop > 0; insideLoop--)
            cout << leftDirection;
        for (insideLoop = (size + 1 - outerLoop); insideLoop > 0; insideLoop--)
            cout << rightDirection;
        cout << endl;
    }
    cout << endl;

    // Ромб с дыркой
    for (outerLoop = 1; outerLoop <= size; outerLoop++)
    {
        for (insideLoop = (size + 1 - outerLoop); insideLoop > 0; insideLoop--)
            cout << space;
        //for (insideLoop = 1; insideLoop < 2; insideLoop++)
        cout << rightDirection;
        for (insideLoop = 1; insideLoop < outerLoop; insideLoop++)
            cout << space << space;
        //for (insideLoop = 1; insideLoop < 2; insideLoop++)
        cout << leftDirection;
        cout << endl;
    }
    for (outerLoop = 1; outerLoop <= size; outerLoop++)
    {
        for (insideLoop = 1; insideLoop < outerLoop + 1; insideLoop++)
            cout << space;
        //for (insideLoop = 1; insideLoop > 0; insideLoop--)
        cout << leftDirection;
        for (insideLoop = (size - outerLoop); insideLoop > 0; insideLoop--)
            cout << space << space;
        //for (insideLoop = 1; insideLoop > 0; insideLoop--)
        cout << rightDirection;
        cout << endl;
    }
    cout << endl;

    // Плюс-минус
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (/*(j % 2 == 0 && i % 2 == 0) || (j % 2 != 0 && i % 2 != 0)*/i % 2 == j % 2)
                cout << symbol_1;
            else
                cout << symbol_2;
        }
        cout << endl;
    }
    cout << endl;

    //Шахматная доска
    cout << char(218);
    for (int i = 0; i < size; i++)
    {
        cout << char(196) << char(196);
    }
    cout << char(180); // не по глазам найти правый верхний уголок в аски таблице )))
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << char(179);
        for (int j = 0; j < size; j++)
        {
            if ((j % 2 == 0 && i % 2 == 0) || (j % 2 != 0 && i % 2 != 0))
                cout << char(219) << char(219);
            else
                cout << char(255) << char(255);
        }
        cout << char(179);
        cout << endl;
    }
    cout << char(192);
    for (int i = 0; i < size; i++)
    {
        cout << char(196) << char(196);
    }
    cout << char(217);
}
