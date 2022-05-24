#include <iostream>
#include <string>
using namespace std;

// Шарафанович Денис, СБУ221
// Домашнее задание №3. ЦИКЛЫ

#define arrowPointer " -> "
#define doubleTab " \t\t "
#define inputError " Не корректное значение "
#define InputValue " Введите числовое значение:  "


void Task_1()
{
    string currentValue;
    cout << doubleTab << "Ввести значение температуры (Задание №1)." << endl;
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
        cout << " На улице тепло! ";
    }
    else if (stoi(currentValue) < 0)
    {
        cout << " На улице холодно! ";
    }
    else if (stoi(currentValue) == 0)
    {
        cout << " На улице " << currentValue;
    }

}
void Task_2()
{
    string currentValue;
    cout << doubleTab << "Поразить цель (Задание №2)." << endl;
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
        cout << " Цель не поражена! ";
    }
    else if (stoi(currentValue) > 0 && stoi(currentValue) < 10) // ЛИБО ПРОСТО ELSE
    {
        cout << " Цель поражена! ";
    }

}
void Task_3()
{
    string currentValue_1, currentValue_2;
    string operatorType;
    double result = 0;
    cout << doubleTab << "Калькулятор ) (Задание №3)." << endl;
    try
    {
        cout << "Введите первое значение и нажмите Enter" << arrowPointer;
        cin >> currentValue_1;
        stoi(currentValue_1);
        cout << "Введите один из представленных операторов: +, -, *, /, и нажмите Enter" << arrowPointer;
        cin >> operatorType;
        cout << "Введите второе значение и нажмите Enter" << arrowPointer;
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
        cout << "Введён не верный опереатор " << endl;
        Task_3();

    }

    cout << "Результат: " << result;

}
void TaskEnd()
{
    cout << "Программа завершилась";
}


void TaskSelection()
{
    string numberOfTask;
    cout << endl << doubleTab << "Введите номер домашнего задания для проверки, от 1 до 3, введите q для выхода" << arrowPointer;
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