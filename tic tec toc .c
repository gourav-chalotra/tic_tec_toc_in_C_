// 🤗 Copy and run the game and enjoy🤗
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void structure(char table[])
{
    printf("\n\t|\t|\n");
    printf("   %c    |  %c\t| %c\n", table[0], table[1], table[2]);
    printf("--------|-------|--------\n");
    printf("\t|\t|\n");
    printf("   %c    |  %c\t| %c\n", table[3], table[4], table[5]);
    printf("--------|-------|--------\n");
    printf("\t|\t|\n");
    printf("   %c    |  %c\t| %c\n", table[6], table[7], table[8]);
    printf("\n\n");
}
// Winning conditions 🤗
int checkWinner(char table[], char player, char computer)
{
    if (table[0] == table[1] && table[1] == table[2] && table[0] == player)
    {
        return player;
    }
    else if (table[3] == table[4] && table[4] == table[5] && table[3] == player)
    {
        return player;
    }
    else if (table[6] == table[7] && table[7] == table[8] && table[6] == player)
    {
        return player;
    }
    else if (table[0] == table[3] && table[3] == table[6] && table[0] == player)
    {
        return player;
    }
    else if (table[1] == table[4] && table[4] == table[7] && table[1] == player)
    {
        return player;
    }
    else if (table[2] == table[5] && table[5] == table[8] && table[2] == player)
    {
        return player;
    }
    else if (table[0] == table[4] && table[4] == table[8] && table[0] == player)
    {
        return player;
    }
    else if (table[6] == table[4] && table[4] == table[2] && table[6] == player)
    {
        return player;
    }
    else if (table[0] == table[3] && table[3] == table[6] && table[0] == computer)
    {
        return computer;
    }
    else if (table[1] == table[4] && table[4] == table[7] && table[1] == computer)
    {
        return computer;
    }
    else if (table[2] == table[5] && table[5] == table[8] && table[2] == computer)
    {
        return computer;
    }
    else if (table[0] == table[4] && table[4] == table[8] && table[0] == computer)
    {
        return computer;
    }
    else if (table[6] == table[4] && table[2] == table[4] && table[6] == computer)
    {
        return computer;
    }
    else if (table[0] == table[1] && table[2] == table[1] && table[0] == computer)
    {
        return computer;
    }
    else if (table[3] == table[4] && table[4] == table[5] && table[3] == computer)
    {
        return computer;
    }
    else if (table[6] == table[7] && table[7] == table[8] && table[6] == computer)
    {
        return computer;
    }
    else
    {
        return '-';
    }
}
char restart(char table[])
{
    table[0] = '1';
    table[1] = '2';
    table[2] = '3';
    table[3] = '4';
    table[4] = '5';
    table[5] = '6';
    table[6] = '7';
    table[7] = '8';
    table[8] = '9';
    return 0;
}
int main()
{
    int tern = 0;
    char mood;
    printf("\n\n\t\t\t==>Welcome to Tic Tac Toe<==\n\n");
    printf("\n\t\tDo you Want to play the Tic Tac Toe Game ?\n\n");
    scanf("%c", &mood);

    if (mood == 'N')
    {
        return 0;
    }
    else if (mood == 'Y')
    {
        char table[9];
        table[0] = '1';
        table[1] = '2';
        table[2] = '3';
        table[3] = '4';
        table[4] = '5';
        table[5] = '6';
        table[6] = '7';
        table[7] = '8';
        table[8] = '9';

        int cmChoiceP;
        char player, computer, winHistory = '+';
        printf("choose the Creacter ,press 1(X) and 2(O)");
        scanf("%d", &cmChoiceP);

        if (cmChoiceP == 1)
        {
            player = 'X';
            computer = 'O';
        }
        else if (cmChoiceP == 2)
        {
            player = 'O';
            computer = 'X';
        }
        else
        {
            printf("press right key !");
            return 0;
        }
        printf("\n\t|\t|\n");
        printf("   %c    |  %c\t| %c\n", table[0], table[1], table[2]);
        printf("--------|-------|--------\n");
        printf("\t|\t|\n");
        printf("   %c    |  %c\t| %c\n", table[3], table[4], table[5]);
        printf("--------|-------|--------\n");
        printf("\t|\t|\n");
        printf("   %c    |  %c\t| %c\n", table[6], table[7], table[8]);
        printf("\n\n");
        while (1)
        {
            if (tern == 1)
            {
                srand(time(0));
                int computerTurn = (rand() % (8 - 0 + 1)) + 0;

                if (table[computerTurn] == player || table[computerTurn] == computer)
                {
                    while (table[computerTurn] == player || table[computerTurn] == computer)
                    {
                        srand(time(0));
                        computerTurn = (rand() % (8 - 0 + 1)) + 0; // random number from 0 to 8;

                        if (table[computerTurn] != player && table[computerTurn] != computer)
                        {
                            break;
                        }
                    }
                }
                table[computerTurn] = computer;
                tern = 0;
            }

            else if (tern == 0)
            {
                int playerTurn;
                printf("Enter the postion :- ");
                scanf("%d", &playerTurn);

                if (table[playerTurn - 1] == player || table[playerTurn - 1] == computer)
                {
                    while (table[playerTurn - 1] == player || table[playerTurn - 1] == computer)
                    {
                        printf("postion is alrady filled located please give another location :- ");
                        scanf("%d", &playerTurn);

                        if (table[playerTurn - 1] != player && table[playerTurn - 1] != computer)
                        {
                            break;
                        }
                    }
                    // system("clear");
                }
                table[playerTurn - 1] = player;
                tern = 1;
            }
            structure(table);
            winHistory = checkWinner(table, player, computer);
            if (winHistory == computer)
            {
                int condition;
                printf("\nYou lose !\n");
                exit(0);
            }
            else if (player == winHistory)
            {
                printf("You Win\n\n\n");

                exit(0);
            }
        }
    }
    return 0;
}
