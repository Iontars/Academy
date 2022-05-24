#include <iostream>
#include <string>
using namespace std;

// ����������� �����, ���221
// �������� ������� �4. �����

#define arrowPointer " -> "
#define doubleTab " \t\t "
#define inputError " �� ���������� �������� "
#define InputValue " ������� �������� ��������:  "

void Task_1();
void Task_2();
void TaskEnd();
void TaskSelection();

void Task_1()
{

    cout << doubleTab << " ��������� ����� (������� �1)." << endl;
    cout << InputValue << arrowPointer;
    int inputValue;
    int newValue = 0;
    cin >> inputValue;
    int currentValue = inputValue;

    while (currentValue != 0)
    {
        newValue = newValue * 10 + currentValue % 10;
        currentValue /= 10;
    }
    if (inputValue == newValue)
        std::cout << "���������!";
    else
        std::cout << "�� ���������!";

}
void Task_2()
{
    string inputtValue;
    int happyTicketValue = rand() % 5 - 1;
    cout << doubleTab << "���������� ����� (������� �2)." << endl;
    cout << InputValue << "�� 1 �� 5 " << arrowPointer;
    cin >> inputtValue;
    if (happyTicketValue == stoi(inputtValue))
        cout << "���������� �����";
    else
        cout << "�� ���������� �����";
}
void TaskEnd()
{
    cout << "��������� �����������";
}


void TaskSelection()
{
    string numberOfTask;
    cout << endl << doubleTab << "������� ����� ��������� ������� ��� ��������, �� 1 �� 3, ������� q ��� ������" << arrowPointer;
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