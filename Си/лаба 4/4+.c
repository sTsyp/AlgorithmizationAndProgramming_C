#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

void cr(double** pArray, int* pK) 
{ 
    int i, K; 
    double* array; 
    printf("Введите K: "); 
    scanf("%d", &K); 

    array = (double*)malloc(sizeof(double) * K); 

    printf("Введите элементы массива:\n");
    for (i = 0; i < K; i++) 
    {
        printf("b[%d]=", i);
        scanf("%lf", &array[i]); 
    }
    
    *pArray = array; 
    *pK = K; 
}

double f1(double* array, int K, double Y) 
{
	double max1 = 0;
	for (int i = 0; i < K; i++) {
		if (fabs(array[i]) < Y) { //task 1
			if (array[i] > max1)
				max1 = array[i];
		}
	}
	return max1;
}

double f2(double* array, int K) 
{
	double max2 = 0;
	int n = 0;
	for (int i = 0; i < K; i++) {
		if (array[i] < 0) { //task 2
			if (max2 == 0) {
				max2 = array[i];
				n = i;
			}
			else if (array[i] >= max2) {
				max2 = array[i];
				n = i;
			}
		}
	}
	double s = 0;
	for (int i = (n + 1); i < K; i++) {
		s += array[i];
	}
	double rez;
	rez = (s / (K - n - 1) * 1.0);
	return max2;
}

int main() 
{
	int K;
    double *array;
    double X, Y;

	setlocale(LC_ALL, "rus"); 
    setlocale(LC_NUMERIC, "eng");

	cr(&array, &K);

	printf("Введите пороговые знчения:\n"); 
    printf("X = ");
    scanf("%lf", &X);
    printf("Y = ");
    scanf("%lf", &Y);


	double answer1 = f1(array, K, Y);
	printf("\nОтвет на задание №1: %lf\n", answer1);
	double answer2 = f2(array, K);
	printf("Ответ на задание №2: %lf", answer2);
	free(array);
	return 0;
}
