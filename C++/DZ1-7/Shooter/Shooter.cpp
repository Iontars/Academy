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
        case 'w': cout << "������" << endl;
            break;
        case UpArrow: cout << "������" << endl;
            break;
        case 'd': cout << "������" << endl;
            break;
        case RightArrow: cout << "������" << endl;
            break;
        case 'a': cout << "�����" << endl;
            break;
        case LeftArrow: cout << "�����" << endl;
            break;
        case 's': cout << "�����" << endl;
            break;
        case DownArrow: cout << "�����" << endl;
            break;
        case Space: cout << "������" << endl;
            break;
        case Enter: cout << "�����" << endl;
            break;
        default: if (key != 27 && key != 32) cout << "������" << endl;
            break;
        }
    } while (key != 27);
}
