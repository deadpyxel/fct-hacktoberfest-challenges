#include <stdlib.h>
#include <stdio.h>

int main(){

	int aux = 1000;
	int i;

	for(i=1; i <= aux; i++){

		if(TwoOrMore(i) == 1 && IsPrime(i) == 1 
		&& NotContain(i) == 1 && SumDigits(i) == 1 && TwoDigits(i) == 1
		&& SecondToLast(i) == 1 && LastDig(i) == 1)

			printf("O Numero e: %d\n", i);
	}

return;
}

int TwoOrMore(int n){

	int aux=0;

	while(n > 0){
		n = n/10;
		aux++;
	}

	if(aux >= 2)
		return 1;

	else return 0;

}

int IsPrime(int n){
	
	int i;

	for(i=2; i < n; i++){

		if(n%i == 0)
			return 0;
	}

	return 1;
}

int NotContain(int n){

	int dig;

	while(n > 0){

		dig = n%10;

		if(dig == 1 || dig == 7)
			return 0;

		n = n/10;
	}
	return 1;
}

int SumDigits(int n){

	int soma=0;

	while(n > 0){

		soma += n%10;
		n = n/10;                             
	}

	if(soma <= 10)
		return 1;

	return 0;
}

int TwoDigits(int n){

	int soma=0;
	int i;

	n = n/10;
	for(i=0; i < 2; i++){
		soma += n%10;		
		n = n/10;
	}

	if(soma%2 != 0)
		return 1;

	return 0;
}

int SecondToLast(int n){
	
	int dig;

	n = n/10;
	dig = n%10;
	
	if(dig > 1 && dig%2 == 0)
		return 1;

	return 0;
}

int LastDig(int n){

	int ld, digs=0;

	ld = n%10;

	while(n > 0){

		n = n/10;
		digs++;
	}

	if(ld == digs)
		return 1;

	return 0;
}
