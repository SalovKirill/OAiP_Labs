/*
����� ������ ���������
������������ ������ �2
������� �2
�������: �������� ���������, ������� ��������� ������� �������������� ��������� �������
��� ����� ������������ � ������������� ��������� �������.
������ � ��� ����� �������� �������������.
*/

#include <stdio.h>
#include <conio.h>
#include <iostream>
#define ARRAY 1000
#define MAXIMUM 0
#define MINIMUM 1000000
#define	SUM 0
#define	NUMBER_OF_MIN 0
#define NUMBER_OF_MAX 0


/*
1 ������� ������� ��� ���������� ������
2 ������� ������� ��� ���������� ������������ ��������
3 ������� ������� ��� ���������� ������������� ��������
4 ������� ������� �������� �����
5 ������� ������� ��� ������
*/
int main()
{
	printf("Enter length of ARRAY\n");
	int ArrayLength;
	int result = scanf_s("%d", &ArrayLength);
	if (result == 0)
	{
		printf("Error messagen");
		_getch();
		return 0;
	}
	printf("Enter ARRAY\n");
	int Array;
	int result = scanf_s("%d", &Array)
	for (int i = 0; i < ArrayLength; i++);
	{
		int result = scanf_s("%d", &[i]);
		if (result == 0)
		{
			printf("Error message\n");
			_getch();
			return 0;
		}
		SUM += ARRAY[i];
		if (ARRAY[i] < MINIMUM)
		{
			MINIMUM = ARRAY[i];
			NUMBER_OF_MIN = 1;
		}
		else if (ARRAY[i] == MINIMUM)
			NUMBER_OF_MIN++;
		if (ARRAY[i] > MAXIMUM)
		{
			MAXIMUM = ARRAY[i];
			NUMBER_OF_MAX = 1;
		}
		else if (ARRAY[i] == MAXIMUM)
			NUMBER_OF_MAX++;
	}
	SUM -= MAXIMUM * NUMBER_OF_MAX + MINIMUM * NUMBER_OF_MIN;
	if (SUM < 0)
		printf("0");
	else
	{
		float average = SUM * 1.0 / (ArrayLength - NUMBER_OF_MAX - NUMBER_OF_MIN);
		printf("%1.4f\n", average);
	}
	_getch();
	return 0;
}