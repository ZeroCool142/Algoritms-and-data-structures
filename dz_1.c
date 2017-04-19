#include <stdio.h>
#include <math.h>
 
void main(void)
{
	int buff;

	//fflush(stdin) ток на винде работает
	//кроссплатформенное решение:
	//int buff;
	//while((buff = getchar()) != '\n');


	//1.	Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); 
	// 		где m-масса тела в килограммах, h - рост в метрах.
	{
		float I, h, m;
		printf("Input height(m.): ");
		scanf("%f", &h);
		while((buff = getchar()) != '\n');
		printf("\nInput mass(kg.): ");
		scanf("%f", &m);
		while((buff = getchar()) != '\n');
		I = m/(h*h);
		printf("\nBody mass index = %.2f\n", I);
	}

	//2.	Написать программу обмена значениями двух переменных:
	//	a.	с использованием третьей переменной;
	{
		int a = 5, b = 2, temp;
		printf("a: %d -- b: %d\n", a, b);
		temp = a;
		a = b;
		b = temp;
		printf("a: %d -- b: %d\n", a, b);
	}

	//	b.	 *без использования третьей переменной.
	{
		int a = 101, b = 42;
		printf("a: %d -- b: %d\n", a, b);
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
		printf("a: %d -- b: %d\n", a, b);
	}


	//3.	Написать программу нахождения всех корней заданного квадратного уравнения.
	{
		float a,b,c,d,x;
		printf("\nSolving the quadratic equation a*x^2 + b*x + c = 0");
		do {
			printf("\nInput a != 0: ");
			scanf("%f", &a);
			while((buff = getchar()) != '\n');
		} while(a == 0);
		printf("\nInput b: ");
		scanf("%f", &b);
		while((buff = getchar()) != '\n');
		printf("\nInput c: ");
		scanf("%f", &c);
		while((buff = getchar()) != '\n');
		d=(b*b)-(4*a*c);
		if(d>0){
			printf("\nDiscriminant = %f > 0, equation have two real roots\n", d);
			x = (-b+sqrt( (b*b)-(4*a*c) ))/(2*a);
			printf("x1 = %f\n", x);
			x = (-b-sqrt( (b*b)-(4*a*c) ))/(2*a);
			printf("x2 = %f\n", x);

		}
		else if(d == 0){
			printf("\nDiscriminant = %f, equation have one real root\n", d);
			x = -(b/(2*a));
			printf("x1 = x2 = %f\n", x);
		}
		else printf("\nDiscriminant = %f < 0, equation have no real roots\n", d);

	}


	//4.	Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».

	{
		int age,temp;
		do {
			printf("Введите возраст: \n");
			scanf("%d", &age);
			while((buff = getchar()) != '\n');
		} while(!(age>=1 && age<=150));
		
		temp=age%100;
		if(temp/10>=1 && temp/10<2) printf("%d лет\n", age);
		else if(temp%10 == 1) printf("%d год\n", age);
		else if(temp%10>1 && temp%10<5) printf("%d года\n", age);
		else printf("%d лет\n", age);
	}
	//5.	*С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2). 
	//		Требуется определить, относятся ли к поля к одному цвету или нет.
	{
		int x1,x2,y1,y2;
		printf("Check two chess(8x8) field color:\n");
		do {
			printf("Input first field x1 y1: \n");
			scanf("%d %d", &x1, &y1);
			while((buff = getchar()) != '\n');
		} while(!(x1>=1 && x1<=8) && !(y1>=1 && y1<=8));
		do {
			printf("Input second field x2 y2: \n");
			scanf("%d %d", &x2, &y2);
			while((buff = getchar()) != '\n');
		} while(!(x2>=1 && x2<=8) && !(y2>=1 && y2<=8));


		if((x1+y1)%2 == (x2+y2)%2) printf("Fields have same color!\n");
		else printf("Fields have different colors\n");
	}


	printf("Press any key to exit...\n");
	getchar();
}