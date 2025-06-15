#include "Tic_tac_Toe_Biblio.h"



/*
Tic Tac Toe 

*/








int main(void)
{
    int winner = 0; // A number (0, 1 or 2) to specify the winner (0 in case of a draw)
    cell grid[3][3] = 
    {
        { {.empty = true , .content = E}, {.empty = true , .content = E}, {.empty = true , .content = E}, }, 
        { {.empty = true , .content = E}, {.empty = true , .content = E}, {.empty = true , .content = E}, }, 
        { {.empty = true , .content = E}, {.empty = true , .content = E}, {.empty = true , .content = E}, }
    };


    big_centered_text("Tic-Tac-Toe Game");







    display_gird(grid);





    // Player 1 (X) makes the first play
    printf("\nPlayer 1's turn : ");
    printf("Please select a cell :");
    choice c = read_choice();

    int i = c / 10 -1;
    int j = c % 10 -1;

    grid[i][j].content = X;
    grid[i][j].empty = false;



    
    for(int x = 1; x <= 4; x++)
    {
        
        display_gird(grid);
        read_choice2:
        printf("\nPlayer 2's turn : ");
        printf("Please select a cell :");
        c = read_choice();

        i = c / 10 - 1;
        j = c % 10 - 1;

        if ( ! (grid[i][j].empty) )
        {
            printf("\nCell occupied! Please select another cell : ");
            goto read_choice2;
        } else 
        {
            grid[i][j].content = O;
            grid[i][j].empty = false;
            if (check_for_winner(grid, &winner))
            {
                break;
            }
        }

        
        display_gird(grid);


    
        read_choice1:
        printf("\nPlayer 1's turn : ");
        printf("Please select a cell :");
        c = read_choice();

        i = c / 10 - 1;
        j = c % 10 - 1;

        if ( ! (grid[i][j].empty) )
        {
            printf("\nCell occupied! Please select another cell : ");
            goto read_choice1;
        } else 
        {
            grid[i][j].content = X;
            grid[i][j].empty = false;
            if (check_for_winner(grid, &winner))
            {
                break;
            }
        }

    }


    
    display_gird(grid);




    Announce_winner(winner);




    return 0;
}