#define _CRT_SECURE_NO_WARNINGS //исключаем ошибки, возникающие при работе со старыми функциями 
#include <stdio.h> //подключение библиотеки, отвечающей за форматированный ввод и выволд переменных
#include <locale.h> //подключение библиотеки, отвечающей за подключение русского язка
#include <stdlib.h> //подключение библиотеки, отвечающей за выеделние памяти 
#include <string.h> //подключение библиотеки, отывечающей за функции работы со строками 
#include "KIT.h" //подключение файла 
#define key 1 //выбор варианта кода


void PrintKit(struct kit *tmp) //распечатка структуры
{
	printf("НАЗВАНИЕ: %s\n", tmp->name); //название набора
	printf("ЦЕНА: %d\n", tmp->price); //цена набора
	printf("ПАРАМЕТРЫ: вес(%d), высота(%d), ширина(%d)\n", tmp->character.weight, tmp->character.height, tmp->character.widht);
	//параметры набора (вес, высота, ширина)
}

struct kit vec[21];
struct kit pustaya;
struct kit func(int n, struct kit vec[]) //функция выполнения задания
{

	int ans_id = 0; //инициализация переменной со значением 0 
	int min_price = vec[0].price;
	for (size_t i = 0; i < n; ++i) //цикл перебора
	{
		int cur_price = vec[i].price; //присвоение текущей цены 
		if (cur_price == min_price) //сравнение
		{
			if (vec[ans_id].character.height <= vec[i].character.height) //еслив высота меньше, то 
			{
				ans_id = i; //присваиваем перменной текущий индекс
			}
		} 
		else if(cur_price < min_price) //если цена меньше 
		{
			ans_id = i; //присваиваем
			min_price = vec[i].price; //присваиваем минимум
		}
	}
	return vec[ans_id];
}

void func1(int n, struct kit vec[]) //фуннкция распечатки
{
	for (size_t i = 0; i < n; i++) //цикл перебора
	{
		if (vec[i].character.height == pustaya.character.height && vec[i].price == pustaya.price) //если найдутся два одинаковых 
		{
			PrintKit(&vec[i]); //печать 
		}
	}
}

int main() 
{
	setlocale(LC_ALL, "RUS"); //подключение русского языка
#if key == 1
	printf("key = %d\n", key); //распечатка выбора ключа
	
	int n;
	printf("Введите количество наборов:\n"); //распечатка строки
	scanf("%d", &n); //форматированный ввод 
	getchar();

	if (n <= 20) 
	{
		printf("Введите инфоормацию о наборах:\n"); //распечатка строки
		for (size_t i = 0; i < n; ++i) //цикл перебора
		{
			struct kit tmp = {" ", {0}, {0, 0, 0}}; //присвоение структуры 
			
			printf("Введите название набора:\n"); //распечатка строки
			gets(tmp.name); //ввод строки

			printf("Введите цену набора:\n"); //распечатка строки
			scanf("%d", &tmp.price); //форматированный ввод
			
			printf("Введите параметры набора:\n"); //распечатка строки
			scanf("%d%d%d", &tmp.character.height, &tmp.character.weight, &tmp.character.widht); //форматированный ввод 
			
			vec[i] = tmp; 
			getchar();
		}

		for (size_t i = 0; i < n; ++i) //цикл перебора по элементам
		{
			printf("\nНабор №%d:\n", i + 1); //распечатка строки
			PrintKit(&vec[i]); //вызов функции распечатки структуры 
		}
		printf("\n\nСамый высокий набор минимальной цены:\n\n"); //распечатка строки
		pustaya = func(n, vec); //присвоение возвращаемого значения функции структуре 
		func1(n, vec); //вызов функции 
	}
	else {
		printf("Превышена максимальная длина массива\n"); //распечатка строки 
	}
#elif key == 2 //вторая ветка задания
	printf("key = %d\n", key); //распечатка выполняемого ключа
	int n = 10; //инициализация переменной значения 10 
	for (size_t i = 0; i < n; ++i) //цикл перебора 
	{
		vec[i] = testing_vec[i]; //присваиваем значению итого элемента тестового значения
		printf("\nНабор №%d:\n", i + 1); //распечатка строки 
		PrintKit(&vec[i]); //вызываем функцию распечатки структуры 
		printf("\n\nСамый высокий набор минимальной цены:\n\n"); //распечатка строки 
		pustaya = func(n, testing_vec); //присвоение возвращаемого значения функции структуре
		func1(n, testing_vec); //вызываем функцию 
	}
#else
	printf("Указано неверное значение key\n"); //иначе распечатка этой строки 
#endif
}