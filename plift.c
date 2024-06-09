#include <stdio.h>
#include <stdlib.h>

// I'm only tracking 3 lifts for this program currently, but this avoids redundancy in code later
typedef struct 
{
    const char* name;
    int weight;
    int fail_count;
} Lift;

int main(int argc, char* argv[])
{
    // This makes a logbook giving day, lift, weight, and number of times failed at that lift into an external csv
    // file.
    FILE *file = fopen("liftlog.csv", "a");
    if (file == NULL)
    {
        return 1;
    }

    // I'm only tracking three currently
    const int num_lifts = 3;

    if (argc != num_lifts + 1)
    {
        printf("Usage: ./plift squat-weight press-weight deadlift-weight\n");
        return 2;
    }

    // Defines the three lifts performed, lift name was a const, lift weight comes from CLI,
    // and fail count is tracked individually
    Lift lifts[num_lifts];
    lifts[0].name = "Squat";
    lifts[0].weight = atoi(argv[1]);
    lifts[0].fail_count = 0;

    lifts[1].name = "Overhead Press";
    lifts[1].weight = atoi(argv[2]);
    lifts[1].fail_count = 0;

    lifts[2].name = "Deadlift";
    lifts[2].weight = atoi(argv[3]);
    lifts[2].fail_count = 0;

    // Days are counted just for the logbook
    int daycount = 1;

    while (lifts[0].fail_count < 3 && lifts[1].fail_count < 3 && lifts[2].fail_count < 3)
    {
        for (int i = 0; i < num_lifts; i++)
        {
            // Increments weight for following day by 5 if lift is the same
            if (lifts[i].fail_count >= 3)
                continue;

            lifts[i].weight += 5;
            printf("Today you should lift %i pounds for %s.\n", lifts[i].weight, lifts[i].name);

            // Determines the exact weight lifted and then matches to projected weight
            int YN;
            printf("How much did you lift for %s: ", lifts[i].name);
            scanf("%i", &YN);

            // Passes data to the logbook
            fprintf(file, "Day #%i, %s, Projected %i, Actual %i\n", daycount, lifts[i].name, lifts[i].weight, YN);

            if (YN >= lifts[i].weight)
            {
                // As long as the lifter lifts greater than or equal to the projected
                // Continue adding 5
                lifts[i].weight = YN;
            }
            else
            {
                // If lifter fails to meet the expected working weight, it prompts to try again
                // with the same working weight as before, increments fail count, and declares 
                // number of times a particular lift has failed
                printf("Try again tomorrow!\n");
                lifts[i].weight = YN;
                lifts[i].fail_count++;
            }
        }

        // Increments daycount and prints information in terminal
        daycount++;
        printf("Day #%i\n", daycount);
    }

    fclose(file);
    return 0;
}
