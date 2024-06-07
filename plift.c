#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *file = fopen("liftlog.csv", "a");
    if (file == NULL)
    {
        return 1;
    }

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
    int fcount = 0;
    int daycount = 1;

    while (fcount < 3)
    {
        mlift += 5;
        printf("Today you should lift %i pounds.\n", mlift);

        int YN;
        printf("How much did you lift: ");
        scanf("%i", &YN);

        fprintf(file, "Day #%i, Projected %i, Actual %i, Failed %i times\n", daycount, mlift, YN, fcount);

        if (YN >= mlift)
        {
            
            if (YN > mlift)
            {
                printf("Excellent! Keep going!\n");
                mlift == YN;
                mlift += 5;
            }
                        
        }
        else if (YN < mlift)
        {
            printf("Try again tomorrow!\n");
            mlift = YN;
            fcount ++;
            printf("Failed %i times\n", fcount);
        }
        printf("Day #%i\n", daycount);
        daycount ++;
    }
    fclose(file);
    return 0;
}