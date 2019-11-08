#include <stdio.h>
#define MAX 20
void multiplication_table(int tam){
	if (tam > MAX){
		printf("tamanho maior que o maximo permitido");
		return 0;
	}
	int table[tam][tam],i,j;
	for(i=1;i<tam+1;i++){
		for(j=1;j<tam+1;j++){
			
			table[i-1][j-1]=i*j;
			printf("%5d",table[i-1][j-1]);
		}
		printf("\n");
		
	}
	return;
}
int main(void){
	int n;
	printf("insere um numero");
	scanf("%d",&n);
	multiplication_table(n);
	return 0;
}
