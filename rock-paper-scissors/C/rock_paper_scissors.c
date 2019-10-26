#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void pc_choice_randomizer(int *choice){
    int i;
    clock_t seed;
    seed = clock();
    srand(seed);
    choice = rand() % 3 + 1;
    return;
}

int main(void){

    unsigned int input, pc_choice;

    do{
        input = 0;

        system(CLEAR);


        printf("\n * * * Rock-Paper-Scissors * * * \n");
        printf("\nEnter [1] to play as rock, enter [2] to play as paper, enter [3] to play as scissor.\n");
        printf("Enter [4] to exit.\n\n");

        scanf("%d", &input);
    }while(input < 1 || input > 4);

    switch(input){
        case 1:
            pc_choice_randomizer;

            printf("\nYour pick: Rock");

            if(pc_choice == 1){
                printf("\nComputer's pick: Rock.");
                printf("\nThe confront has ended in a draw!");
            }

            else if(pc_choice == 2){
                printf("\nComputer's pick: Paper.");
                printf("\nThe computer has won the confront!");
            }

            else{
                printf("\nComputer's pick: Scissor.");
                printf("\nYou won the confront!");
            }

            printf("\n\nPress [ENTER] to exit.\n\n");
            getchar();
            getchar();

            return 0;

        case 2:
            pc_choice_randomizer;

            printf("\nYour pick: Paper");

            if(pc_choice == 1){
                printf("\nComputer's pick: Rock.");
                printf("\nYou won the confront!");
            }

            else if(pc_choice == 2){
                printf("\nComputer's pick: Paper.");
                printf("\nThe confront has ended in a draw!");
            }

            else{
                printf("\nComputer's pick: Scissor.");
                printf("\nThe computer has won the confront!");
            }

            printf("\n\nPress [ENTER] to exit.\n\n");
            getchar();
            getchar();

            return 0;

        case 3:
            pc_choice_randomizer;

            printf("\nYour pick: Scissors");

            if(pc_choice == 1){
                printf("\nComputer's pick: Rock.");
                printf("\nThe computer has won the confront!");
            }

            else if(pc_choice == 2){
                printf("\nComputer's pick: Paper.");
                printf("\nYou won the confront!");
            }

            else{
                printf("\nComputer's pick: Scissor.");
                printf("\nThe confront has ended in a draw!");
            }

            printf("\n\nPress [ENTER] to exit.\n\n");
            getchar();
            getchar();

            return 0;

        case 4: return 0;
    }

    return 0;
}