#include <iostream>
#include <string>
using namespace std;

// ����������� �����, ���221
// �������� ������� �3. �����

#define arrowPointer " -> "
#define doubleTab " \t\t "
#define inputError " �� ���������� �������� "
#define InputValue " ������� �������� ��������:  "


void Task_1()
{
    string currentValue;
    cout << doubleTab << "������ �������� ����������� (������� �1)." << endl;
    cout << InputValue << arrowPointer;

    try
    {
        cin >> currentValue;
        stoi(currentValue);
    }
    catch (...)
    {
        cout << inputError << endl;
        currentValue = "0";
        Task_1();
    }
    if (stoi(currentValue) > 0)
    {
        cout << " �� ����� �����! ";
    }
    else if (stoi(currentValue) < 0)
    {
        cout << " �� ����� �������! ";
    }
    else if (stoi(currentValue) == 0)
    {
        cout << " �� ����� " << currentValue;
    }

}
void Task_2()
{
    string currentValue;
    cout << doubleTab << "�������� ���� (������� �2)." << endl;
    cout << InputValue << arrowPointer;

    try
    {
        cin >> currentValue;
        stoi(currentValue);
    }
    catch (...)
    {
        cout << inputError << endl;
        currentValue = "0";
        Task_2();
    }
    if (stoi(currentValue) < 0 || stoi(currentValue) > 10)
    {
        cout << " ���� �� ��������! ";
    }
    else if (stoi(currentValue) > 0 && stoi(currentValue) < 10) // ���� ������ ELSE
    {
        cout << " ���� ��������! ";
    }

}
void Task_3()
{
    string currentValue_1, currentValue_2;
    string operatorType;
    double result = 0;
    cout << doubleTab << "����������� ) (������� �3)." << endl;
    try
    {
        cout << "������� ������ �������� � ������� Enter" << arrowPointer;
        cin >> currentValue_1;
        stoi(currentValue_1);
        cout << "������� ���� �� �������������� ����������: +, -, *, /, � ������� Enter" << arrowPointer;
        cin >> operatorType;
        cout << "������� ������ �������� � ������� Enter" << arrowPointer;
        cin >> currentValue_2;
        stoi(currentValue_2);

    }
    catch (...)
    {
        cout << inputError << endl;
        currentValue_1 = "0";
        Task_3();
    }
    if (operatorType == "+")
    {
        result = stoi(currentValue_1) + stoi(currentValue_2);
    }
    else if (operatorType == "-")
    {
        result = stoi(currentValue_1) - stoi(currentValue_2);

    }
    else if (operatorType == "*")
    {
        result = stoi(currentValue_1) * stoi(currentValue_2);

    }
    else if (operatorType == "/")
    {
        result = stoi(currentValue_1) / stoi(currentValue_2);

    }
    else
    {
        cout << "����� �� ������ ��������� " << endl;
        Task_3();

    }

    cout << "���������: " << result;

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
    else if (numberOfTask == "3")
    {
        Task_3();
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
    setlocale(LC_ALL, "ru");
    TaskSelection();
}