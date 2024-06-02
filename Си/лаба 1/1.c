#include <stdio.h> 
#include <locale.h> 
#include <math.h> 
#include <stdlib.h> 
int main() 
{
    int x = 4, y = 25;
    int *p = &x, *q = &y;
    p = q;
    if(p == q) 
    {
        *p = *q-4;
    }
    else 
    {
        if(*p == *q) 
        {
            q = p;
        }
    }
    if(*p == *q) 
    {
        *q = *p*3;;
    }
    printf("%d", *p);
    return 0; 
}
//ввод массива 
//первое задание
//второе задание
//функции должны возвращать значение 