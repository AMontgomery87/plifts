#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
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
    //int tlift = mlift + 5;
    //int wlift = tlift + 5;
    int fcount = 0;

    while (fcount < 3)
    {
        printf("Today you should lift %i pounds.\n", mlift += 5);

        int YN;
        printf("How much did you lift: ");
        scanf("%i", &YN);

        if (YN >= mlift)
        {
            printf("Tomorrow you should lift %i\n", mlift + 5);
            if (YN > mlift)
            {
                mlift = YN;
                printf("Excellent! Keep going!\n");
                printf("mlift is %i\n", mlift);
            }            
        }
        else if (YN < mlift)
        {
            printf("Try again tomorrow!\n");
            mlift -= 5;
            fcount += 1;
            printf("Failed %i times\n", fcount);
        }
    }
    return 0;
}