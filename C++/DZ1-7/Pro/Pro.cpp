#include <iostream>
#include <string>
using namespace std;

//ОБЩИЕ МАКРОСЫ
#define currencyType " грн. "
#define brCurrencyType " (грн.)"
#define pennyType " коп. "
#define bundle " (шт.) "
#define km " км. "
#define arrowPointer " -> "
#define doubleTab " \t\t "

#define TASK_REGION_1
#define TASK_REGION_2
#define TASK_REGION_3
#define TASK_REGION_4

string numberOfTask;
//ПЕРЕМЕННЫЕ ДЛЯ ЗАДАЧИ №1
double value, rub, penny;
//ПЕРЕМЕННЫЕ ДЛЯ ЗАДАЧИ №2
int numbersOfCopybook, numbersOfPencil;
double copybookPrice, pencilPrice, copybookTotalCost, pencilTotalCost, currentTotalCost;
//ПЕРЕМЕННЫЕ ДЛЯ ЗАДАЧИ №3
int numberOfBundles;
double copybookPrice_2, copybookCoverPrice, currentCost;
//ПЕРЕМЕННЫЕ ДЛЯ ЗАДАЧИ №4
double roadDistance, gasConsum, gasCost, totalCost;
//ПЕРЕЧИСЛЕНИЯ ДЛЯ ВЫБОРА ЗАДАЧИ
enum Tasks
{
    TASK_1 = 1, TASK_2 = 2, TASK_3 = 3, TASK_4 = 4
};
Tasks tasks;
//МЕТОДЫ ДЛЯ РЕШЕНИЯ ЗАДАЧ
void Task_1_calc()
{
    rub = (int)value;
    penny = (value - rub);
}
void Task_2_calc()
{
    copybookTotalCost = numbersOfCopybook * copybookPrice;
    pencilTotalCost = numbersOfPencil * pencilPrice;
    currentTotalCost = copybookTotalCost + pencilTotalCost;
}
void Task_3_calc()
{
    currentCost = numberOfBundles * (copybookPrice_2 + copybookCoverPrice);
}
void Task_4_calc()
{
    totalCost = gasConsum / 100 * (roadDistance * 2) * gasCost;
}
//ТОЧКА ВХОДА
int main()
{
    cout << typeid(numberOfTask).name();
    setlocale(LC_ALL, "ru");
tryAgain: // Метка перехода на выбор задачи
    cout << endl << doubleTab << "Введите номер домашнего задания для проверки, от 1 до 4" << arrowPointer;
    cin >> numberOfTask; cout << endl;
    //ОБРАБОТЧИК ОШИБОК НА СЛУЧАЙ ВВОДА НЕ КОРРЕКТНЫХ ДАННЫХ (реализовал только на этапе выбора задания, дабы не перегружать код)
    try
    {
        switch (stoi(numberOfTask))
        {
        case 1:
            tasks = TASK_1; break;
        case 2:
            tasks = TASK_2; break;
        case 3:
            tasks = TASK_3; break;
        case 4:
            tasks = TASK_4; break;
        default:
            cout << endl << doubleTab << "Введено не корректное значение, попробуйте снова!" << endl;
            goto tryAgain; break;
        }
    }
    catch (...)
    {
        cout << endl << doubleTab << "Введено не корректное значение, попробуйте снова!" << endl;
        goto tryAgain;
    }

#if defined  TASK_REGION_1
    if (tasks == 1)
    {
        cout << doubleTab << "Преобразование числа в денежный формат (Задание №1)." << endl;
        cout << "Введите дробное число" << arrowPointer;
        cin >> value; cout << endl;
        Task_1_calc();
        cout << value << currencyType << " - это " << rub << currencyType << penny << pennyType << endl;
        goto tryAgain;
    }
#endif

#if defined  TASK_REGION_2
    if (tasks == 2)
    {
        cout << doubleTab << "Вычисление стоимости покупки (Задание №2)." << endl;
        cout << "Введите исходные данные: " << endl;
        cout << "Цена тертади" << brCurrencyType << arrowPointer;
        cin >> copybookPrice;
        cout << "Колчество тетадей" << arrowPointer;
        cin >> numbersOfCopybook;
        cout << "Цена карандаша" << brCurrencyType << arrowPointer;
        cin >> pencilPrice;
        cout << "Колчество карандашей" << arrowPointer;
        cin >> numbersOfPencil;
        Task_2_calc();
        cout << "Стоимость покупки: " << currentTotalCost << currencyType << endl;
        goto tryAgain;
    }
#endif

#if defined  TASK_REGION_3
    if (tasks == 3)
    {
        cout << doubleTab << "Вычисление стоимости покупки (Задание №3)." << endl;
        cout << "Введите исходные данные: " << endl;
        cout << "Цена тертади" << brCurrencyType << arrowPointer;
        cin >> copybookPrice_2;
        cout << "Цена обложки" << brCurrencyType << arrowPointer;
        cin >> copybookCoverPrice;
        cout << "Колчество комплектов" << bundle << arrowPointer;
        cin >> numberOfBundles;
        Task_3_calc();
        cout << "Стоимость покупки: " << currentCost << currencyType << endl;
        goto tryAgain;
    }
#endif

#if defined  TASK_REGION_4
    if (tasks == 4)
    {
        cout << doubleTab << "Вычисление стоимости поездки на дачу и обратно (Задание №4)." << endl;
        cout << "Расстояние до дачи" << km << arrowPointer;
        cin >> roadDistance;
        cout << "Расход бензина (литров на 100 км пробега)" << arrowPointer;
        cin >> gasConsum;
        cout << "Цена литра бензина" << brCurrencyType << arrowPointer;
        cin >> gasCost;
        Task_4_calc();
        cout << totalCost;
        goto tryAgain;
    }
#endif
    return 0;
}