#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

#define UpArrow 72
#define DownArrow 80
#define LeftArrow 75
#define RightArrow 77
#define Space -32
#define Enter 10



    cout << "Shooter" << endl;

    char key;
    do
    {
        key = _getch();
        //cout << int(key) << "\t" << key << endl;
        switch (key)
        {
        case 'w': cout << "Вперед" << endl;
            break;
        case UpArrow: cout << "Вперед" << endl;
            break;
        case 'd': cout << "Вправо" << endl;
            break;
        case RightArrow: cout << "Вправо" << endl;
            break;
        case 'a': cout << "Влево" << endl;
            break;
        case LeftArrow: cout << "Влево" << endl;
            break;
        case 's': cout << "Назад" << endl;
            break;
        case DownArrow: cout << "Назад" << endl;
            break;
        case Space: cout << "Прыжок" << endl;
            break;
        case Enter: cout << "Огонь" << endl;
            break;
        default: if (key != 27 && key != 32) cout << "Ошибка" << endl;
            break;
        }
    } while (key != 27);
}
