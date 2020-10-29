#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Hoogte die ingevoerd wordt door de gebruiker
    int y;
    // Aantal spaties
    int j;
    // Aantal #
    int n;
    // Aantal rijen
    int i;
    do
    {
        y = get_int("Height: ");
    }
    //Alleen doorgaan indien er een getal tussen de 1 en 8 is ingevoerd.
    while (y < 1 || y > 8);

    // For loop voor het aantal rijen
    for (i = 1; i <= y; i++)
    {

        //For loop voor bepalen van aantal spaties
        for(j = (y - i); j > 0; j--)
        {
            printf(" ");
        }

        //For loop voor bepalen van aantal #
        for(n = 1; n <= i; n ++)
        {
            printf("#");
        }

        // Gat tussen de twee piramides
        printf("  ");

        //For loop voor de 'left-aligned' piramide
        //Eerste loop zorgt dat de eerste rij van # na het gat wordt weergegeven.
        for(int a = 1; a <= i; a++)
        {
            printf("#");
            //Deze loop zorgt voor het aantal # dat na de eerste rij van deze halve piramide staat.
            for(int b = i; b < a; b++)
            {
                printf("#");
            }
        }

        //Enter
        printf("\n");
    }
}