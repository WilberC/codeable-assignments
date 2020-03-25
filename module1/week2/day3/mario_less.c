#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cant_rows = 0;
    while (!cant_rows || cant_rows < 1 || cant_rows > 8)
    {
        cant_rows = get_int("How many rows do you want? (min=1,max=8) : ");
    }
    bool print_space = true;
    for (int i = 1; i <= cant_rows; i++) 
    {
        for (int symbol = 0; symbol < i; symbol++) 
        {
            if (print_space == true) 
            {
                for (int space = cant_rows; space > i; space--) 
                {
                    printf(" ");
                }
                print_space = false;
            }
            printf("#");
        }
        printf("\n");
        print_space = true;
    }
}
