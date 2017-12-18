/*
Салов Кирилл Андреевич
Лабораторная работа №2
Вариант №2
Задание: Написать программу, которая вычисляет среднее арифметическое элементов массива
без учета минимального и максимального элементов массива. 
Массив и его длина вводятся пользователем.
*/

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>

int main()
{
	printf("Enter length of array\n");
	int ArrayLength;
	int result = scanf_s("%d", &ArrayLength);
	if (result == 0)
	{
		printf("Error message\n");
		_getch();
		return 0;
	}
		printf("Enter Array\n");
		int Array[1000];
		int maximum = 0;
		int minimum = 1000000;
		int sum = 0;
		int numberOfMin = 0;
		int numberOfMax = 0;
		for (int i = 0; i < ArrayLength; i++)
	{
		int result = scanf_s("%d", &Array[i]);
		if (result == 0)
		{
			printf("Error message\n");
			_getch();
			return 0;
		}
		sum += Array[i];
		if (Array[i] < minimum)
		{
			minimum = Array[i];
			numberOfMin = 1;
		}
		else if (Array[i] == minimum)
			numberOfMin++;
		if (Array[i] > maximum)
		{
			maximum = Array[i];
			numberOfMax = 1;
		}
		else if (Array[i] == maximum)
			numberOfMax++;
	}
	sum -= maximum * numberOfMax + minimum * numberOfMin;
	if (sum < 0)
		printf("0");
	else
	{
		float average = sum * 1.0 / (ArrayLength - numberOfMax - numberOfMin);
		printf("%1.4f\n", average);
	}
	_getch();
	return 0;
}
