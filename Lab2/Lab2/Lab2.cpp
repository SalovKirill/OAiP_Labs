/*
Салов Кирилл Андреевич
Лабораторная работа №2
Вариант №2
Задание: Написать программу, которая вычисляет среднее арифметическое элементов массива
без учета минимального и максимального элементов массива.
Массив и его длина вводятся пользователем.
*/

#include <stdio.h>
#include <conio.h>
#include <iostream>
#define ARRAY 1000

void check(int result)
{
	if (result == 0)
	{
		printf("Error message\n");
		_getch();
		exit(1);
	}
}


void minimum_counting(int* num, int i, int* minimum, int* numberOfMin)
{
	if (num[i] < *minimum)
	{
		*minimum = num[i];
		*numberOfMin = 1;
	}
	else if (num[i] == *minimum)
		(*numberOfMin++);
}

void maximum_counting(int* num, int i, int* maximum, int* numberOfMax)
{
	if (num[i]> *maximum)
	{
		*maximum = num[i];
		*numberOfMax = 1;
	}
	else if (num[i] == *maximum)
		(*numberOfMax++);
}

void print_sum(int numberOfMax, int numberOfMin, int sum, int ArrayLength)
{
	if (sum < 0)
		printf("0");
	else
	{
		float average = sum * 1.0 / (ArrayLength - numberOfMax - numberOfMin);
		printf("%1.4f\n", average);
	}
}

int main()
{
	printf("Enter length of array\n");
	int ArrayLength;
	int num[ARRAY];
	int minimum = 1000000;
	int maximum = 0;
	check(scanf_s("%d", &ArrayLength));
	printf("Enter Array\n");
	int sum = 0;
	int numberOfMin = 0;
	int numberOfMax = 0;
	for (int i = 0; i < ArrayLength; i++)
	{
		check(scanf_s("%d", &num[i]));
		sum += num[i];
		minimum_counting(num, i, &minimum, &numberOfMin);
		maximum_counting(num, i, &maximum, & numberOfMax);
	}
	sum -= maximum * numberOfMax + minimum * numberOfMin;
	print_sum(numberOfMax, numberOfMin, sum, ArrayLength);
	_getch();
	return 0;
}