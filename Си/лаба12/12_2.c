#define _CRT_SECURE_NO_WARNINGS //подключаем необходимые библиотеки
#include <stdio.h> //ввоод/вывод
#include <locale.h> //русский язык
#include <string.h> //функции для работы со строками
#include <stdlib.h> //выделение памяти
#include <math.h>
 
typedef struct Node //структура узел 
{
    char* value;
    struct Node* next; //следующий эелемнт
    struct Node* prev; //преддщуий элемент
} Node;
 
 
void input(char** s) //функция ввода строки
{ //ввод строки
    printf("Введите строку из слов\n");
    char* tmp;// обьявляем указатель на строку
    tmp = (char*)malloc(330); // выделение памяти
    gets(tmp); // ввод строки
    tmp = strtok(tmp, ".");
    *s = tmp; //помещаем считанную строку в исходную
}
 
void PrintList(Node* head) //распечатка листа
{
    Node* p = head;
    if (!p) { //если головы нету
        printf("Пустой лист\n"); //форматированный вывод строки
        return;
    }
    for (; p != NULL; p = p->next) { //пока не дошли до конца
        printf("%s ", p->value); //форматированный вывод строки
    }
}
 
Node* addElement(Node* head, char* word, int position) //вставка эелемнта в двусвязный список
{
    Node* new_node, * tmp;
    int i = 0; //счетчик
    //сначала создается новый элемент и задаются его значения
    new_node = (Node*)malloc(sizeof(Node)); //выделение пямти
    new_node->value = (char*)malloc(30); //выделение пмяти 
    strcpy(new_node->value, word); //копируем
    new_node->next = NULL;
    new_node->prev = NULL;
    //аналогично односвязному списку
    if (!head) //если головы нет
    {
        return new_node;
    }
 
    if (!position) //если добавляем перед текущей головой
    {
        new_node->next = head;
        return new_node;
    }
 
    tmp = head;
    while (tmp->next && i < position - 1) //доходим до элемента с нужно позицией
    {
        tmp = tmp->next;
        i++;
    }
 
    if (!tmp->next) //если добавляем в конец, то уже все сделано, голова не изменилась
    {
        new_node->prev = tmp;
        tmp->next = new_node;
        return head;
    }
    new_node->next = tmp->next;
    tmp->next = new_node;
    new_node->prev = tmp;
    new_node->next->prev = new_node;
    return head;
}
 
Node* DeleteNode(Node* head, int index) //удаление элемента
{
 
    Node* elm = head, * tmp;
    int i = 0;
 
    if (!elm)
    {
        printf("Пустой лист\n"); //форматированный вывод строки, если элементов нет
        return head;
    }
 
    //удаляем голову
    if (!index)
    {
        elm = head->next;
        elm->prev = NULL;
        head->next = NULL;
        head->prev = NULL;
        free(head);
        return elm;
    }
 
    while (elm && i < index - 1) //пока не дошли до нужного элемента
    {
        elm = elm->next;
        i++;
    }
 
    //если индекс больше длины списка, ничего не делаем
    if (!elm)
        return head;
    if (!elm->next)
        return head;
 
    tmp = elm->next;
 
    if ((elm->next)->next)
    {
        ((elm->next)->next)->prev = elm;
        elm->next = (elm->next)->next;
        tmp->next = NULL; //(elm->next)->next = NULL;
        tmp->prev = NULL;
 
    }
    else
        elm->next = NULL;
 
    free(tmp); //очищаем память 
 
    return head;
}
 
Node* CreateList(char* s) //создание листа
{
    char* copied[330]; //обьявляем строку с заданным числом элементов
    strcpy(copied, s); //копируем строку s в copied
    int count = 0; //количество слов 
    char* vec[30]; //массив слов
    char sep[] = " "; //разделитель - пробел
 
    char* cur = strtok(copied, sep); //обрезаем первый элемент до пробела
    Node* L = NULL;
    while (cur != NULL) //цикл
    {
        if (count == 30) 
        {
            printf("Количество слов в строке превышает 30\n");
            return NULL;
        }
        vec[count] = cur; //присвоение слова массиву
        count++; //увеличиваем на еденицу
        cur = strtok(NULL, sep);
    }
    for (int i = 0; i < count; ++i) 
    {
        L = addElement(L, vec[i], i);
    }
    return L;
}
 
int isVowel(char c) //главные буквы
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') 
    {
        return 1;
    }
    return 0;
}
 
Node* func1(Node* L) // функция, создающая список L1, состоящий из слов с первой гласной буквой
{ 
    Node* L1 = NULL;
    Node* p = L;
    int ind1 = 0;
    for (; p != NULL; p = p->next) 
    {
        if (isVowel(p->value[0])) //проверка если буква гласная
        {
            L1 = addElement(L1, p->value, ind1); //вызываем функцию вставки элемента
            ind1++;
        }
    }
    return L1;
}
 
Node* func2(Node* L) // функция, создающая список L1, состоящий из слов с первой согласной буквой
{ 
    Node* L2 = NULL;
    Node* p = L;
    int ind2 = 0;
    for (; p != NULL; p = p->next) 
    {
        if (!isVowel(p->value[0])) //проверка если буква согласная
        {
            L2 = addElement(L2, p->value, ind2); //вызываем функцию вставки элемента
            ind2++;
        }
    }
    return L2;
}
 
Node* ChangeList(Node* L) //изменяем лист
{
    char* mx;
    mx = (char*)malloc(30); //выделение памяти
    strcpy(mx, L->value); //копируем
 
    Node* p;
    for (p = L; p != NULL; p = p->next) //пока не дошли до конца
    {
        if (strcmp(p->value, mx) > 0) 
        {
            strcpy(mx, p->value);
        }
    }
    int i = 0;
    for (p = L; p != NULL; ) //пока не дошли до конца
    {
        if (!strcmp(mx, p->value)) //если не равно
        {
            p = p->next;
            L = DeleteNode(L, i); //вызываем функцию удаления
            --i;
        }
        else //инчае
        {
            p = p->next; //следующий элемент
        }
        ++i;
    }
    return L;
}

void PrintReversedList(Node* head) { //фунция разворота списка
    Node* p = head; //голова
    if (!p) {
        printf("Пустой лист\n"); //форматированный вывод строки
        return;
    }
    for (; p != NULL; p = p->next) {
        if (p->next == NULL) { //елси доршли до конца
        break; //прекращаем цикл
        }
    }
    for (; p != NULL; p = p->prev) { //цикл пока не дошли до начала
        printf("%s ", p->value); //форматированный вывод строки
    }
}
 
Node* ClearList(Node* L)  //очистка листа
{
    Node* next, * tmp = L;
 
    while (tmp) //перебор
    {
        next = tmp->next; //следующий элемент
        free(tmp); //очищаем память
        tmp = next;
    }
 
    L = NULL;
 
    printf("\nЛист очищен"); //форматированный вывод строки 
}

 
int main() 
{
    setlocale(LC_ALL, "rus"); //подключаем русский язык
    char* s; //обьявление строки
    input(&s); //вызываем функцию ввода строки
    Node* L;
    L = CreateList(s); //вызываем функцию выполнения задания
    PrintList(L); //функция печати
    printf("\n"); //форматированный вывод строки
    PrintReversedList(L); //разворачиваем список
    printf("\nСписок из гласных:\n"); //форматированный вывод строки
    Node* L1 = func1(L); //вызов функции с гласными
    PrintList(L1); //функция печати
    printf("\n"); //форматированный вывод
    PrintReversedList(L1); //разворачиваем список
    printf("\nСписок из согласных:\n"); //форматированный вывод строки 
    Node* L2 = func2(L); //вызов функции с согласными 
    PrintList(L2); //функция печати
    printf("\n"); //форматированный вывод 
    PrintReversedList(L2); //разворачиваем
    ClearList(L1); //очистка
    ClearList(L2); //очистка
    ClearList(L); //очистка
}