#include "Tic_Tac_Toe_Biblio.h"


/*-----------------------------------------------------------------------------------------------------------------------------------------

                                         C O N S T R U C T I O N    O F    F U N C T I O N S

-----------------------------------------------------------------------------------------------------------------------------------------*/


void print_line(char ch, int length) {
    for (int i = 0; i < length; ++i)
        putchar(ch);
    putchar('\n');
}


void center_text(const char *text, int width) {
    int padding = (width - strlen(text)) / 2;
    for (int i = 0; i < padding; ++i)
        putchar(' ');
    printf("%s\n", text);
}


void big_centered_text(char str[])
{
    printf(".\n");
    
    int width = 148;

    print_line('_', width);
    printf("\n");

    center_text(str, width);

    print_line('_', width);
}





void display_gird(cell grid[3][3])
{
    printf("\n    1   2   3");
    printf("\n 1  %c | %c | %c", grid[0][0].content, grid[0][1].content, grid[0][2].content);
    printf("\n   ___|___|____");
    printf("\n 2  %c | %c | %c", grid[1][0].content, grid[1][1].content, grid[1][2].content);
    printf("\n   ___|___|____");
    printf("\n 3  %c | %c | %c ", grid[2][0].content, grid[2][1].content, grid[2][2].content);
    printf("\n      |   |   ");
}


choice read_choice()
{

    int x;
    scanf("%d", &x);

    switch (x)
    {
    case 11:
    case 12:
    case 13:
    case 21:
    case 22:
    case 23:
    case 31:
    case 32:
    case 33:
        return (choice)x;
        break;
    
    default:
        printf("Invalid Input! Try Again : ");
        return read_choice();
        break;
    }
    
}


bool check_for_winner(cell grid[3][3], int* winner)
{   
    if (grid[0][0].content == grid[0][1].content && grid[0][1].content == grid[0][2].content && grid[0][0].content != E)
    {
        *winner = (grid[0][0].content == X) ? 1 : 2;
        return true;
    }

    if (grid[1][0].content == grid[1][1].content && grid[1][1].content == grid[1][2].content && grid[1][0].content != E)
    {
        *winner = (grid[1][0].content == X) ? 1 : 2;
        return true;
    }

    if (grid[2][0].content == grid[2][1].content && grid[2][1].content == grid[2][2].content && grid[2][0].content != E)
    {
        *winner = (grid[2][0].content == X) ? 1 : 2;
        return true;
    }

    if (grid[0][0].content == grid[1][0].content && grid[1][0].content == grid[2][0].content && grid[0][0].content != E)
    {
        *winner = (grid[0][0].content == X) ? 1 : 2;
        return true;
    }

    if (grid[0][1].content == grid[1][1].content && grid[1][1].content == grid[2][1].content && grid[0][1].content != E)
    {
        *winner = (grid[0][1].content == X) ? 1 : 2;
        return true;
    }

    if (grid[0][2].content == grid[1][2].content && grid[1][2].content == grid[2][2].content && grid[0][2].content != E)
    {
        *winner = (grid[0][2].content == X) ? 1 : 2;
        return true;
    }

    if (grid[0][0].content == grid[1][1].content && grid[1][1].content == grid[2][2].content && grid[0][0].content != E)
    {
        *winner = (grid[0][0].content == X) ? 1 : 2;
        return true;
    }

    if (grid[0][2].content == grid[1][1].content && grid[1][1].content == grid[2][0].content && grid[0][2].content != E)
    {
        *winner = (grid[2][0].content == X) ? 1 : 2;
        return true;
    }

    return false;

}


void Announce_winner(int winner)
{
    switch (winner)
    {
    case 1:
        big_centered_text("Player 1 (X) wins !");
        break;
    case 2:
        big_centered_text("Player 2 (O) wins !");
        break;
    default:
        big_centered_text("Draw");
        break;
    }
}

