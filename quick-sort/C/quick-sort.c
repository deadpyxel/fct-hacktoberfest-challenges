/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Bibliotecas */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Definir limpeza de tela para Windows e Linux */

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Maximo valor do Array */

#define MAX 1000


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Quick Sort */

void QuickSort(int array[], int inicio, int fim){
    int i, j, pivot, temp;
    if (inicio < fim){
        pivot = inicio;
        i = inicio;
        j = fim;
        while(i < j){
            while(array[i] <= array[pivot] && i < fim)
            i++;
            while(array[j] > array[pivot])
            j--;
            if(i < j){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        temp = array[pivot];
        array[pivot] = array[j];
        array[j] = temp;
        QuickSort(array, inicio, j-1);
        QuickSort(array, j+1, fim);
    }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Gerar Números Aleatórios */

void Random(int *array, int dim)
{
    int i;
    clock_t seed;
    seed = clock();
    srand(seed);
    for (i = 0; i < dim; i++)
        *(array + i)= rand() % (9999 + 1 - 0) + 0;
    return;
}

/*
 *Como restringir o intervalo gerado pela função rand:
 *rand() % (maior_valor + 1 - menor_valor) + menor_valor;
 */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Exibir Elementos de um Array */

void Visualizar(int *array, int dim){
    int i;
    for(i=0; i<=dim-1; i++){
        printf("Array[%d]=%d\n", i,*(array+i));
    }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Menu do Programa */

int main(void){

    int optA, optB, dim;

    do{
        system(CLEAR);
        printf("\n ###### Trabalho pratico de programação 02 ######\n");
        printf("\nInsira a dimensão do array: (MIN = 1, MAX = 1000)\n");
        scanf("%d", &dim);
    }while(dim < 2 || dim > MAX);

    int array[dim];

    do{
        system(CLEAR);
        printf("\nSeu array tem tamanho %d.\n", dim);
        printf("\nDigite [1] para gerar valores aleatórios para o array.");
        printf("\nDigite [2] para sair.\n\n");
        scanf("%d", &optA);
    }while(optA < 1 || optA > 2);

    switch(optA){
        case 1:
            do{
                printf("\nO seu array é:\n\n");
                Random(array, dim);
                Visualizar(array, dim);
                printf("\n\n\n");
                printf("Digite [1] para organizar o array utilizando Quick Sort.\n");
                printf("Digite [2] para sair.\n\n");
                scanf("%d", &optB);
            }while(optB < 1 || optB > 2);

            switch(optB){
                case 1:
                    QuickSort(array, 0, dim-1);
                    printf("\nO array foi organizado: \n\n");
                    Visualizar(array, dim);
                    printf("\nPressione ENTER para sair.\n\n");
                    getchar();
                    getchar();
                    return 0;

                case 2:
                    return (0);
            }

        case 2:
            return 0;
    }
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/