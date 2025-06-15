#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>



/*-----------------------------------------------------------------------------------------------------------------------------------------

                                           D E F I N I T I O N    O F    S T R U C T U R E S

-----------------------------------------------------------------------------------------------------------------------------------------*/

typedef enum input
{
    X = 'X',
    O = 'O', 
    E = ' '
} input;


typedef enum choice
{
    c11 = 11, 
    c12 = 12, 
    c13 = 13, 

    c21 = 21, 
    c22 = 22, 
    c23 = 23, 

    c31 = 31, 
    c32 = 32, 
    c33 = 33
} choice;




typedef struct cell
{
    input content;
    bool empty;
} cell;








/*-----------------------------------------------------------------------------------------------------------------------------------------

                                            D E F I N I T I O N    O F    F U N C T I O N S

-----------------------------------------------------------------------------------------------------------------------------------------*/

void print_line(char ch, int length);

void center_text(const char *text, int width);

void big_centered_text(char str[]);

void display_gird(cell grid[3][3]);

choice read_choice();

bool check_for_winner(cell grid[3][3], int* winner);

void Announce_winner(int winner);
