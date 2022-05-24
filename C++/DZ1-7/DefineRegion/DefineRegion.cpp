#include <iostream>
#include <typeinfo>
using namespace std;

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

enum Tasks
{
    TASK_1 = 1, TASK_2 = 2, TASK_3 = 3, TASK_4 = 4
};

int main()
{
    setlocale(LC_ALL, "ru");
    Tasks tasks;
    int numberOfTask;

tryAgain:
    cout << endl << doubleTab << "Введите номер домашнего задания для проверки, от 1 до 4" << arrowPointer;
    cin >> numberOfTask; cout << endl;
    switch (numberOfTask) {
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

#if defined  TASK_REGION_1
    if (tasks == 1)
    {
        double value, rub, penny;
        cout << doubleTab << "Преобразование числа в денежный формат (Задание №1)." << endl;
        cout << "Введите дробное число" << arrowPointer;
        cin >> value; cout << endl;
        rub = (int)value;
        penny = (value - rub) * 100;
        cout << value << currencyType << " - это " << rub << currencyType << penny << pennyType << endl;
        goto tryAgain;
    }
#endif TASK_REGION_1

#if defined  TASK_REGION_2
    if (tasks == 2)
    {
        int numbersOfCopybook, numbersOfPencil;
        double copybookPrice, pencilPrice, copybookTotalCost, pencilTotalCost, currentTotalCost;
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
        copybookTotalCost = numbersOfCopybook * copybookPrice;
        pencilTotalCost = numbersOfPencil * pencilPrice;
        currentTotalCost = copybookTotalCost + pencilTotalCost;
        cout << "Стоимость покупки: " << currentTotalCost << currencyType << endl;
        goto tryAgain;
    }
#endif TASK_REGION_2

#if defined  TASK_REGION_3
    if (tasks == 3)
    {
        double copybookPrice, copybookCoverPrice, currentCost;
        int numberOfBundles;
        cout << doubleTab << "Вычисление стоимости покупки (Задание №3)." << endl;
        cout << "Введите исходные данные: " << endl;
        cout << "Цена тертади" << brCurrencyType << arrowPointer;
        cin >> copybookPrice;
        cout << "Цена обложки" << brCurrencyType << arrowPointer;
        cin >> copybookCoverPrice;
        cout << "Колчество комплектов" << bundle << arrowPointer;
        cin >> numberOfBundles;
        currentCost = numberOfBundles * (copybookPrice + copybookCoverPrice);
        cout << "Стоимость покупки: " << currentCost << currencyType << endl;
        goto tryAgain;
    }
#endif TASK_REGION_3

#if defined  TASK_REGION_4
    if (tasks == 4)
    {
        double distance, gasConsum, gasCost, totalCost;
        cout << doubleTab << "Вычисление стоимости поездки на дачу и обратно (Задание №4)." << endl;
        cout << "Расстояние до дачи" << km << arrowPointer;
        cin >> distance;
        cout << "Расход бензина (литров на 100 км пробега)" << arrowPointer;
        cin >> gasConsum;
        cout << "Цена литра бензина" << brCurrencyType << arrowPointer;
        cin >> gasCost;
        totalCost = gasConsum / 100 * (distance * 2) * gasCost;
        cout << totalCost;
        goto tryAgain;


    }
#endif TASK_REGION_4


    return 0;
}
