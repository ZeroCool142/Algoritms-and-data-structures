#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int integer, numerator, denominator;
} fraction;
/*
	Чет я уже не уверен что целую часть стоило отдельным полем делать,
	но время исправлять уже нет((
*/

int gcd(int a, int b);
void simplifyFraction(fraction f, fraction *res);
void addFraction(fraction f1, fraction f2, fraction *res);
void subFraction(fraction f1, fraction f2, fraction *res);
void divFraction(fraction f1, fraction f2, fraction *res);
void multFraction(fraction f1, fraction f2, fraction *res);
void toMixedFraction(fraction *f);
void printFraction(fraction *f);


int main(int argc, char const *argv[]) {
	
	fraction f1 = {1,1,6};
	fraction f2 = {0,1,4};
	fraction res = {0,0,0};


	addFraction(f1, f2, &res);
	toMixedFraction(&res);
	printFraction(&res);

	subFraction(f1, f2, &res);
	toMixedFraction(&res);
	printFraction(&res);

	multFraction(f1, f2, &res);
	toMixedFraction(&res);
	printFraction(&res);
	
	divFraction(f1, f2, &res);
	toMixedFraction(&res);
	printFraction(&res);

	return 0;
}


int gcd(int a, int b){
	if(a < 0) a *= -1;
	if(b < 0) b *= -1;
	int remainder;
        while (b != 0)
        {
            remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
}

void simplifyFraction(fraction f, fraction *res){
	if(f.denominator == 0){
		printf("Division by 0!\n");
		exit(1);
	}
	if(f.integer != 0){
		if(f.integer > 0){
			f.numerator += f.integer * f.denominator;
			f.integer = 0;
		}
		else {
			f.integer *= -1;
			f.numerator = (f.numerator + f.integer * f.denominator) * -1;
			f.integer = 0;
		}
		
	}

	int n = gcd(f.numerator, f.denominator);
	res->numerator = f.numerator / n;
	res->denominator = f.denominator / n;
	res->integer = 0;
}

void printFraction(fraction *f){
	if(f->denominator == 1){
		printf("%d\n", f->numerator + f->integer);
	}
	else if (f->numerator == 0 && f->integer != 0){
		printf("%d\n", f->integer);
	}
	else {
		if(f->integer == 0){
			printf("%d/%d\n", f->numerator, f->denominator);
		}
		else printf("%d %d/%d\n", f->integer, f->numerator, f->denominator);
	}
}

void addFraction(fraction f1, fraction f2, fraction *res){
	
	simplifyFraction(f1, &f1);
	simplifyFraction(f2, &f2);

	res->numerator = (f1.numerator * f2.denominator) + (f2.numerator * f1.denominator);
	res->denominator = f1.denominator * f2.denominator;
	res->integer = 0;
	simplifyFraction(*res,res);
}

void subFraction(fraction f1, fraction f2, fraction *res){
	
	simplifyFraction(f1,&f1);
	simplifyFraction(f2,&f2);

	res->numerator = (f1.numerator * f2.denominator) - (f2.numerator * f1.denominator);
	res->denominator = f1.denominator * f2.denominator;
	res->integer = 0;
	simplifyFraction(*res,res);
}

void multFraction(fraction f1, fraction f2, fraction *res){
	
	simplifyFraction(f1,&f1);
	simplifyFraction(f2,&f2);

	res->numerator = f1.numerator * f2.numerator;
	res->denominator = f1.denominator * f2.denominator;
	res->integer = 0;
	simplifyFraction(*res,res);
}

void divFraction(fraction f1, fraction f2, fraction *res){
	
	simplifyFraction(f1,&f1);
	simplifyFraction(f2,&f2);

	if(f2.numerator == 0){
		printf("Division by 0\n");
		exit(1);
	}
	res->numerator = f1.numerator * f2.denominator;
	res->denominator = f1.denominator * f2.numerator;
	res->integer = 0;
	simplifyFraction(*res,res);
}

void toMixedFraction(fraction *f){
	int q = f->numerator, r = f->denominator, i=f->integer,sign=1;
	if(q < 0) {
		q *= -1;
		sign = -1;
	}
	if(r < 0){
		r *= -1;
		sign = -1;
	}
	while(q >= r){
		q -= r;
		i++;
	}
	f->integer = i;
	f->numerator = q;
	f->denominator = r;
	if(f->integer!=0) f->integer *= sign;
	else f->numerator *= sign;
}
/* Output:
1 5/12
11/12
7/24
4 2/3
*/