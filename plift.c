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
            fprintf(file, "Day #%i, Projected %i, Actual %i\n", daycount, mlift, YN);
            if (YN > mlift)
            {
                fprintf(file, "Day #%i, Projected %i, Actual %i\n", daycount, mlift, YN);
                printf("Excellent! Keep going!\n");
                mlift == YN;
                mlift += 5;
                daycount ++;

            }            
        }
        else if (YN < mlift)
        {
            fprintf(file, "Day #%i, Projected %i, Actual %i\n", daycount, mlift, YN);
            printf("Try again tomorrow!\n");
            mlift = YN;
            fcount ++;
            printf("Failed %i times\n", fcount);
            daycount ++;
        }
        
        printf("Day #%i\n", daycount);
    }
    fclose(file);
    return 0;
}