#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int dice1, dice2, total, temp;
    char cmd1;

    srand(time(0));
    dice1 = (rand() %6) + 1;
    dice2 = (rand() %6) + 1;
    total = dice1 + dice2;

    printf("Welcome to craps game. Let me tell you the rules of this game \n");
    printf("1. If the sum of the dice thrown in the first turn is 7 or 11, the player wins. \n");
    printf("2. If the sum of the dice thrown in the first turn is 2, 3, or 12, the player loses. \n");
    printf("3. If the sum of the dice thrown in the first turn is 4, 5, 6, 8, 9, or 10, that number will be the player's target number \n");
    printf("4. If the player rolls the target number again in subsequent turns, they win. However, if they roll a 7 before hitting the target number, they lose. \n");
    printf("Those are the rules. Have a nice game. \n");
    again:
    printf("To start the game please type 's'. If you want exit then press 'e' \n");
    start:
    scanf(" %c", &cmd1);

    if (cmd1=='s')
    {
        printf("Your first numbers are %d and %d which makes %d \n", dice1,dice2,total);

        if(total==7 || total==11){
            printf("You win because you rolled %d in total. Congratulations \n", total);\

            printf("Do you want to play again? y/n \n");
            check:
            scanf(" %c", &cmd1);

            if (cmd1=='y')
            {
                printf("Hello again.\n");
                goto again;
            }
            else if(cmd1=='n'){
                printf("Thank you for trying our game \n");
                exit(0); 
            }
            else{
                printf("Please type 'y' or 'n'. \n");
                goto check;
            }
        }
        else if (total==2 || total==3 || total==12){
            printf("You lose because you rolled %d in total. Do you want to play again? y/n \n", total);
            check2:
            scanf(" %c", &cmd1);

            if (cmd1=='y')
            {
                printf("Hello again.\n");
                goto again;
            }
            else if(cmd1=='n'){
                printf("Thank you for trying our game \n");
                exit(0); 
            }
            else{
                printf("Please type 'y' or 'n'. \n");
                goto check2;
            }
        }
        else{
            printf("You rolled %d in total. This will be your target number. Rolling again until you hit same number. \n", total);
            temp = total;
            do
            {
                srand(time(0));
                dice1 = (rand() %6) + 1;
                dice2 = (rand() %6) + 1;
                total = dice1 + dice2;
                printf("You rolled %d in total. \n", total);
                if (total==7)
                {
                    printf("You lost because you rolled %d. Better luck next time. Do you want to play again? y/n\n", total);
                    check3:
                    scanf(" %c", &cmd1);

                    if (cmd1=='y')
                    {
                        printf("Hello again.\n");
                        goto again;
                    }
                    else if(cmd1=='n'){
                        printf("Thank you for trying our game \n");
                        exit(0); 
                    }
                    else{
                        printf("Please type 'y' or 'n'. \n");
                        goto check3;
                    }
                }
            } while (temp == total);
            printf("You win because you rolled %d in total again. Congratulations. Do you want to play again? y/n \n", total);
                    check4:
                    scanf(" %c", &cmd1);

                    if (cmd1=='y')
                    {
                        printf("Hello again.\n");
                        goto again;
                    }
                    else if(cmd1=='n'){
                        printf("Thank you for trying our game \n");
                        exit(0); 
                    }
                    else{
                        printf("Please type 'y' or 'n'. \n");
                        goto check4;
                    }
        }
    }

    else if (cmd1=='e')
    {
        printf("Thank you for trying our game \n");
        exit(0);  
    }
    else{
        printf("Please type 's' or 'e'. \n");
        goto start;
    }  
}