#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	const int hardArraySize = 10;
	int newArray[hardArraySize * 2];
	int hardArray[hardArraySize];
	int checkArray[hardArraySize];
	int i, j, minValue, maxValue, shiftValue;
	bool isMatch = true, noMatch = true;
	int number = 0;
	float sum = 0;

	//Заполнение массива
	cout << "\t" << "Заполнение массива" << endl;
	for (i = 0; i < hardArraySize; i++)
	{
		cout << "Введите " << i + 1 << " элемент массива: ";
		cin >> hardArray[i];
	}

	//Вывод всех элеменов массива
	cout << endl << "\t" << "Вывод всех элементов массива" << endl;
	for (i = 0; i < hardArraySize; i++)	cout << hardArray[i] << "\t";


	//Вывод всех элеменов массива (реверс)
	cout << endl << "\t" << "Вывод всех элементов массива (реверс)" << endl;
	for (i = hardArraySize - 1; i >= 0; i--) cout << hardArray[i] << "\t";


	//Вычисления
	cout << endl << endl << "\t" << "Вычисления" << endl;
	for (i = 0; i < hardArraySize; i++)
	{
		sum += hardArray[i];
		if (i == hardArraySize - 1)
		{
			cout << "Сумма элементов массива равна: " << sum << endl;
			cout << "Среднее арифметисеское массива: " << sum / hardArraySize << endl << endl;
		}
	}

	//Минимальное/максимальное значение массива
	cout << endl << "\t" << "Минимальное/максимальное значение массива" << endl;
	for (i = 0; i < hardArraySize; i++)
	{
		if (i == 0)
		{
			minValue = hardArray[i];
			maxValue = hardArray[i];
		}
		if (hardArray[i] < minValue) minValue = hardArray[i];
		if (hardArray[i] > maxValue) maxValue = hardArray[i];
		if (i == hardArraySize - 1) // последняя итерация
		{
			cout << "Минимальное значение: " << minValue << endl;
			cout << "Максимальное значение: " << maxValue << endl << endl;
		}
	}

	//Поиск повторяющихся значений
	cout << endl << "\t" << "Поиск повторяющихся значений" << endl;
	for (i = 0; i < hardArraySize; i++)
	{
		isMatch = true;
		for (int q = 0; q < hardArraySize; q++) // проверка на повторный поиск числа
		{
			if (hardArray[i] == checkArray[q])	isMatch = false;
		}
		for (j = 0; j < hardArraySize && isMatch; j++) // проверка текущего элемента массива на такие же значения
		{
			if (hardArray[i] == hardArray[j])
			{
				checkArray[i] = hardArray[i]; number++; // запоминание числа	
			}
		}
		if (number > 1) // вывод на экран числа если его количесиво повторений >= 2 
		{
			cout << "Число: " << checkArray[i] << " Повторяется: " << number - 1 << " раз " << endl;
			noMatch = false;
		}
		number = 0;
		if (noMatch && i == hardArraySize - 1) cout << "Повтрений нет" << endl;
	}

	//Сдвиг массива вправо
	cout << endl << "\t" << "Сдвиг массива вправо" << endl;
	cout << "На сколько позиций сдвинуть массив?: ";
	cin >> shiftValue;
	int tempCounter = 0, counter = 0;
	for (i = 0; i < hardArraySize; i++)
	{
		newArray[i + shiftValue] = hardArray[i];
		tempCounter = i + shiftValue;
		if (tempCounter >= hardArraySize)
		{
			newArray[counter] = hardArray[i]; counter++;
		}
	}
	for (i = 0; i < hardArraySize; i++)	cout << hardArray[i] << "\t";
	cout << endl;
	for (i = 0; i < hardArraySize; i++) cout << newArray[i] << "\t";
	cout << endl;
}
