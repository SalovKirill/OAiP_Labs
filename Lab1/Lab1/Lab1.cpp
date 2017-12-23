/*
Салов Кирилл Андреевич
Лабораторная работа №1
Вариант №8
Задание : Перевести километры в ярды и выразить в дюймах
*/

#include <stdio.h>
#include "conio.h"
#include <stdlib.h>
#define YARDS_IN_KMS 1093.6133
#define INCHES_IN_YARDS 36

void check(int result)
{
	if (result == 0)
	{
		printf("Error message");
		_getch();
		exit(1);
	}
}

int main()
{
	printf("Enter length in kilometres\n");
	float kms;
	check(scanf_s("%f", &kms));
	float yards = kms * YARDS_IN_KMS;
	printf("Length in yards is %1.2f\n", yards);
	float inches = yards * INCHES_IN_YARDS;
	printf("Length in inches is %1.2f\n", inches);
	_getch();
	return 0;
}