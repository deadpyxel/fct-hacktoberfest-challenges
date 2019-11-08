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
int Altura(struct no *arvore)
{
   if (arvore == NULL)
        return -1;
    int he = Altura(arvore->esq);
    int hd = Altura(arvore->dir);
    if (he > hd)
        return he+1;
    return hd+1;
}
void BuscaNoAltura(struct no *arvore, int altura)
{
    if(arvore!=NULL)
    {
        if(Altura(arvore)==altura)
            printf("%d ", arvore->info);
        BuscaNoAltura(arvore->esq, altura);
        BuscaNoAltura(arvore->dir, altura);
    }
}

int main(void)
{
    struct no *a1 = NULL;
    InserirRec(&a1, 1);
    InserirRec(&a1, 2);
    InserirRec(&a1, 3);
    InserirRec(&a1, 4);
    InserirRec(&a1, 5);
    InserirRec(&a1, 7);
    BuscaNoAltura(a1, 2);
    return(0);
}
