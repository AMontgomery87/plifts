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
                daycount ++;

            }            
        }
        else if (YN < mlift)
        {
            printf("Try again tomorrow!\n");
            mlift -= 5;
            fcount += 1;
            printf("Failed %i times\n", fcount);
            daycount ++;
        }
        fprintf(file, "Day #%i, Projected %i, Actual %i\n", daycount, mlift, YN);
        printf("Day #%i\n", daycount);
    }
    fclose(file);
    return 0;
}