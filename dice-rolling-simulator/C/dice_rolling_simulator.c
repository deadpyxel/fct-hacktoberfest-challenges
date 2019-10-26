#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int roll(int sides){
    int result;
    clock_t seed;
    seed = clock();
    srand(seed);
    result = rand() % sides + 1;
    return(result);
}

int main(void){

    int sides;

    printf("\n * * * Dice Roller * * * \n");
    printf("\nEnter the number of sides of the dice:\n");
    scanf("%d", &sides);

    int result = roll(sides);

    printf("\nYou rolled %d on a %d sided dice.\n", result, sides);

    printf("Press [ENTER] to exit.");
    getchar();
    getchar();

    return 0;
}