#include <iostream>
using namespace std;

// Метод треугольник
float fac(float size)
{
    int result = 1;
    for (int i = 1; i <= size; i++)
    {
        result *= i;
    }
    return result;
}
//
//            *                * - verticalStepPoint
// # |  |   | + |   |   |      # - gorizontalStepPoint
//   |  |   |   |   |   |      + - Текущее место отрисовки     
//   |  |   |   |   |   |

// Методы шахматной доски
void DrawMagicStar(int SizeOfSquare, int gorizontalStepPoint)
{
    string symbol_1 = "+ ";
    string symbol_2 = "- ";
    for (int verticalStepPoint = 0; verticalStepPoint < SizeOfSquare; verticalStepPoint++)
    {
        if ((verticalStepPoint % 2 == 0 && gorizontalStepPoint % 2 == 0) || (verticalStepPoint % 2 != 0 && gorizontalStepPoint % 2 != 0))
            cout << symbol_1;
        else
            cout << symbol_2;
    }
}
void DrawEndlessSpace(int inputValue)
{
    for (int i = 0; i < inputValue; i++)
    {
        cout << "  ";
    }
}
//
int main()
{
#define DoubleWhiteBox char(219)<<char(219)
#define TrippleWhiteBox char(219)<<char(219)<<char(219)
#define QuadrupleSpaceField "    "
    float sizeOfPyramid, result;
    int siseOfSquare = 5;

    // Треугольник Паскаля
    cout << "Enter the Size: ";  // ¯\_(ツ)_/¯ По формуле Ньютона, почему то числа перестают складываться коррекно, когда их ожидаимая длина должна превысить 4 значное число, наглядо видно во Float режиме ))
    // происходит это после 13 итерации пирамиды 
    cin >> sizeOfPyramid;

    for (int i = 0; i < sizeOfPyramid + 1; i++)
        cout << "    ";
    cout << char(219) << char(219) << endl;

    for (int i = 0; i < sizeOfPyramid; i++)
    {
        for (int c = sizeOfPyramid - i; c > 0; c--)
            cout << QuadrupleSpaceField;
        cout << char(219);

        for (int c = 0; c <= i; c++)
        {
            result = fac(i) / (fac(c) * fac(i - c));
            if (result < 10)
                cout << TrippleWhiteBox << "0" << result << TrippleWhiteBox;
            else if (result >= 10 && result < 100)
                cout << TrippleWhiteBox << result << TrippleWhiteBox;
            else if (result >= 100 && result < 1000)
                cout << DoubleWhiteBox << "0" << result << DoubleWhiteBox;
            else if (result >= 1000 && result < 10000)
                cout << DoubleWhiteBox << result << DoubleWhiteBox;
        }
        cout << char(219) << endl;
    }
    cout << endl << endl;

    // Шахматная доска Pro
    for (int z = 0; z < siseOfSquare * 5; z++)
    {
        if (z >= 0 && z < siseOfSquare || z >= 10 && z < siseOfSquare * 3 || z >= siseOfSquare * 4)
        {
            for (int i = 0; i < siseOfSquare; i++)
            {
                if (i % 2)
                {
                    DrawEndlessSpace(siseOfSquare);
                }
                else
                {
                    DrawMagicStar(siseOfSquare, z);
                }
            }
            cout << endl;
        }
        else
        {
            for (int i = 0; i < siseOfSquare; i++)
            {
                if (i % 2)
                {
                    DrawMagicStar(siseOfSquare, z);
                }
                else
                {
                    DrawEndlessSpace(siseOfSquare);
                }
            }
            cout << endl;
        }
    }
    setlocale(LC_ALL, "");
    cout << endl << "Пирамида вверху" << endl;
}
