#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    /* ------------------ */
    long credit_card_number = get_long("Credit Card Numer: ");
    long aux_credit_number = credit_card_number;
    int total_elements = 0;
    /*int * result_array;*/
    /* ------------------ */
    while(credit_card_number)
    {
        /*printf("%ld\n", credit_card_number % 10);*/
        credit_card_number /= 10;
        total_elements += 1;
    }
    /* ------------------ */
    int aux_counter;
    int loop_counter = 0;
    int sum = 0;
    int aux_val = 0;
    int data_card[5]; /* ['sum', 'first_digit', 'second_digit'] */
    if (total_elements % 2 == 0)
    {
        aux_counter = 2;
    }
    else
    {
        aux_counter = 1;
    }
    /* ------------------ */
    while(aux_credit_number)
    {
        aux_val = aux_credit_number % 10;
        /* ---------- */
        /*printf("Loop: %i - Total-element: %i - Aux-Val: %i\n", loop_counter,total_elements,aux_val);*/
        if (loop_counter == (total_elements - 1))
        {
            data_card[1] = aux_val;
        }
        if (loop_counter == (total_elements - 2))
        {
            data_card[2] = aux_val;
        }
        /* ---------- */
        if ( aux_counter % 2 == 0)
        {
            sum += aux_val;
            /*printf("Suma N: %i ", aux_val);*/
        } else
        {
            aux_val *= 2;
            while (aux_val)
            {
                sum += aux_val % 10;
                aux_val /= 10;
            }
        }
        aux_counter +=1;
        loop_counter +=1;
        aux_credit_number /= 10;
    }
    /* ['sum', 'first_digit', 'second_digit'] */
    data_card[0] = sum;
    data_card[3] = sum % 10;
    data_card[4] = total_elements;
    /* ------------------ */
    printf("=======================\n");
    printf("Sum: %i\n", data_card[0]);
    printf("First: %i\n", data_card[1]);
    printf("Second: %i\n", data_card[2]);
    printf("Last Digit Sum: %i\n", data_card[3]);
    printf("Total Digit: %i\n", data_card[4]);
    printf("=======================\n");
    if (data_card[4] == 16 && (data_card[1] == 5) && (data_card[2] > 0 && data_card[2] < 6) && data_card[3] == 0)
    {
        printf("MASTERCARD\n");
    } else if ((data_card[4] == 13 || data_card[4] == 16) && data_card[1] == 4  && data_card[3] == 0)
    {
        printf("VISA\n");
    } else if (data_card[4] == 15 && data_card[1] == 3 && (data_card[2] == 4 || data_card[2] == 7))
    {
        printf("AMEX\n");
    } else
    {
        printf("INVALID\n");
    }
}
