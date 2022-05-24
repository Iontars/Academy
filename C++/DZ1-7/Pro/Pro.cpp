#include <iostream>
#include <string>
using namespace std;

//����� �������
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

string numberOfTask;
//���������� ��� ������ �1
double value, rub, penny;
//���������� ��� ������ �2
int numbersOfCopybook, numbersOfPencil;
double copybookPrice, pencilPrice, copybookTotalCost, pencilTotalCost, currentTotalCost;
//���������� ��� ������ �3
int numberOfBundles;
double copybookPrice_2, copybookCoverPrice, currentCost;
//���������� ��� ������ �4
double roadDistance, gasConsum, gasCost, totalCost;
//������������ ��� ������ ������
enum Tasks
{
    TASK_1 = 1, TASK_2 = 2, TASK_3 = 3, TASK_4 = 4
};
Tasks tasks;
//������ ��� ������� �����
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
//����� �����
int main()
{
    cout << typeid(numberOfTask).name();
    setlocale(LC_ALL, "ru");
tryAgain: // ����� �������� �� ����� ������
    cout << endl << doubleTab << "������� ����� ��������� ������� ��� ��������, �� 1 �� 4" << arrowPointer;
    cin >> numberOfTask; cout << endl;
    //���������� ������ �� ������ ����� �� ���������� ������ (���������� ������ �� ����� ������ �������, ���� �� ����������� ���)
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
            cout << endl << doubleTab << "������� �� ���������� ��������, ���������� �����!" << endl;
            goto tryAgain; break;
        }
    }
    catch (...)
    {
        cout << endl << doubleTab << "������� �� ���������� ��������, ���������� �����!" << endl;
        goto tryAgain;
    }

#if defined  TASK_REGION_1
    if (tasks == 1)
    {
        cout << doubleTab << "�������������� ����� � �������� ������ (������� �1)." << endl;
        cout << "������� ������� �����" << arrowPointer;
        cin >> value; cout << endl;
        Task_1_calc();
        cout << value << currencyType << " - ��� " << rub << currencyType << penny << pennyType << endl;
        goto tryAgain;
    }
#endif

#if defined  TASK_REGION_2
    if (tasks == 2)
    {
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
        Task_2_calc();
        cout << "��������� �������: " << currentTotalCost << currencyType << endl;
        goto tryAgain;
    }
#endif

#if defined  TASK_REGION_3
    if (tasks == 3)
    {
        cout << doubleTab << "���������� ��������� ������� (������� �3)." << endl;
        cout << "������� �������� ������: " << endl;
        cout << "���� �������" << brCurrencyType << arrowPointer;
        cin >> copybookPrice_2;
        cout << "���� �������" << brCurrencyType << arrowPointer;
        cin >> copybookCoverPrice;
        cout << "��������� ����������" << bundle << arrowPointer;
        cin >> numberOfBundles;
        Task_3_calc();
        cout << "��������� �������: " << currentCost << currencyType << endl;
        goto tryAgain;
    }
#endif

#if defined  TASK_REGION_4
    if (tasks == 4)
    {
        cout << doubleTab << "���������� ��������� ������� �� ���� � ������� (������� �4)." << endl;
        cout << "���������� �� ����" << km << arrowPointer;
        cin >> roadDistance;
        cout << "������ ������� (������ �� 100 �� �������)" << arrowPointer;
        cin >> gasConsum;
        cout << "���� ����� �������" << brCurrencyType << arrowPointer;
        cin >> gasCost;
        Task_4_calc();
        cout << totalCost;
        goto tryAgain;
    }
#endif
    return 0;
}