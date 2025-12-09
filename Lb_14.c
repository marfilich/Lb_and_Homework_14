#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

double func(double x);
double* full_elements(double* ptr_array, int size);
int put_elements(double* ptr_array, int size);
double* calc_elements(double* ptr_array, int size);
double sum_elements(double* ptr_array, int begin, int end);
int find_element(double* ptr_array, int size, double element);
double funtion_homework_lb11(double* ptr_array, int);

double funtion(double* ptr_array, int k);



int main()
{
	setlocale(LC_ALL, "RUS");
	int begin, end, k;
	double a;
	int size;

	puts("Введите размер массива:");
	scanf("%d", &size);
	puts("Введите начальный индекс:");
	scanf("%d", &begin);
	puts("Введите конечный индекс:");
	scanf("%d", &end);
	puts("Введите значение элемента");
	scanf("%lf", &a);
	puts("Введите позицию элемента для поиска максимального");
	scanf("%d", &k);

	double* ptr_array;
	ptr_array = (double*)malloc(size * sizeof(double));
	if (ptr_array == NULL) 
	{
		puts("error");
		return -1;
	}
	full_elements(ptr_array, size);
	put_elements(ptr_array, size);
	puts("Элементы массива возведены в квадрат");
	put_elements(calc_elements(ptr_array, size), size);
	printf("Сумма чисел от %d до %d равна %.4lf\n", begin, end, sum_elements(ptr_array, begin, end));
	printf("Индекс элемента %d\n", find_element(ptr_array, size, a));
	funtion_homework_lb11(ptr_array, size);
	printf("Максимальное значение до числа на позиции %d равно %.4lf\n", k, funtion(ptr_array, k));
	

	free(ptr_array);
	return 0;
}

double* full_elements(double* ptr_array, int size)
{
	double x = 2;
	for (int i = 0; i < size; i++)
	{
		ptr_array[i] = func(x);
		x += 0.2;
	}
	ptr_array[size - 2] = 50;
	ptr_array[size - 5] = 2;
	return ptr_array;
}

int put_elements(double* ptr_array, int size) 
{
	for (int i = 0; i < size; i++)
	{
		printf("ptr_array[%d] = %lf\n", i, ptr_array[i]);
	}
}

double* calc_elements(double* ptr_array, int size)
{
	double* ptr_array_new;
	ptr_array_new = (double*)malloc(size * sizeof(double));
	if (ptr_array_new == NULL)
	{
		puts("error");
		return -1;
	}
	for (int j = 0; j < size; j++)
	{
		double num;
		num = ptr_array[j] * ptr_array[j];
		ptr_array_new[j] = num;
	}
	return ptr_array_new;
}

double sum_elements(double* ptr_array, int begin, int end)
{
	double sum = 0;
	for (int i = begin - 1; i <= end - 1; i++)
	{
		sum += ptr_array[i];
	}
	return sum;
}

int find_element(double* ptr_array, int size, double element)
{
	int index = -1;
	for (int i = 0; i <= size; i++)
	{
		if (element == ptr_array[i]) 
		{
			index = i;
		}
	}
	return index;
}



double funtion_homework_lb11(double* ptr_array, int n)
{
	int first_p = 0, last_p = 0;
	double  sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (ptr_array[i] > 0)
		{
			first_p = i;
			break;
		}
	}
	for (int i = n - 1; i < n; i--)
	{
		if (ptr_array[i] > 0)
		{
			last_p = i;
			break;
		}
	}
	if ((last_p - first_p) > 1)
	{
		for (int i = first_p + 1; i < last_p; i++)
		{
			sum += ptr_array[i];
		}
		printf("Сумма элементов между первым и последним положительными элементами равна %lf", sum);
	}
	else
	{

		printf("Между первым и последним положительными элементами нет других чисел");
	}
}

double func(double x)
{
	double y;
	y = pow(2, x) - 2 * pow(x, 2) - 1;
	return y;
}


//Работа 14 ДЗ
// Вариант 4
double funtion(double* ptr_array, int k)
{
	double max = ptr_array[0];
	for (int i = 0; i <= k; i++)
	{
		if (ptr_array[i] > max) 
		{
			max = ptr_array[i];
		}
	}
	return max;
}

