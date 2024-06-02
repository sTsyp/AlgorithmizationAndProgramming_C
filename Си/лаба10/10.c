#define _CRT_SECURE_NO_WARNINGS //функция, отключающая предупреждения о устаревших функциях 
#include <stdio.h> //подключаем библиотеку, содержащую форматированный ввод и вывод 
#include <locale.h> //русский язык

void creatingfile(const char* fName) //создание файла
{
    FILE* f = fopen(fName, "wb"); //открываем с нужным расширением

    if (!f) //если там пусто
    {
        printf("Пусто в %s\n", fName); //форматированный ввод
        return; //конец функции
    }

    int n = 0; //счетчик
    printf("Введите количество элементов: \n"); //форматированный вывод строки
    scanf("%d", &n); //форматированный ввод количества элементов
    
    printf("Введите элементы:\n"); //форматированный вывод строки
    for (int i = 0; i < n; i++) //цикл
    {
        int el; //обьявление переменной
        scanf("%d", &el); //форматированный ввод переменной
        fwrite(&el, sizeof(int), 1, f); //записывает массив размером
    }

    fclose(f); //закрывает файл
}

void printingfile(const char* fName) //печать файла
{
    FILE* f = fopen(fName, "rb"); //открываем с нужным расширением

    if (!f) //если пусто
    {
        printf("Пусто\n"); //форматированный вывод строки
        return; //конец функции
    }

    printf("В файле вот это:\n"); //что там находится
    rewind(f); //в начало файла

    while (!feof(f)) //пока не пришли в конец
    {
        int el; //обьявление переменной
        fread(&el, sizeof(int), 1, f); //чтение
        if (!feof(f)) printf("%d ", el); //если не конец, пишем 
    }
    printf("\n"); //переход на следующую строку

    fclose(f); //закрываем файл
}

int deleteEl(const char* fName) //удаление элемента
{
    FILE* f = fopen(fName, "r+b"); //открываем с нужным расширением

    if (!f) 
    {
        printf("Пусто\n"); //форматированный вывод строки 
        return; //конец функции
    }
    rewind(f);//перемещает указатель положения в файле на начало указанного потока


    int currIndex = 0; //инициализация переменных 
    int s = 0;
    int x;

    fread(&x, sizeof(int), 1, f); //чтение
    while (!feof(f)) //пока не дошли до конца
    {
        currIndex++; //увеличиваем счетчик
        fread(&x, sizeof(int), 1, f); //читаем
    }
    rewind(f); //уходим в начало файла

    int flag = 0; //инициализация переменной
    fread(&x, sizeof(int), 1, f); //чтение
    int counter = 1; //инициализация переменной
    while (!feof(f)) //пока не будет достигнут конец файла
    {
        if (x > 0 && x %2 == 0)  //по улсовию задания, четный положительный элемент
        {
            flag = 1; //поднимаем флаг 
            break; //заканчиваем цикл
        }
        fread(&x, sizeof(int), 1, f); //читаем
        counter++; //увеличиваем счетчик
    }

    int buf; //обьявление переменной
    rewind(f); //уходим в начало файла
    int c = counter; //обьявляем и присваиваем значение
    while (c < currIndex) //пока меньше 
    {
        fseek(f, (c) * sizeof(int), SEEK_SET);
        fread(&buf, sizeof(int), 1, f);
        rewind(f);
        fseek(f, (c-1) * sizeof(int), SEEK_SET);
        fwrite(&buf, sizeof(int), 1, f);
        rewind(f);
        c++;
    }

    int desc = _fileno(f);
    if (flag) 
    {
        _chsize(desc, (currIndex - 1) * sizeof(int));
        return 1;
        fclose(f);
    }

    fclose(f);
    return 0;
    
}

void writeBEGIN(const char* fName, int qd) //доп задание, добавление в начало файла
{
    FILE* f = fopen(fName, "r+b"); //открываем с нужным расширением

    rewind(f);//перемещает указатель положения в файле на начало указанного потока

    int currIndex = 0; //обьявление переменных
    int s = 0;
    int x;

    fread(&x, sizeof(int), 1, f); //чтение
    while (!feof(f)) //пока не будет достигнут конец файла
    {
        currIndex++; //увеличиваем счетчик
        fread(&x, sizeof(int), 1, f); //читаем
    }
    rewind(f); //уходим в начало файла

    int buf; //обьявляем переменную

    while (currIndex != 0) //пока не равен нулю
    {
        fseek(f, (currIndex - 1) * sizeof(int), SEEK_SET);
        fread(&buf, sizeof(int), 1, f);
        rewind(f);
        fseek(f, (currIndex) * sizeof(int), SEEK_SET);
        fwrite(&buf, sizeof(int), 1, f); 
        rewind(f);
        currIndex--;
    }

    printf("\n");
    fwrite(&qd, sizeof(int), 1, f);
    fclose(f);
}

void TASK(const char* fName) //задание
{
    int qd = 0;
    for (int i = 0; i < 10; i++) 
    {  
        qd += deleteEl(fName); 
    }
    writeBEGIN(fName, qd);
}



int main() 
{ //вызов всех функций
    setlocale(LC_ALL, "RUS");
    creatingfile("array.bin");
    
    printf("YOU ENTERNED\n");
    printingfile("array.bin");

    TASK("array.bin");
    printingfile("array.bin");
    return 0;
}