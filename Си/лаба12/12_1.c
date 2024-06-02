#define _CRT_SECURE_NO_WARNINGS //подключаем необходимые библиотеки
#include <stdio.h> //ввоод/вывод
#include <locale.h> //русский язык
#include <string.h> //функции для работы со строками
#include <stdlib.h> //выделение памяти
#include <math.h>
 
typedef struct Node { //описание алгоритмов основных алгоритмов 
    int degree; //информационное поле (степень) 
    int val; //информационное поле (коэффицент)
    struct Node* next; //адресное поле (следующий элемент)
} Node;
 
 
void PrintPolinomyal(Node* head) { //печать односвязного списка
    int cnt = 0; //счетчик, обозначает количество введенных элементов
    Node* p = head; //голова 
    if (!p) { //если ничего не введено
        printf("Пустой многочлен\n"); //то форматированный вывод строки
        return; //конец функции
    }
    if (p->val != 0) { //если коэффицент не равен 0
        printf("%dx^%d ", p->val, p->degree); //форматированный вывод 
        ++cnt; //увеличиваем счетчик
    }
    p = p->next; //следующий элемент
    for (; p != NULL; p = p->next) { //цикл перебора, пока не закончился ввод 
        if (p->val > 0) { //если коэффицент больше 0
            if (cnt > 0) { //если счетчик больше 0
                printf("+%dx^%d ", p->val, p->degree); //то форматированно выводим строку
                ++cnt; //и увеличиваем счетчик
            }
            else { //иначе
                printf("%dx^%d ", p->val, p->degree); //форматированно выводим строку
                ++cnt; //и увеличиваем счетчик
            }
        }
        else if (p->val < 0) { //если коэффицент меньше нуля
            printf("%dx^%d ", p->val, p->degree); //форматированно выводим строку
            ++cnt; //и увеличиваем счетчик
        }
    }
    printf("\n");
}
 
Node* addElement(Node* head, int value, int degree, unsigned int position) //вставка элемента в односвязный список 
{
    Node* new_node, * tmp; //обьявление перемен
    int i = 0; //инициализация счетчика
    new_node = (Node*)malloc(sizeof(Node)); //динамическое выделение памяти под размер
    new_node->degree = degree; //присваиваем значение переменных
    new_node->val = value;
    new_node->next = NULL; 
    if (!head) //если список пустой, то уже все сделано, возвращаем новую голову
        return new_node;
 
    if (!position) //если добавляем перед текущей головой
    {
        new_node->next = head;
        return new_node;
    }
 
    tmp = head;
    while (tmp->next && i < position - 1) //доходжим до элемента с нужной позицией
    {
        tmp = tmp->next;
        i++;
    }
 
    if (!tmp->next) //если добавляем в конец, то уже все сделано, голова не изменилась
    {
        tmp->next = new_node;
        return head;
    }
    new_node->next = tmp->next;
    tmp->next = new_node;
    return head;
}
 
Node* ClearList(Node* L) { //очистка листа 
    Node* next, * tmp = L;
 
    while (tmp) //пока не дошли до конца
    {
        next = tmp->next;
        free(tmp); //очищаем память
        tmp = next;
    }
 
    L = NULL;
 
    printf("Лист очищен\n");
}
 
Node* deleteElement(Node* head, int position) { //удаление элемента из односвязного списка
    Node* elm = head, * tmp; //обьявление и ирницализация переменных
    int i = 0; //счетчик
 
    if (!elm) {  //если списорк пустой
        printf("List is empty\n\n"); //форматированный вывод строки
        return head; //возвращаем голову
    }
    //удаляем голову
    if (!position) {
        elm = head->next;
        head->next = NULL; //присваиваем значение NULL
        free(head); //очищаем память
        return elm;
    }
 
    while (elm != NULL && i < position - 1) {
        elm = elm->next;
        i++;
    }
 
    //если индекс больше длины списка, ничего не делаем
    if (!elm) {
        return head;
    }
    if (!elm->next) {
        return head;
    }
 
    tmp = elm->next;
 
    if ((elm->next)->next) {
        elm->next = (elm->next)->next;
        tmp->next = NULL;
    }
    else {
        elm->next = NULL;
    }
    free(tmp); //очищаем память
    return head;
}
 
Node* ChangePolinomyal(Node* L) { //задание / меняем список
    int ind = 0; //счетчик
    Node* p = L;
    for (; p != NULL;) { //пока не дошли до конца
        if (p->degree % 2 == 0) { //если степень четная
            L = deleteElement(L, ind); //вызываем функцию удаления элемента
            p = L;
            ind = 0; //обнуляем счетчик
        }
        else { //инчае
            ind++; //увеличиваем счетчик
            p = p->next; //следующий элемент
        }
    }
    return L;
}
 
 
Node* CreatePolinomyal() { //ввод полинома
    printf("Введите количество членов в многочлене L:\n"); //форматированный вывод строки
    int n; //количество элементов
    scanf("%d", &n); //форматированный ввод 
    printf("Почленно введите данные многочлена:\n"); //форматированный вывод
    Node* L = NULL;
    for (int i = 0; i < n; ++i) { //цикл
        int tmp_degree, tmp_val; //степень и коэффицент 
        scanf("%d%d", &tmp_val, &tmp_degree); //форматированный ввод коэффицента и степени элемента
        Node* p = L;
        int flag = 0; //флаг
        for (int j = 0; j < i, p != NULL; j++) {
            if (tmp_degree == p->degree) { //если степени элементов равны
                p->val += tmp_val; //складываем коэффиценты 
                flag = 1; //флаг=1
            }
            p = p->next; //следующий элемент 
        }
        if (flag == 0) { //если флаг не изменился
            L = addElement(L, tmp_val, tmp_degree, i); //вызываем функцию вставки элемента
        }
    }
    return L;
}
 
 
 
int main() {
    setlocale(LC_ALL, "rus"); //подключаем русский язык
    Node* L;
    L = CreatePolinomyal(); //вызываем функцию ввода полинома
    PrintPolinomyal(L); //вызываем функцию печати
    L = ChangePolinomyal(L); //вызываем функцию изменения
    printf("Измененный многочлен:\n"); //форматированный вывод строки
    PrintPolinomyal(L); //вызываем функцию печати
    ClearList(L); //очистка памяти и листа
}