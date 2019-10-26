#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum Boolean{f, v} boolean;



void vectorScan(int *vector, const int lenght){
    int i;
    for(i = 0; i < lenght; i++){
        system("cls");
        printf("Insira o termo do indice [%d]: ", i);
        scanf("%d", vector + i);
    }
}

void vectorGenerator(int *vector, const int lenght){
    int i, sign;
    time_t t;
    srand((unsigned) time(&t));
    for(i = 0; i < lenght; i++){
        sign = rand() % 2;
        if(sign)
            sign = -1;
        else
            sign = 1;
        *(vector + i) = (rand() % 10) * sign;
    }
    return;
}

void vectorPrint(int *vector, const int lenght){
    int i;
    system("cls");
    for(i = 0; i < lenght; i++)
        printf("\n[%2d]: %3d", i, *(vector + i));
    puts("\n\n");
    system("Pause");
    system("cls");
    return;
}

boolean threeSum(const int *vector, const int lenght, int *n1, int *n2, int *n3){
    int i, j, k;
    for(i = 0; i < lenght; i++)
        for(j = 0; j < lenght; j++)
            for(k = 0; k < lenght; k++)
                if(*(vector + i) + *(vector + j) + *(vector + k) == 0){
                    *n1 = *(vector + i);
                    *n2 = *(vector + j);
                    *n3 = *(vector + k);
                    return(1);
                }
    return(0);
}

void main(){
    puts("Insira o numero de termos da sua lista: ");
    int n, op;
    scanf("%d", &n);
    int num[n];
    do{
        system("cls");
        puts("Deseja inserir os numeros ou gera-los automaticamente?\n\n1 - Inserir\n2 - Gerar\n\nOpcao: ");
        scanf("%d", &op);
    }while(op < 1 || op > 2);
    if(op == 1)
        vectorScan(num, n);
    else
        vectorGenerator(num, n);
    vectorPrint(num, n);
    int num1, num2, num3;
    if(threeSum(num, n, &num1, &num2, &num3))
        printf("\n\n\nOs numeros %d, %d e %d somados resultam em zero.", num1, num2, num3);
    else
        puts("\n\n\nNenhum dos numeros da lista, quando somados, resultam em zero");

    return;
}
