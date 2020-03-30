#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string text = get_string("Text: ");
    /*string text = ".?12:-Alice  ABC";*/
    
    int text_len = strlen(text);
    int cant_letters = 0;
    int cant_words = 0;
    int cant_sentences = 0;
    for (int i = 0; i < text_len; i++)
    {
        if (isalpha(text[i]))
        {
            cant_letters += 1;
        }
        if (isspace(text[i]) && !isspace(text[i-1]))
        {
            cant_words += 1;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            cant_sentences += 1;
        }
    }
    cant_words += 1;
    float L = (cant_letters * 100) / (float) cant_words ;
    float S = (cant_sentences * 100) / (float) cant_words ;
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    int final_index = (int) round(index);
    printf("==========\n");
    printf("Letters: %i\n", cant_letters);
    printf("Words: %i\n", cant_words);
    printf("Sentences: %i\n", cant_sentences);
    printf("==========\n");
    printf("L: %f\n", L);
    printf("S: %f\n", S);
    printf("Index: %f\n", index);
    printf("Index Round: %f\n", final_index);
    printf("==========\n");
    if (final_index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (final_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", final_index);
    }
}
