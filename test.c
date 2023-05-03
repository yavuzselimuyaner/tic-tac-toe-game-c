#include <stdio.h>
char a[3][3];
void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            a[i][j] = ' ';
        }
    }
}
void printgame()
{
    printf("%c  |  %c  |   %c\n",a[0][0],a[0][1],a[0][2]);
    printf("_____________\n");
    printf("%c  |  %c  |  %c\n",a[1][0],a[1][1],a[1][2]);
    printf("______________\n");
    printf("%c  |  %c  |  %c\n",a[2][0],a[2][1],a[2][2]);
    printf("_______________\n");


}
int checkwin(char symbol)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        if(a[i][0]==symbol && a[i][1]==symbol && a[i][2]==symbol ){

            return 1;
        }
    }
    for(j=0;j<3;j++)
    {
        if(a[0][j]==symbol && a[1][j]==symbol && a[2][j]==symbol)
        {
            return 1;

        } 
    }
    if(a[0][0]==symbol && a[1][1]==symbol && a[2][2]==symbol){
        return 1;
    }
    return 0;
}
int checkfull(){
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (a[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    initialize_board();
    int row,col;
    char symbol;
    int player=1;
    while(1)
    {
         player = (player % 2) ? 1 : 2;

        
        symbol = (player == 1) ? 'X' : 'O';

        // Print the board
        printf("Player %d, enter row (0-2) and column (0-2) to place %c: ", player, symbol);
        scanf("%d %d", &row, &col);
        player++;
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        if (a[row][col] != ' ') {
            printf("That cell is already full. Try again.\n");
            continue;
        }
       a[row][col] = symbol;
        printgame();

    if (checkwin(symbol)) {
        printf("Player %d wins!\n", player);
        break;
    }

    if (checkfull()) {
        printf("It's a draw!\n");
        break;
    }

    }
    
    printgame();
    return 0;
}