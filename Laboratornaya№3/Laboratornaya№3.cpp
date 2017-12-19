/*
Салов Кирилл Андреевич
Лабораторная работа №3
Вариант №2 
Задание: Написать программу, которая во вводимом с клавиатуры тексте выберет слова,
начинающиеся с гласной буквы, и выведет их на экран.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

const char VOWEL[] = { 'A', 'a', 'E', 'e', 'O', 'o', 'U', 'u', 'I', 'i', 'Y', 'y', '\0' };

int NumOfWords = 0;

bool isVowel(char c)
{
	int i = 0;
	while (VOWEL[i])
	{
		if (c == VOWEL[i])
		{
			return 1;
		}
		i++;
	}
	return 0;
}

char** chooseWords(char** words, int* num_of_words_vowel)
{
	char** temp_words = NULL;
	for (int i = 0; i < NumOfWords; i++)
	{
		if (isVowel(words[i][0]))
		{
			temp_words = (char**)realloc(temp_words, (*num_of_words_vowel + 1) * sizeof(char*));
			temp_words[*num_of_words_vowel] = (char*)calloc(strlen(words[i]), strlen(words[i]) * sizeof(char));
			strcpy(temp_words[*num_of_words_vowel], words[i]);
			(*num_of_words_vowel)++;
		}
	}
	return temp_words;
}

char** readWords()
{
	int word_length = 0;
	char **words = (char**)calloc(1, sizeof(char*));
	words[NumOfWords] = (char*)calloc(1, sizeof(char));
	char c;
	while (c = getchar())
	{
		if (c == -1)
		{
			break;
		}
		if (isspace(c))
		{
			if (word_length == 0)
			{
				continue;
			}
			words[NumOfWords] = (char*)realloc(words[NumOfWords], (word_length + 1) * sizeof(char));
			words[NumOfWords][word_length] = '\0';
			word_length = 0;
			NumOfWords++;
			words = (char**)realloc(words, (NumOfWords + 1) * sizeof(char*));
			words[NumOfWords] = (char*)calloc(1, sizeof(char));
		}
		else
		{
			words[NumOfWords] = (char*)realloc(words[NumOfWords], (word_length + 1) * sizeof(char));
			words[NumOfWords][word_length] = c;
			word_length++;
		}
	}
	return words;
}

void writeWords(char** words, int num_of_words)
{
	for (int i = 0; i < num_of_words; i++)
	{
		printf("%s\n", words[i]);
	}
}

int main()
{
	char **words = readWords();
	int num_of_words_vowel = 0;
	char** words_vowel = chooseWords(words, &num_of_words_vowel);
	writeWords(words_vowel, num_of_words_vowel);
	return 0;
}
