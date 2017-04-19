#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//1.	Ввести a и b и вывести квадраты и кубы чисел от a до b.
//2.	Даны целые положительные числа N и K. Используя только операции сложения и вычитания, найти частное от деления нацело N на K, а также остаток от этого деления.
	void divide(int firstNumber, int secondNumber, int *quotient, int *nremainder){
		int temp = 0, i = firstNumber, j = secondNumber;
		if (i>j)
		{
			i = i ^ j;
			j = i ^ j;
			i = i ^ j;
		}
		for (i; j-i>=0; j-=i)
		{
			temp++;
			
		}
		*quotient = temp;
		*nremainder =  j;
	}
//3.	Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления определить, имеются ли в записи числа N нечетные цифры. 
//Если имеются, то вывести True, если нет — вывести False.
	int checkForOdd(int n){
		int res = 0;
		while((n != 0) && (res == 0)){
			if(n%2==0) n /= 10;
			else res = 1;
		}
		return res;
	}

//4.	С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое всех положительных четных чисел, оканчивающихся на 8.
	float average(){
		int temp = 0, count = 0;
		float res = 0;

		printf("Enter some numbers (0 for end):");
		do{
			scanf("%d", &temp);
			if((temp > 0) && (temp%10 == 8)) {
				res += temp;
				count++;
			}
		} while (temp != 0);
		return res/count;
	}
//5.	Написать функцию нахождения максимального из трех чисел.
	float maxNumber(float a, float b, float c){
		float max = a;
		if(b > max) max = b;
		if(c > max) return c;
		return max;
	}
//6.	* Написать функцию, генерирующую случайное число от 1 до 100.
//а) с использованием стандартной функции rand()
	int random(int min, int max){
		srand(time(NULL));
		int temp = 0;
		temp = (rand()%(max-min)) + min;
		return temp;
	}
//б) без использования стандартной функции rand()
	unsigned int myRandom(int a, int b, int c, unsigned int *seed){
		*seed = (a * *seed + c) % b;
		return *seed;
	}

//_______________________________________________


	int main(int argc, char const *argv[])
	{
		int qout = 0;
		int rem = 0;
		int firstNumber = 7, secondNumber = 21;
		
		/*Check firstNumber, secondNumber for positive and not 0 */
		
		divide(firstNumber,secondNumber, &qout, &rem);
		printf("Quotient = %d\nRemainder = %d\n", qout, rem);
		
		printf("%d \n", checkForOdd(146));

		float avgByEight = average();
		printf("%f \n", avgByEight);

		float a = 1.1f, b = 3.3f, c = 0.1f;
		printf("%f\n", maxNumber(a,b, c));
		
		
		printf("%d\n", random(1,100));


		unsigned int seed = time(NULL);
		for(int i=0; i < 3; i++){
			printf("%d\n", myRandom(99123, 4545, 999145, &seed));
		}
		
		return 0;
	}

