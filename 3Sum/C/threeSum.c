#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum Boolean{f, v} boolean;


void vectorScan(int *vector, const int lenght){
    char ch[10];
    int i;
    for(i = 0; i < lenght; i++){
        numValidate(ch, vector + i, "Insira o proximo termo: ");
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
                    if(i == j || i == k || j == k)
                        continue;
                    else{
                        *n1 = *(vector + i);
                        *n2 = *(vector + j);
                        *n3 = *(vector + k);
                        return(1);
                    }
                }
    return(0);
}

boolean charToInt(const char *String, int *num){
    int i = 0, sign = 1;
    if(!(*String >= 48 || *String <= 57) && *String != 45)
        return(0);
    if(*String == 45){
        sign = -1;
        i = 1;
    }*num = 0;
    for(; *(String + i) != '\0'; i++){
        if(*(String + i) < 48 || *(String + i) > 57)
            return(0);
        *num *= 10;
        *num += *(String + i) - 48;
    }*num *= sign;
    return(1);
}

boolean charToUnsignedInt(const char *String, int *num){
    int i;
    *num = 0;
    for(i = 0; *(String + i) != '\0'; i++){
        if(*(String + i) < 48 || *(String + i) > 57)
            return(0);
        *num *= 10;
        *num += *(String + i) - 48;
    }return(1);
}

void numValidate(const char *String, int *var, const char *msg){
    do{
        system("cls");
        puts(msg);
        gets(String);
    }while(!charToInt(String, var));
    return;
}

void numUnsignedValidate(const char *String, int *var, const char *msg){
    do{
        system("cls");
        puts(msg);
        gets(String);
    }while(!charToUnsignedInt(String, var));
    return;
}


void main(){
    char ch[10];
    int n, op = 0;
    numUnsignedValidate(ch, &n, "Insira o numero de termos da sua lista: ");
    int num[n];
    do{
        numValidate(ch, &op, "Deseja inserir os numeros ou gera-los automaticamente?\n\n1 - Inserir\n2 - Gerar\n\nOpcao: ");
    }while(op < 1 || op > 2);
    if(op == 1)
        vectorScan(num, n);
    else
        vectorGenerator(num, n);
    vectorPrint(num, n);
    int num1, num2, num3;
    if(threeSum(num, n, &num1, &num2, &num3))
        printf("\n\n\nOs numeros %d, %d e %d somados resultam em zero.\n\n", num1, num2, num3);
    else if(n < 3)
        puts("\n\nSua lista nao possui elementos suficientes para a soma.\n\n");
    else
        puts("\n\n\nNenhum dos numeros da lista, quando somados, resultam em zero.\n\n");
    system("Pause");

    return;
}
