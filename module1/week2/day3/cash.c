#include <cs50.h>
#include <stdio.h>
#include <math.h>

const int quarter = 25;
const int dimes = 10;
const int nickels = 5;
const int pennies = 1;

int main(void)
{
    float owed = 0.0;
    while (!owed || owed < 0)
    {
        owed = get_float("Change owed: ");
        /* Get Int part and Decimal part */
        int int_owed = (int)owed;
        float dec_owed = owed - int_owed;
        /* Change total to Coins */
        float owed_cents = (int_owed * 100) + ((int)round((dec_owed * 100)));
        /* Get coins needed */
        int total_coins = 0;
        int auxiliar_owed = (int) owed_cents;
        /* -------------------------------------------- */
        /* Quarters */
        int cant_quarter = (auxiliar_owed / quarter);
        auxiliar_owed -= (cant_quarter * quarter);
        /* Dimes */
        int cant_dimes = (auxiliar_owed / dimes);
        auxiliar_owed -= (cant_dimes * dimes);
        /* Nickels */
        int cant_nickels = (auxiliar_owed / nickels);
        auxiliar_owed -= (cant_nickels * nickels);
        /* Pennies */
        int cant_pennies = (auxiliar_owed / pennies);
        auxiliar_owed -= (cant_pennies * cant_pennies);
        /* Total coins */
        /*printf("AuxOwed : %i\n", auxiliar_owed);
        printf("25 : %i\n", cant_quarter);
        printf("10 : %i\n", cant_dimes);
        printf("05 : %i\n", cant_nickels);
        printf("01 : %i\n", cant_pennies);*/
        total_coins += cant_quarter;
        total_coins += cant_dimes;
        total_coins += cant_nickels;
        total_coins += cant_pennies;
        /* -------------------------------------------- */
        printf("%i\n", total_coins);
    }
}
