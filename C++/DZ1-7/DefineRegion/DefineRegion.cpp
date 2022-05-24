#include <iostream>
#include <typeinfo>
using namespace std;

#define currencyType " ���. "
#define brCurrencyType " (���.)"
#define pennyType " ���. "
#define bundle " (��.) "
#define km " ��. "
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
    cout << endl << doubleTab << "������� ����� ��������� ������� ��� ��������, �� 1 �� 4" << arrowPointer;
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
        cout << endl << doubleTab << "������� �� ���������� ��������, ���������� �����!" << endl;
        goto tryAgain; break;
    }

#if defined  TASK_REGION_1
    if (tasks == 1)
    {
        double value, rub, penny;
        cout << doubleTab << "�������������� ����� � �������� ������ (������� �1)." << endl;
        cout << "������� ������� �����" << arrowPointer;
        cin >> value; cout << endl;
        rub = (int)value;
        penny = (value - rub) * 100;
        cout << value << currencyType << " - ��� " << rub << currencyType << penny << pennyType << endl;
        goto tryAgain;
    }
#endif TASK_REGION_1

#if defined  TASK_REGION_2
    if (tasks == 2)
    {
        int numbersOfCopybook, numbersOfPencil;
        double copybookPrice, pencilPrice, copybookTotalCost, pencilTotalCost, currentTotalCost;
        cout << doubleTab << "���������� ��������� ������� (������� �2)." << endl;
        cout << "������� �������� ������: " << endl;
        cout << "���� �������" << brCurrencyType << arrowPointer;
        cin >> copybookPrice;
        cout << "��������� �������" << arrowPointer;
        cin >> numbersOfCopybook;
        cout << "���� ���������" << brCurrencyType << arrowPointer;
        cin >> pencilPrice;
        cout << "��������� ����������" << arrowPointer;
        cin >> numbersOfPencil;
        copybookTotalCost = numbersOfCopybook * copybookPrice;
        pencilTotalCost = numbersOfPencil * pencilPrice;
        currentTotalCost = copybookTotalCost + pencilTotalCost;
        cout << "��������� �������: " << currentTotalCost << currencyType << endl;
        goto tryAgain;
    }
#endif TASK_REGION_2

#if defined  TASK_REGION_3
    if (tasks == 3)
    {
        double copybookPrice, copybookCoverPrice, currentCost;
        int numberOfBundles;
        cout << doubleTab << "���������� ��������� ������� (������� �3)." << endl;
        cout << "������� �������� ������: " << endl;
        cout << "���� �������" << brCurrencyType << arrowPointer;
        cin >> copybookPrice;
        cout << "���� �������" << brCurrencyType << arrowPointer;
        cin >> copybookCoverPrice;
        cout << "��������� ����������" << bundle << arrowPointer;
        cin >> numberOfBundles;
        currentCost = numberOfBundles * (copybookPrice + copybookCoverPrice);
        cout << "��������� �������: " << currentCost << currencyType << endl;
        goto tryAgain;
    }
#endif TASK_REGION_3

#if defined  TASK_REGION_4
    if (tasks == 4)
    {
        double distance, gasConsum, gasCost, totalCost;
        cout << doubleTab << "���������� ��������� ������� �� ���� � ������� (������� �4)." << endl;
        cout << "���������� �� ����" << km << arrowPointer;
        cin >> distance;
        cout << "������ ������� (������ �� 100 �� �������)" << arrowPointer;
        cin >> gasConsum;
        cout << "���� ����� �������" << brCurrencyType << arrowPointer;
        cin >> gasCost;
        totalCost = gasConsum / 100 * (distance * 2) * gasCost;
        cout << totalCost;
        goto tryAgain;


    }
#endif TASK_REGION_4


    return 0;
}
