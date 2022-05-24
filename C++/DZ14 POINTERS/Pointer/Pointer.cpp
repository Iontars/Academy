﻿#include <iostream>
using namespace std;

#define POINTERS_BASICS

int main()
{
    setlocale(LC_ALL, "ru");


#ifdef POINTERS_BASICS
    int a = 2;
    int* pa = &a;
    int* pb;
    int b = 3;
    pb = &b;
    //pb - работаем с адресом
    //*pb - разыменовываем адрес и работаем со значением по адресу

    cout << a << endl;
    cout << &a << endl;
    cout << pa << endl;
    cout << *pa << endl;
    cout << pb << endl;
#endif // POINTERS_BASICS


    const int n = 5;
    int arr[n] = { 3,5,8,13,21 };
    cout << "Arr is " << arr << endl;
    cout << "Arr is " << *arr << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr + i << "  -  ";
        cout << *(arr + i) << "  ";
    }
    cout << endl;
}




/*
-------------------------------------------------------------------------------------
//часто вместо самой переменной бывает необходимо узнать адресс этой
//переменной в памяти и поработать с этим адресом
//для работы с адрессами в языке с++ существуют указатели.
//указатель (pointer) - переменная которая содержит адресс другой переменной.
//адрес - число длиной 4 байта означаюший порядковый номер байта в оперативной памяти,
//с точки зрения  процессора память представляет собой массив байтов.
//у каждого эллемена этого массива есть номер, этот номер и является адресом байта памяти.

//Адреса всегда записываются в 16ричнй системе счисления 0х00.
//Шестнадцатиричная система считсленя предназначена для компактной записи двоичных чисел.
//Один Шестнадцариричный разряд включает в себя 4 двоичных разряда. 0000
//Всьмиричная включает 3 двоичных. 000.
//
//0х показывает что число записано HEX
//Благодаря этому 1байт всегда можно представить двухразрдным HEX числом.
//
//HEX редактор
//
//Объявленеи указателей

 (амперсанд) & -   Adress of operator. оператор взятия адреса. Унарный оператор который возвращаяет адрес своего операнда,
 у оператора взятия адреа есть лишь префиксная форма записи.

 * - Dereference operator  Оператор разыменования. Унарный оператор который возвращает значение по адресу,
  только префиксная форма записи. Только при объявлени иуказателя звёздочка показывает что объявляемая
  переменная - указатель. в овсех остальных случаях звёздочка разыменовывает указатель и возвращает
  значение по адресу



                                Указатели и массивы
Имя массива является указателем на массив, поскольку содерит адрес кулевого элемента массива,
а следовательно и всего массива
                                Арифметика указателей
Над указателями можно выполнять урифметические операции
+
-
++
--
причём результат операции будет зависить от целовог отпа данных на который указываут указатель
Если к указателю на Char прибавить единиу то адресс изменится на 1 байт
                    Short - на 2 байта
                    Int -  байта
                    итд





------------------------------------------------------------------------------------
*/

