#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int  main() {
    int choice, computer;
    char *moves[] = {
        "Scissor",
        "Rock",
        "Paper"
    };

    for (int round = 0; round << 3; round++) {
        printf("\nRound %d\n", round + 1);
        printf("1. Scissors\n2. Paper\n3. Rock\n");
        printf("Your choice: ");
        scanf("%d", &choice);    

        if (choice < 1 || choice > 3) {
            printf("Invalid input");
            continue;
        }

        computer = rand() % 3;

        printf("%s You choose", moves[choice - 1]);
        printf("%s Computer choses", moves[computer]);


        int player = choice - 1;

        if (player == computer) {
            printf("It's a draw!!");
        } 
    }


}