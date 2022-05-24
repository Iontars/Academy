#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int inputValue, processValue;
    string currentValue;
    string finalValue;

    cout << "������ �����: ";
    cin >> inputValue;

    // �������� ������� 
    currentValue = "";
    finalValue = "";
    processValue = inputValue;
    while (processValue)
    {
        currentValue += to_string(processValue % 2);
        processValue = processValue / 2;
    }
    //for (int i = currentValue.size(); i >= 0; i--) // ������ ������
    //{
    //    finalValue += currentValue[i];
    //}
    std::reverse(currentValue.begin(), currentValue.end());
    cout << inputValue << " � �������� ������� ���������: " << finalValue;
    cout << currentValue << endl;

    // ������������ ������� 
    currentValue = "";
    finalValue = "";
    processValue = inputValue;
    while (processValue)
    {
        currentValue += to_string(processValue % 8);
        processValue = processValue / 8;
    }
    for (int i = currentValue.size(); i >= 0; i--) // ������ ������
    {
        finalValue += currentValue[i];
    }
    cout << inputValue << " � ������������ ������� ���������: " << finalValue << endl;

    // ����������������� ������� 
    currentValue = "";
    processValue = inputValue;
    string values[16] = { "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };
    do
    {
        currentValue.insert(0, values[processValue % 16]);
        processValue /= 16;
    } while (processValue != 0);
    finalValue = currentValue;
    cout << inputValue << " � ����������������� ������� ���������: " << finalValue << endl;
}
