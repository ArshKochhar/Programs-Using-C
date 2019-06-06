#include <stdio.h>

float power(float x, int n);
int factorial(int n);

int main(int argc, char **argv)
{
	float x = 0.785398; // 45% in rads
	int sign = 1;
	float sin = 0;
	int exponent;
	
	for (exponent = 1; exponent < 11; exponent +=2){
		sin += sign * power(x,exponent)/factorial(exponent);
		sign = sign * -1;
	}
	printf("sin(%f) = %f\n",x,sin);
	return 0;
}


float power(float x, int n){
	float num;
	int i;
	num = 1.0;		
	for (i=1; i<=n; i++)    // this loop will
   	   num *=x;		    // compute xn  
	return num;
}

int factorial(int n){
	int i;
	int fact = 1;	 	
	for(i=1;i<=n;i++)
		fact=fact*i;
	return fact;
}