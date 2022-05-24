#include <iostream>
#include <string>
using namespace std;

// Шарафанович Денис, СБУ221
// Домашнее задание №4. ЦИКЛЫ

#define arrowPointer " -> "
#define doubleTab " \t\t "
#define inputError " Не корректное значение "
#define InputValue " Введите числовое значение:  "

void Task_1();
void Task_2();
void TaskEnd();
void TaskSelection();

void Task_1()
{

    cout << doubleTab << " Полиндром числа (Задание №1)." << endl;
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
        std::cout << "Палиндром!";
    else
        std::cout << "Не полиндром!";

}
void Task_2()
{
    string inputtValue;
    int happyTicketValue = rand() % 5 - 1;
    cout << doubleTab << "Счастливый билет (Задание №2)." << endl;
    cout << InputValue << "от 1 до 5 " << arrowPointer;
    cin >> inputtValue;
    if (happyTicketValue == stoi(inputtValue))
        cout << "Счастливый билет";
    else
        cout << "Не счастливый билет";
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