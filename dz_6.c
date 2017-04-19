#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
1.	С клавиатуры вводится строка символов:
	a.	И вводится символ. Написать программу, которая подсчитывает, сколько раз символ входит в строку;
	b.	Написать программу, которая определяет, есть ли в строке гласные буквы;
	c.	Написать собственную функцию аналог strlen.
2.	*Для двух строк напишите функцию, определяющую, является ли одна строка перестановкой другой.
3.	**Реализовать функцию, осуществляющую сжатие строки, на основе счётчика повторяющихся символов. Например, строка aabcccccaaa должна превратиться в a2b1c5a3. 
	Если “сжатая” строка оказывается длиннее исходной, функция должна вернуть исходную строку.
4.	*Реализовать функцию void shift(char *str), которая будет циклически сдвигать строку.

*/

	//Полседние 2 не успел сделать((

int strLen(char * str);
int countChar(char * str, char c);
int checkVowels(char * str);
int reversStringCompare(char * str, char * str2);
void packStr(char * str, char * packedStr);
void shiftStr(char * str, char * shifted);

int main(void)
{	
	char *a1 = "Hello world!";
	char userInput = 'l';

	printf("Count of chars: %d\n", countChar(a1, userInput));

	if(checkVowels(a1)) printf("String contains a vowel\n");
	else printf("String not contains a vowel\n");


	char *reversed = "!dlrow olleH";

	if(reversStringCompare("123", "123")) printf("Is reversed string\n");
	else printf("It's not reversed string\n");

	return 0;
}

int strLen(char * str){
	int i = 0;
	while(*(str + i)!='\0') i++;
	return i;
}
int countChar(char * str, char c){
	int i = 0, count = 0;
	while(*(str + i)!='\0'){
		if(*(str + i)==c) count++;
		i++;
	}
	return count;
}
int checkVowels(char * str){
	int i = 0;

	while(*(str + i)!='\0'){
		switch (tolower(*(str + i))){
			case 'a' :
			case 'e' :
			case 'i' :
			case 'o' :
			case 'u' : 
				return 1;
		}
		i++;
	}
	return 0;
}
int reversStringCompare(char * str, char * str2){
	int str_l = strLen(str);
	int str_l2 = strLen(str2);
	if (str_l!=str_l2) return 0;

	int j = str_l2-1;
	int i = 0;
	for (i, j; i < str_l && j >= 0; i++, j--)
	{
		if (*(str + i) != *(str2 + j)) return 0;
	}
	return 1;
}

/* Output: 
Count of chars: 3
String contains a vowel
Is reversed string
[Finished in 0.3s]
*/