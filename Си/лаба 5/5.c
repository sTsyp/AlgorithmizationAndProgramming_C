#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
void cr(int** pB, int* pM, int* pN)
{
    int M, B, N; 
    int* B; 
    
    printf("Введите количество строк:");
    scanf("%d", &M);
    printf("Введите количество столбцов:");
    scanf("%d", &N);
    
    if(M<2 || N>10)
    {
        printf("Вы ввели недопустимые размеры!!!");
    }

    B=(int*)malloc(M * sizeof(int));
    for(int i=0;i<M;i++)
    {            
        B[i]=(int*)malloc(N*sizeof(int));
    }


    for(int i=0;i<=M-1;i++)
    {
        for(int j=0;j<=N-1;j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
    printf("\nМассив имеет вид:");
    for(int i=0;i<=M-1;i++)
    {
        printf("\n");
        for(int j=0;j<=N-1;j++)
        {
            printf(" %d ", B[i][j]);
        }
    }


    *pB = B; 
    *pM = M;
    *pN = N; 
}

void B_free(int **B, int M)
{
    for(int i = 0; i < M; i++) 
    {
        free(B[i]);
    }
    free(B);
}

void f1(int* B, int N, int M)
{
    int min, sum; 
    for (int i = 0; i < M; i++)
    {            
        sum = 0;
        for (int j = 0; j < N; j++)
        {
            sum += B[i][j];          /* подсчет суммы строки*/
        }
        if(i == 0)                 
            min = sum;              /* присваиваем минимальную сумму нулевой строке */
        else
        if(sum < min)               
            min = sum;              /* проверяем есть ли строки меньше чем минимальная*/
    }
    printf("%d", min);  
}
int main()
{
    int M, N;
    int* B;
    cr(&B, &M, &N);
    f1(B, M, N);
    B_free(B, M);
    return 0; 
}