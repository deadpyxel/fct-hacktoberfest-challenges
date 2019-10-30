#include <stdio.h>
#include <stdlib.h>

struct no
{
    int info;
    struct no *esq, *dir;
};
struct arvore
{
    struct no *raiz;
};

short InserirRec(struct no **arvore, int elem)
{
    if(*arvore==NULL)   //Arvore vazia
    {
        struct no *novo;
        novo = (struct no *)malloc(sizeof(struct no));
        if(novo==NULL)
            return(0);
        novo->info = elem;
        novo->dir = NULL;
        novo->esq = NULL;
        *arvore = novo;
    }
    else
    {
        if(elem < (*arvore)->info)
            InserirRec(&(*arvore)->esq, elem);
        else if(elem > (*arvore)->info)
            InserirRec(&(*arvore)->dir, elem);
        else        //É igual, então não insere, pois não desejamos elementos repetidos
            return(0);
    }
}
void EncontraNo(struct no *arvore, int *nivel, int *nivelMax, int *res)
{
    if(arvore!=NULL)
    {
        *(nivel)=*(nivel)+1;
        EncontraNo(arvore->esq, nivel, nivelMax, res);
        if(*(nivel)>*(nivelMax))
        {
            *(res) = arvore->info;
            *(nivelMax) = *(nivel);
        }
        EncontraNo(arvore->dir, nivel, nivelMax, res);
    }
}

int main(void)
{
    struct no *a1 = NULL;
    int res = -1, nivelMax = -1, nivel=0;
    InserirRec(&a1, 3);
    InserirRec(&a1, 2);
    InserirRec(&a1, 1);
    InserirRec(&a1, 4);
    EncontraNo(a1, &nivel, &nivelMax, &res);
    printf("\n No mais distante -> %d", res);
    return(0);
}
