#include <cs50.h>
#include <stdio.h>

//Ik heb een aantal printf's laten staan, zo kan je zien hoe mijn denkwijze is geweest bij het oplossen van dit probleem.

int main(void)
{
    long ccnumber; //Variabele die ik kan gebruiken om andere variabelen aan het ingevoerde creditcard nummer gelijk te stellen.
    do
    {
        ccnumber = get_long("Number: "); //Input van de gebruiker
    }
    while (ccnumber < 0);
    long number = ccnumber;
    int sum = 0;
    while (number)
    {
        int b = number % 10;
        //printf("%i\n", b);
        number /= 100;
        sum = sum + b;
    }

    //printf("Second part\n");
    number = ccnumber;
    number /= 10;
    int sum2 = 0;
    while (number)
    {
        int x = number % 10;
        int y = x * 2;
        int z = 0;
        int a = 0;
        // Indien y groter is dan 10 en dus uit twee cijfers bestaat, moeten deze worden opgedeeld volgens Luhn's algoritme
        if (y >= 10)
        {
            z = y % 10;
            //printf("Waarde van Z: %i\n", z);
            a = y /= 10;
            //printf("Waarde van A: %i\n", a);
            sum2 = sum2 + a + z;
            //printf("%i\n", x);
            number /= 100;
        }
        else
        {
            sum2 = sum2 + y;
            //printf("%i\n", x);
            number /= 100;
        }
    }
    // sum = Som van getallen die niet zijn vermenigvuldigd met twee
    // sum2 = Som van de getallen die vermenigvuldigd zijn met twee
    int sum3 = sum + sum2;
    if ((sum3 % 10) == 0)
    {
        //printf("VALID\n");
        number = ccnumber;
        //Variabele nummer == eerste getal van het nummer
        long nummer = number;
        while (nummer >= 10)
        {
            nummer = nummer / 10;
        }
        //printf("First digit: %li\n", nummer);
        //Variabele nummer2 == eerste twee getallen van het nummer
        long nummer2 = number;
        while (nummer2 >= 100)
        {
            nummer2 = nummer2 / 10;
        }
        //printf("First two digits: %li\n", nummer2);
        //Tellen van het aantal cijfers waaruit het nummer bestaat
        int count = 0;
        while (number > 0)
        {
            number /= 10;
            count++;
        }
        //printf("Number of digits: %i\n", count);
        //Bepalen bij welke bank het nummer hoort.
        if (count == 15 && (nummer2 == 34 || nummer2 == 37))
        {
            printf("AMEX\n");
        }
        else if (count == 13 && nummer == 4)
        {
            printf("VISA\n");
        }
        else if (count == 16)
        {
            if (nummer == 4)
            {
                printf("VISA\n");
            }
            else if (nummer2 == 51 || nummer2 == 52 || nummer2 == 53 || nummer2 == 54 || nummer2 == 55)
            {
                printf("MASTERCARD\n");
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }
}