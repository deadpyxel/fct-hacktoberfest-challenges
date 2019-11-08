#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct no
{
    int info;
    struct no *esq, *dir;
};
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
void RotacionaDir(struct no **arvore)
{
    struct no *aux;
    aux = (*arvore)->esq;
    (*arvore)->esq = aux->dir;
    aux->dir = *arvore;
    *arvore = aux;
}
void RotacionaEsq(struct no **arvore)
{
    struct no *aux;
    aux = (*arvore)->dir;
    (*arvore)->dir = aux->esq;
    aux->esq = *arvore;
    *arvore = aux;
}
int FatorBalanceamento(struct no *NO)
{
    return(Altura(NO->dir)-Altura(NO->esq));
}
short InserirRec(struct no **arvore, int elem)
{
    int FB;
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
        //      BALANCEAMENTO
        FB = FatorBalanceamento(*arvore);
        if(FB>=2)   //A arvore esta desbalanceada a direita, ou seja, a altura da direita é maior
        {
            if(FatorBalanceamento((*arvore)->dir)>0)  //Mesmo sinal
                RotacionaEsq(&(*arvore));
            else
            {
                RotacionaDir(&((*arvore)->dir));
                RotacionaEsq(&(*arvore));
            }
        }
        else if(FB<=-2)    //A arvore esta desbalanceada a esquerda, ou seja, a altura da esquerda é maior
        {
            if(FatorBalanceamento((*arvore)->esq)>0)
            {
                RotacionaEsq(&((*arvore)->esq));
                RotacionaDir(&(*arvore));
            }
            else        //Mesmo sinal
                RotacionaDir(&(*arvore));
        }
    }
}
void PreOrdem(struct no *arvore)
{
    if(arvore!=NULL)
    {
        printf("%d ", arvore->info);
        PreOrdem(arvore->esq);
        PreOrdem(arvore->dir);
    }
}
void vetorParaArvore(int *vetor, int tamanhoVet, struct no **arvore)
{
	int i;
	for(i=0 ; i<tamanhoVet ; i++)	//Percorrendo o vetor
	{
		InserirRec(arvore, vetor[i]);
	}
}
int main(void)
{
    struct no *raiz=NULL;
    int vetor [7] = {1, 2, 3, 4, 5, 6, 7};
    vetorParaArvore(vetor, 7, &raiz);
    printf("\n  Pre-Ordem: ");
    PreOrdem(raiz);
    
    return(0);
}
