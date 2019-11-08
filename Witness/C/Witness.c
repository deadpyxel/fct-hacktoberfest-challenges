#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum Boolean {f, v} boolean;

boolean charToInt(const char *String, int *num){
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

void vectorScan(int *vector, const int lenght){
    char ch[10];
    int i;
    for(i = 0; i < lenght; i++){
        numValidate(ch, vector + i, "Insira a proxima altura: ");
    }
}

void vectorGenerator(int *vector, const int lenght){
    int i;
    time_t t;
    srand((unsigned) time(&t));
    for(i = 0; i < lenght; i++)
        *(vector + i) = (rand() % 10);
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

int witnessCounter(int *vector, int lenght){
    int i, j, count = 1, taller = *(vector + lenght - 1);
    for(i = lenght - 1; i >= 0; i--)
        for(j = i - 1; j >= 0; j--)
            if(*(vector + j) > *(vector + i) && *(vector + j) > taller){
                count++;
                taller = *(vector + j);
            }
    return(count);
}


void main(){
    char ch[10];
    int n, op;
    numValidate(ch, &n, "Quantas pessoas estao na fila?");
    int people[n];
    do{
        numValidate(ch, &op, "Deseja inserir as alturas ou gera-las automaticamente?\n\n1 - Inserir\n2 - Gerar\n\nOpcao: ");
    }while(op < 1 || op > 2);
    if(op == 1)
        vectorScan(people, n);
    else
        vectorGenerator(people, n);
    vectorPrint(people, n);
    int witness = witnessCounter(people, n);
    printf("Houveram %d testemunhas\n\n", witness);
    system("Pause");
}
