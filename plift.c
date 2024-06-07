#include <stdio.h>
#include <stdlib.h>

// Current version takes a single lift to progress at argv[1]
int main(int argc, char* argv[])
{
    // Opens/Creates a file for logbook of lift
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

    // mlift is incremented by 5 as long as the lifter hits the lift from the day before
    int mlift = atoi(argv[1]);

    // failures are tracked on fcount
    int fcount = 0;

    // Days are incremented for logbook entry
    int daycount = 1;

    while (fcount < 3)
    {
        mlift += 5;
        printf("Today you should lift %i pounds.\n", mlift);

        // YN takes actual lifted weight 
        int YN;
        printf("How much did you lift: ");
        scanf("%i", &YN);

        fprintf(file, "Day #%i, Projected %i, Actual %i, Failed %i times\n", daycount, mlift, YN, fcount);

        // Conditionals compare YN to projected weight
        if (YN >= mlift)
        {
            
            if (YN > mlift)
            {
                // Special case where lifter lifts more, continues from new maximum
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