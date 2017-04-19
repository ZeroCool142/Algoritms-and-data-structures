#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
 


/**Написать функции 1а и 1d - с использованием арифметики указателей.
	1.	Создать массив из 100 элементов. Написать программу, которая содержит функции для
	a.	заполнения массива случайными числами;
	b.	подсчета среднего арифметическое элементов;
	c.	нахождения номера элемента, который максимально отличается от среднего арифметического;
	d.	находит максимальное абсолютное число в массиве;
	e.	*считывает массив из файла. Массив в файле не может быть больше 100 эл-тов
	2.	*Выполнить пункты a, b, c, d первого задания для двухмерного массива
	*/

void initArr(int *arr);
float avg(int *arr);
int maxDif(int *arr);
int maxNum(int *arr);

void initArr2d(int *arr);
float avg2d(int *arr);
void maxDif2d(int *arr, int *indexI, int *indexJ);
int maxNum2d(int *arr);

int lengthMass(char *path);
void readFile(char *path, int *arr, int length);


int main(void)
{	
	int *arr = malloc(sizeof(int)*MAX);
	initArr(arr);
	float ae = avg(arr);
	printf("Avaerage: %f\n", ae);
	int m = maxDif(arr);
	printf("Index of maximum different: %d\n", m);
	int num = maxNum(arr);
	printf("Absolute maximum: %d\n", num);

	int ii = 0, ij = 0;
	int *arr2d = malloc(sizeof(int)*MAX*MAX);
	initArr2d(arr2d);
	ae = avg2d(arr2d);
	printf("Avaerage(2 dim): %f\n", ae);
	maxDif2d(arr2d, &ii, &ij);
	printf("Index of maximum different(2 dim): %d : %d\n", ii, ij);
	num = maxNum2d(arr2d);
	printf("Absolute maximum(2 dim): %d\n", num);

	char *p = "1.txt";
	int length = lengthMass(p);
	int arrF[length];

	readFile(p, arrF, length);
	printf("Array from file:\n");
	for (int i = 0; i < length; ++i)
	{
		printf("%d\n", arrF[i]);
	}


	free(arrF);
	free(arr);
	free(arr2d);

	return 0;

}

void initArr(int *arr){
	srand(time(NULL));
	for(int i = 0; i < MAX; i++){
		*(arr + i) = rand();
	}
}
void initArr2d(int *arr){
	srand(time(NULL));
	for(int i = 0; i < MAX; i++){
		for (int j = 0; j < MAX; j++)
		{
			*(arr + i*MAX + j) = rand();
		}
	}
}
float avg(int *arr){
	float sum = 0;
	for(int i = 0; i < MAX; i++){
		sum += *(arr + i);
	}
	return sum/MAX;
}
float avg2d(int *arr){
	float sum = 0;
	for(int i = 0; i < MAX; i++){
		for (int j = 0; j < MAX; j++)
		{
			sum += *(arr + i*MAX + j);
		}
	}
	return sum/(MAX*MAX);
}

int maxDif(int *arr){
	float average = avg(arr);
	float temp = 0, value = (*(arr) < average) ? abs(average-*(arr)) : abs(*(arr)-average);
	int index = 0;
	for (int i = 0; i < MAX; i++)
	{
		temp = (*(arr + i) < average) ? abs(average-*(arr + i)) : abs(*(arr + i)-average);
		if(temp > value) {
			index = i;
			value = temp;
		} 
	}
	return index;
}
void maxDif2d(int *arr, int *indexI, int *indexJ){
	float average = avg(arr);
	float temp = 0, value = (*(arr)<average) ? abs(average-*(arr)) : abs(*(arr)-average);
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		 {
		 	temp = (*(arr + i*MAX + j)<average) ? abs(average-*(arr + i*MAX + j)) : abs(*(arr + i*MAX + j)-average);
			if(temp > value) {
				*indexI = i;
				*indexJ = j;
				value = temp;
			}
		 } 
	}
}

int maxNum(int *arr){
	int max = abs(*arr);
	int temp = 0;
	for (int i = 0; i < MAX; i++)
	{
		temp = abs(*(arr+i));
		if(temp > max) max = temp;
	}
	return max;
}

int maxNum2d(int *arr){
	int max = abs(*arr);
	int temp;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			temp = abs(*(arr+i*MAX+j));
			if(temp > max) max = temp;
		}
	}
	return max;
}

void readFile(char *path, int *arr, int length){
	FILE *f;
	f = fopen(path, "r");
	for (int i = 0; i < length; i++)
	{
		fscanf(f, "%d", &arr[i]);
	}

	fclose(f);
}

int lengthMass(char *path){
	FILE *f;
	int t, count = 0;
	f = fopen(path, "r");
	while(fscanf(f, "%d", &t)!= EOF){
		count++;
	}

	fclose(f);
	return count;
}