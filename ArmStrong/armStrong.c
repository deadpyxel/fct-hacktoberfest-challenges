#include <stdio.h>
#include <locale.h>

int Armstrong_number(int value){
	int copy=value, result=0, exponent=0;
	while(value>0){
		exponent++;
		value=value/10;
	}
	value=copy;
	while(value>0){
		result=result+pow(value%10,exponent);
		value=value/10;
	}
	if(result==copy)	return 1;
	return 0;
}
int main(void){
	int value;
	printf("insert a value");
	scanf("%d",&value);
	if(Armstrong_number(value)==1) printf("\n\n\n your value is Armstrong ");
	else printf("\n\n\n your value is not Armstrong");
	return 0;
}
