#include <iostream>
using namespace std;

#define arrowPointer " -> "
#define doubleTab " \t\t "
#define inputError " �� ���������� �������� "
#define InputValue " ������� �������� ��������:  "

void Task_1();
void Task_2();
void Task_3();
void Task_4();
void TaskEnd();
void TaskSelection();

void Task_1()
{
    long value = 0;
    long temp = 1;
    cout << doubleTab << "��������� ����� (������� �1)." << endl;
    cout << InputValue << arrowPointer;
    cin >> value;
    for (int i = 1; i <= value; i++)
    {
        temp *= i;
    }
    cout << "��������� ����� " << value << " ����� " << temp;
}

void Task_2()
{
    int number, powerOfNumber;
    int result = 1;
    cout << doubleTab << "���������� � ������� (������� �2)." << endl;
    cout << "������� �������� ����� " << endl;
    cin >> number;
    cout << "������� ������� ����� " << endl;
    cin >> powerOfNumber;
    for (int i = 0; i < powerOfNumber; i++)
    {
        result *= number;
    }
    cout << number << "^" << powerOfNumber << " = " << result;
}

void Task_3()
{
    cout << doubleTab << "������� ASCII-�������� (������� �3)." << endl;
    setlocale(LC_ALL, "EN");
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 16; ++j)
        {
            int n = (i << 4) + j;
            if (isgraph(n)) cout << static_cast<char>(n) << ' ';
            else cout << "  ";
        }
        cout << endl;
    }
    setlocale(LC_ALL, "ru");
}
void Task_4()
{
    int number;
    bool point;
    int j;
    cout << doubleTab << "��� ������� ����� (������� �3)." << endl;
    cout << InputValue << arrowPointer;
    cin >> number;
    for (int i = 2; i < number; i++)
    {
        point = true;
        for (j = 2; j < i; j++)
            if (!(i % j))
            {
                point = false;
                break;
            }
        if (point == true)
        {
            cout << j << endl;
        }
    }
}

void TaskEnd()
{
    cout << "��������� �����������!";
}

void TaskSelection()
{
    string numberOfTask;
    cout << endl << doubleTab << "������� ����� ��������� ������� ��� ��������, �� 1 �� 4, ������� q ��� ������" << arrowPointer;
    cin >> numberOfTask; cout << endl;
    if (numberOfTask == "1")
    {
        Task_1();
        TaskSelection();
    }
    else if (numberOfTask == "2")
    {
        Task_2();
        TaskSelection();
    }
    else if (numberOfTask == "3")
    {
        Task_3();
        TaskSelection();
    }
    else if (numberOfTask == "4")
    {
        Task_4();
        TaskSelection();
    }
    else if (numberOfTask == "q")
    {
        TaskEnd();
    }
    else
    {
        cout << inputError << endl;
        TaskSelection();
    }
}

int main()
{
    setlocale(LC_ALL, "");
    TaskSelection();
}
