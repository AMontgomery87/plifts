#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./plift starting-lift-weight\n");
        return 1;
    }

    if (argc > 2)
    {
        printf("Usage: ./plift takes only one input\n");
        return 2;
    }

    int mlift = atoi(argv[1]);
    int tlift = mlift + 5;
    int wlift = tlift + 5;

    printf("Today you should lift %i pounds.\n", tlift);

    int YN = get_int("How much did you lift?\n");

    if (YN == tlift)
    {
        printf("Tomorrow you should lift %i\n", wlift);
        return 0;
    }
    else
    {
        printf("Try again tomorrow!\n");
        return 0;
    }
}