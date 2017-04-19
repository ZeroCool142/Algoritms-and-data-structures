#include <stdio.h>
#include <stdlib.h>
#define N 8
#define M 8

/*
	1.	Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
	2.	Реализовать функцию возведения числа a в степень b:
		a.	без рекурсии;
		b.	рекурсивно;
	3.	Исполнитель Калькулятор преобразует целое число, записанное на экране. У исполнителя две команды, каждой команде присвоен номер:
		1. Прибавь 1
		2. Умножь на 2
	Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза. Сколько существует программ, которые число 3 преобразуют в число 20.
		а) с использованием массива;
		б) с использованием рекурсии.

	4.	*Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.
	5.	**Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по одному разу. 
		Здесь алгоритм решения такой же как и в задаче о 8 ферзях. Разница только в проверке положения коня.
*/


void toBin(int num);
int power(int base, int exponent);
int powerRecursive(int base, int exponent);
int res = 0;
void calc(int input, int limit);

int board[N][M] = {0};
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int maxMoves = N*M-1;
int iter = 0;

int isPosible(int x, int y);
void printBoard();
int knightMove(int curX, int curY, int move);

int main(void)
{	
	int a = 42;
	toBin(a);
	
	printf("\nLoop power: %d\n", power(a, 2));
	printf("Recurcive power: %d\n", powerRecursive(a, 2));
	
	res = 0;
	calc(3,20);
	printf("Number of programms: %d\n", res);

	printf("\nKnight tour:\n");
	if (knightMove(1,1,1)) printBoard();
	else printf("Impossibru!\n");

	return 0;
}

void toBin(int num){
	if (num >= 2) toBin(num / 2);
	printf("%d", num % 2);
}

int power(int base, int exponent){
	if(exponent == 0) return 1;
	for (int i = 0; i < exponent-1; ++i){
		base *= base;
	}
	return base;
}

int powerRecursive(int base, int exponent){
	if(exponent==0) return 1;
	if (exponent > 1){
		return base * powerRecursive(base, exponent-1);
	}
}

void calc(int input, int limit){
	if(input > limit) return;
	else if (input == limit){
		res++;
		return;
	}
	calc(input+1, limit);
	calc(input*2, limit);
}


//////KNIGHT/////////
int isPosible(int x, int y){
	return x>=0 && x<N && y>=0 && y<M && board[x][y]==0;
}
int chkBoard(){
	int count=0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if(isPosible(i, j)) count++;
		}
	}

	if (count>0) return 1;
	return 0;


}
void printBoard(){
	printf("\n");
	for (int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			printf("%4d ", board[i][j]);
		}
		printf("\n\n");
	}
}

//На некоторых начальных позициях нереально долго работает, наверно нужна какая-нибудь эвристика
int knightMove(int curX, int curY, int move){
	int nextX, nextY;
	
	printBoard();
	board[curX][curY] = move;
	if (!chkBoard(curX,curY)) {
		board[curX][curY] = 0;
		return 0;
	}
	if(move>maxMoves) return 1;

	for (int i = 0; i < 7; i++){
		nextX = curX + dx[i];
		nextY = curY + dy[i];
if (!chkBoard(curX,curY)) {
		board[curX][curY] = 0;
		return 0;
	}
		if(isPosible(nextX, nextY) && knightMove(nextX,nextY, move+1)) return 1;
	}

	board[curX][curY] = 0;
	return 0;
}
/* Output:
101010
Loop power: 1764
Recurcive power: 1764
Number of programms: 18
Knight tour:

   1   38   43   34    3   36   19   22 

  44   59    2   37   20   23    4   17 

  39   42   33   60   35   18   21   10 

  58   45   40   53   24   11   16    5 

  41   32   57   46   61   26    9   12 

  50   47   52   25   54   15    6   27 

  31   56   49   62   29    8   13   64 

  48   51   30   55   14   63   28    7 

[Finished in 3.2s]
*/




