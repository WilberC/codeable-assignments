#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char return_upper_or_lower(char cip_letter, char input_letter)
{
    if (isupper(input_letter))
    {
        return toupper(cip_letter);
    }
    else
    {
        return tolower(cip_letter);
    }
}

int main(int argc, string argv[])
{
    /* ---------- VALIDATIONS --------------- */
    if (argv[2])
    {
        printf("Error more than 2 arguments\n");
        return 1;
    }
    int key_length = strlen(argv[1]);
    if (key_length != 26)
    {
        printf("Error is less than 26\n");
        return 1;
    }
    int aux_counter = 0;
    for (int x = 0; x < key_length; x++)
    {
        if (!isalpha(argv[1][x]))
        {
            printf("Error is not a letter\n");
            return 1;
        }
        aux_counter = 0;
        for (int y = 0; y < key_length; y++)
        {
            if (argv[1][x] == argv[1][y])
            {
                aux_counter +=1;
                if (aux_counter >= 2)
                {
                    printf("Error repeated: %c = %c\n", argv[1][x] , argv[1][y]);
                    return 1;
                }
            }
        }
    }
    /* ------------------------------------ */
    string plaintext = get_string("plaintext: ");
    int chart_int;
    printf("ciphertext: ");
    for (int i= 0; i < strlen(plaintext); i++)
    {
        chart_int = plaintext[i];
        if (isupper(chart_int))
        {
            chart_int -= 65;
            printf("%c", return_upper_or_lower(argv[1][chart_int], plaintext[i]));
        }
        else if (islower(chart_int))
        {
            chart_int -= 97;
            printf("%c", return_upper_or_lower(argv[1][chart_int], plaintext[i]));
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}