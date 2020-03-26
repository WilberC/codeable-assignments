#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    /* ------------------ */
    long credit_card_number = get_long("Credit Card Numer: ");
    long auxiliar_credit_number = credit_card_number;
    int length_first_array = 0;
    int length_second_array = 0;
    int total_elements = 0;
    /* ------------------ */
    while(credit_card_number)
    {
        credit_card_number /= 10;
        if (total_elements % 2 == 0)
        {
            length_second_array += 1;
        } else
        {
            length_first_array += 1;
        }
        total_elements += 1;
    }
    /* ------------------ */
    int by_two[length_first_array];
    int by_one[length_second_array];
    int auxiliar_bytwo = 0;
    int auxiliar_byone = 0;
    int auxiliar_counter_par_impar = 0;
    int digit = 0;
    /* ------------------ */
    /*printf("**************************\n");*/
    while(auxiliar_credit_number)
    {
        /*printf("%ld\n", auxiliar_credit_number % 10);*/
        digit = auxiliar_credit_number % 10;
        if (auxiliar_counter_par_impar % 2 == 0)
        {
            by_one[auxiliar_byone] = digit;
            /*printf("%d-", digit);*/
            auxiliar_byone += 1;
        } else
        {
            by_two[auxiliar_bytwo] = digit;
            auxiliar_bytwo += 1;
        }
        auxiliar_counter_par_impar += 1;
        auxiliar_credit_number /= 10;
    }
    /*printf("\n");*/
    /*printf("**************************\n");*/
    /* ------------------ */
    /*printf("-----------------\n");
    printf("Total elementos : %i\n", total_elements);
    printf("Dimension 1 : %i\n", length_first_array);
    printf("Dimension 2 : %i\n", length_second_array);
    printf("-----------------\n");*/
    /* ------------------ */
    int sum_by_one = 0;
    int sum_by_two = 0;
    int auxiliar_value = 0;
    for(int one = 0; one < length_first_array; one++) 
    {
        /*printf("%d-", (by_one[one]));*/
        sum_by_one += by_one[one];
    }
    /*printf("\n");
    printf("-----------------\n");*/
    for(int two = 0; two < length_second_array; two++) 
    {
        /*printf("%d-", by_two[two]);*/
        auxiliar_value = (by_two[two] * 2);
        while(auxiliar_value)
        {
            sum_by_two += auxiliar_value % 10;
            auxiliar_value /= 10;
        }
    }
    /*printf("\n");
    printf("-----------------\n");*/
    /* ------------------ */
    int checksum = sum_by_two + sum_by_one;
    /*printf("===========================\n");
    printf("Suma Total : %i\n", checksum);
    printf("===========================\n");*/
    int last_digit = checksum % 10;
    int first_digit = by_two[length_second_array - 1];
    int second_digit = by_one[length_first_array - 1];
    printf("===========================\n");
    printf("t : %i\n", checksum);
    printf("1 : %i\n", first_digit);
    printf("2 : %i\n", second_digit);
    printf("===========================\n");
    if (last_digit != 0)
    {
        printf("INVALID\n");
    } else if(total_elements == 15 && first_digit == 3 && (second_digit == 4 || second_digit == 7))
    {
        printf("AMEX\n");
    } else if(total_elements == 16 && first_digit == 5 && (second_digit == 1 || second_digit == 2 || second_digit == 3 || second_digit == 4 ||       second_digit == 5))
    {
        printf("MASTERCARD\n");
    } else if((total_elements == 13 || total_elements == 16) && first_digit == 4)
    {
        printf("VISA\n");
    } else
    {
        printf("INVALID\n");
    }
}
