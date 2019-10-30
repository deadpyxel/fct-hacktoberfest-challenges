#include <stdio.h>
#include <stdlib.h>

struct no
{
    int info;
    struct no *next;
};
struct lista
{
    struct no *ini, *fim;
};
void InicializaLista(struct lista *L)
{
    L->ini=NULL;
    L->fim=NULL;
}
short InsereNoFim(int valor, struct lista *L)
{
    struct no *p=NULL;
    p=(struct no *)malloc(sizeof(struct no));
    if(p==NULL)
        return(0);
    p->next=NULL;
    p->info=valor;
    if(L->ini==NULL) //Lista vazia
        L->ini=p;
    else
        L->fim->next=p;
    L->fim=p;
    return(1);
}
void CriaLista(struct lista *L, int TAMANHO)
{
    //Cria uma lista de acordo com o valor digitado.
    //Obs: como está sendo utilizado a função de inserir no fim, é necessário digitar a sequência já ordenada.
    int i=0, valor=0;
    for(i=0 ; i<TAMANHO; i++)
    {
        printf("\n  %d = ", i+1);
        scanf("%d", &valor);
        InsereNoFim(valor, L);
    }
}
void ImprimeLista(struct lista *L)
{
    struct no *p=NULL;
    if(L->ini==NULL)
        printf("\n        Lista vazia!");
    else
    {
        for(p=L->ini ; p!=NULL ; p=p->next)
            printf("%d ", p->info);
    }
    printf("\n\n");
}
void IntercalaListaOrdenada(struct lista *L1, struct lista *L2, struct lista *L3)
{
    struct no *p=NULL, *q=NULL;
    p=L1->ini;
    q=L2->ini;
    while((p!=NULL)&&(q!=NULL))
    {
        if(p->info < q->info)
        {
            InsereNoFim(p->info, L3);
            p=p->next;
        }
        else if(q->info < p->info)
        {
            InsereNoFim(q->info, L3);
            q=q->next;
        }
        else        //Os elementos são iguais, logo basta colocar só um
        {
            InsereNoFim(p->info, L3);
            p=p->next;
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        InsereNoFim(p->info, L3);
        p=p->next;
    }
    while(q!=NULL)
    {
        InsereNoFim(q->info, L3);
        q=q->next;
    }
}

int main(void)
{
    struct lista L1, L2, LResult;
    InicializaLista(&L1);
    InicializaLista(&L2);
    InicializaLista(&LResult);
    CriaLista(&L1, 3);
    CriaLista(&L2, 3);
    IntercalaListaOrdenada(&L1, &L2, &LResult);
    ImprimeLista(&LResult);
    return(0);
}
