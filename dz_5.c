#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>
#define LEN 20000
/*
1. Попробовать оптимизировать пузырьковую сортировку. Описать в комментариях к программе что дают эти улучшения. 
	Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
2. Реализовать шейкерную сортировку.
3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. 
	Функция возвращает индекс найденного элемента или -1, если элемент не найден.
4. Подсчитать количество операций для каждой из сортировок. 
	Реализовать меню с выбором способа заполнения массива: из файла, случайными числами, с клавиатуры.
*/


void initArray(int *arr, int size);
void arrcpy(int *arr, int *arr2, int size);
void swap(int *a, int *b);
int getDeltaTime(struct timeb *s, struct timeb *e);
int bubbleSort(int *arr, int size);
int ububbleSort(int *arr, int size);
int cocktailSort(int *arr, int size);
int binSearch(int *arr, int size, int searchNum);



int main(void)
{	
	struct timeb start, end;
	int arr[LEN];
	int arr2[LEN];

	initArray(arr, LEN);
	arrcpy(arr, arr2, LEN);

	ftime(&start);
	long int bSortOperations = bubbleSort(arr, LEN);
	ftime(&end);
	printf("Bubble running time: %dms\n", getDeltaTime(&start, &end));

	ftime(&start);
	long int ubSortOperations = ububbleSort(arr2, LEN);
	ftime(&end);
	printf("uBubble running time: %dms\n", getDeltaTime(&start, &end));

	ftime(&start);
	long int cSortOperations = cocktailSort(arr2, LEN);
	ftime(&end);
	printf("Cocktail running time: %dms\n", getDeltaTime(&start, &end));
/*
	printf("bubble:\n");
	for (int i = 0; i < LEN; ++i)
	{
		printf("%d ", arr[i]);
	}

	printf("\ncocktail:\n");
	for (int i = 0; i < LEN; ++i)
	{
		printf("%d ", arr[i]);
	}
*/
	printf("\nNumber of operations (bubble): %ld\nNumber of operations (cocktail): %ld\n", bSortOperations, ubSortOperations);

	ftime(&start);
	int index = binSearch(arr, LEN, 42);
	ftime(&end);
	printf("Searching time: %dms\n", getDeltaTime(&start, &end));
	if (index>=0)
	{
		printf("Index of the search number: %d\n", index);
	} else {
		printf("Number not found!\n");
	}
}

void initArray(int *arr, int size){
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
	{
		arr[i] = rand()%100;
	}
}

void arrcpy(int *arr, int *arr2, int size){
	for (int i = 0; i < size; ++i)
	{
		arr2[i] = arr[i];
	}
}
void swap(int *a, int *b){
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
int getDeltaTime(struct timeb *s, struct timeb *e){
	return (int) (1000.0 * (e->time - s->time) + (e->millitm - s->millitm));
}
int bubbleSort(int *arr, int size){
	int operations = 0;
	int lastSwap = size - 1, current = 0;

	for(int i = 1; i < size; i++){
		for (int j = 0; j < lastSwap; j++)
		{
			if(arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
				current = j;
				operations++;
			}
		}
		lastSwap = current;
	}
	return operations;
}
int ububbleSort(int *arr, int size){
	int operations = 0;

	for(int i = 1; i < size; i++){
		for (int j = 0; j < size; j++)
		{
			if(arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
				operations++;
			}
		}
		
	}
	return operations;
}

int cocktailSort(int *arr, int size){
	int left = 0, right = size-1, operations =0;

	while(left<=right){
		for (int i = left; i < right; i++)
		{
			if(arr[i] > arr[i+1]){
				swap(&arr[i], &arr[i+1]);
			}
			operations++;
		}
		right--;

		for (int i = right; i > left; i--)
		{
			if(arr[i-1] > arr[i]){
				swap(&arr[i], &arr[i-1]);
			}
			operations++;
		}
		left++;

	}
	return operations;
}

int binSearch(int *arr, int size, int searchNum){
	int last = size, first = 0, mid;
	int op = 0;

	if(size == 0 || arr[0] > searchNum || arr[size-1] < searchNum){
		return -1;
	}

	while (first < last){
		mid = (last+first)/2;

		if (arr[mid] >= searchNum)
		{
			last = mid;
		}
		else first = mid + 1;
		op++;
	}

	if (arr[last] == searchNum)
	{
		printf("Search operations: %d\n", op);
		return last;
	} 
	return -1;
}
/* Output: 
Bubble running time: 391ms
Cocktail running time: 340ms

Number of operations (bubble): 49958086
Number of operations (cocktail): 49995000
Search operations: 14
Searching time: 0ms
Index of the search number: 4172
[Finished in 1.1s]
*/