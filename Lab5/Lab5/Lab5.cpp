/*
Салов Кирилл Андреевич
Лабораторная работа №5
Вариант №2
(«Покупатель»:имя, фамилия, город, улица, номер дома,
номер квартиры, номер кредитной карточки, код покупки.)
Задание: написать программу, которая записывает с клавиатуры
в файл структуру, согласно выданному варианту задания.
*/

#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h> 
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH_FIO 20
#define MAX_LENGTH_CITY 30
#define MAX_LENGTH_STREET 30
#define MAX_LENGTH_PURCHASES 20

int buyer = 0;


typedef struct
{
	char Name[MAX_LENGTH_FIO];
	char Surname[MAX_LENGTH_FIO];
} Buyer;


typedef struct
{
	char city[MAX_LENGTH_CITY];
	char street[MAX_LENGTH_STREET];
	Buyer Buyer;
	int home = 0;
	int flat = 0;
	int card = 0;
	int code = 0;

} Purchase;

 Purchase num[MAX_LENGTH_PURCHASES];

FILE* f_Buyers = fopen("f_out.txt", "w");



void Choice()
{
	printf("Доступные операции: \n");
	printf(" 1-Добавить покупателя \n");
	printf(" 2-Поиск покупателя\n");
	printf(" 3-Посмотреть весь список\n");
	printf(" 4-Завершить\n");

}

int CheckNumber()
{
	int number = 0;
	do
	{
		int result = scanf_s("%d", &number);
		if (result == 0) {
			printf("Неверный ввод");
			_getch();
			exit(1);
		}
		if (number < 1 || number > 5)
			printf("Неверная команда\n");
	} while (number < 1 || number > 5);
	return number;
}
void addbuyer()
{
	printf("Введите имя покупателя\n");
	scanf("%s", num[buyer].Buyer.Name);
	printf("Введите фамилию покупателя\n");
	scanf("%s", num[buyer].Buyer.Surname);
	printf("Введите город покупателя \n");
	scanf("%s", &num[buyer].city);
	printf("Введите название улицы покупателя \n");
	scanf("%s", &num[buyer].street);
	printf("Введите номер дома покупателя \n");
	scanf("%d", &num[buyer].home);
	printf("Введите номер квартиры покупателя \n");
	scanf("%d", &num[buyer].flat);
	printf("Введите номер кредитной карты покупателя\n");
	scanf("%d", &num[buyer].card);
	printf("Введите код покупки\n");
	scanf("%d", &num[buyer].code);
	buyer++;

}
void writebuyer(int i)
{
	fprintf(f_Buyers, "%-30s|%-20s|%-20s|%-30s", num[i].Buyer.Name,num[i].Buyer.Surname, num[i].city, num[i].street);
	fprintf(f_Buyers, "%10d|%10d|%10d|%16d\n", num[i].home, num[i].flat, num[i].code, num[i].card);
}
void searchbuyer()

{
	int x;
	char c[MAX_LENGTH_PURCHASES];
	printf("По какому параментру вы хотите найти покупателя?\n");
	printf("1-Имя\n 2-Фамилия\n 3-Город\n 4-Номер покупки\n");
	scanf("%d", &x);
	scanf("%s", c);
	for (int i = 0; i < buyer; i++)
	{
		switch (x)
		{
		case 1:
		{
			if (!strcmp(num[i].Buyer.Name, c))
			{
				writebuyer(i);
			}
		} break;
		case 2:
		{
			if (!strcmp(num[i].Buyer.Surname, c))
			{
				writebuyer(i);
			}
		} break;
		case 3:
		{
			if (!strcmp(num[i].city, c))
			{
				writebuyer(i);
			}
			break;
		}
		case 4:
		{
			char str[12];
			sprintf(str, "%d", num[i].code);
			if (!strcmp(str, c))
			{
				writebuyer(i);
			}
		}
		}

	}
}


void writebuyer()
{
	fprintf(f_Buyers, "%-30s|%-20s|%-20s|%-30s", "Buyer Name", "Buyer Sunrame", "Buyer's city", "Buyer's street");
	fprintf(f_Buyers, "%10s|%10s|%10s|%16s \n", "Home", "Flat", "Code", "Card");
	for (int i = 0; i < buyer; i++)
	{
		writebuyer(i);
	}
}
int main()
{
	int num;
	system("chcp 1251");
	system("cls");
	do
	{
		Choice();
		num = CheckNumber();
		switch (num)
		{
		case 1: {
			addbuyer();
			printf("Покупатель добавлен\n\n");
		}
				break;
		case 2: {
			searchbuyer();
			printf("Поиск завершен\n\n");
		}
				break;
		case 3: {
			writebuyer();
			printf("Список покупателй выведен в файл\n\n");
		}
				break;
		case 4: printf("До свидания");
			break;
		}
	} while (num != 4);
	_getch();
	return 0;
}