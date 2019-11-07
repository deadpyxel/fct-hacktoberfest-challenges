#include <stdio.h>

#define max 20

int first_missing_positive (int input[], int n){
    int i;

    for (i = 0; i < n; i++){
        if (input[i] < 0){
            return i;
        }
    }

    return printf("No negative integer in your array. \n\n");
}

int main(){
    int n, i;
    int input[max];

    printf("Insert the quantity of numbers in your array (max.: 20): \n");
    scanf("%d", &n);
    printf("\n");

    for (i = 0; i < n; i++){
        printf("Insert a integer number: \n");
        scanf("%d", &input[i]);
        printf("\n");
    }

    return("%d", first_missing_positive(input, n));
}