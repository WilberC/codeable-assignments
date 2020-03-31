#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int get_alfabet_number(alfabet_number, key)
{
    return (alfabet_number + key) % 26;
}

int main(int argc, string argv[])
{
    if (argv[2])
    {
        printf("Error\n");
        return 1;
    }
    /* Get cli variable */
    int key_length = strlen(argv[1]);
    for (int x = 0; x < key_length; x++)
    {
        if (isalpha(argv[1][x]))
        {
            printf("Error\n");
            return 1;
        }
    }
    int key = atoi(argv[1]);
    /* get plaint text */
    string text = get_string("plaintext: ");
    /* Extra variables */
    int text_len = strlen(text);
    int aux_char_int;
    /* ----------------------- */
    printf("ciphertext: ");
    for (int i = 0; i < text_len; i++)
    {
        if (islower(text[i]))
        {
            aux_char_int = get_alfabet_number((text[i] - 97), key);
            aux_char_int += 97;
            printf("%c", aux_char_int);
            
        }
        else if (isupper(text[i]))
        {
            aux_char_int = get_alfabet_number((text[i] - 65), key);
            aux_char_int += 65;
            printf("%c", aux_char_int);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
