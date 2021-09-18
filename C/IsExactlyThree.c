// https://edabit.com/challenge/CMFyi8tgCucNSoRo7
// Solution by Kai#9999

/*
You are given a number n. Determine whether n has exactly 3 divisors or not.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_divisor_count(int num, int verbose)
{
    if (verbose)
        printf("%d\n", 1);
    
    if (num == 1)
        return 1;
    
    // starting at 2; num will always divide by 1 and itself
    int count = 2;
    for (int i = 2; i <= num / 2; ++i)
    {
        if (num % i == 0)
        {
            ++count;
            if (verbose)
                printf("%d\n", i);
        };
    }

    if (verbose)
        printf("%d\n", num);

    return count;
}

void prthelp()
{
    printf("IntegerToEnglish by Kai#9999\n");
    printf("-h or --help: Displays this help page\n");
    printf("-n x: Outputs number of divisors\n");
}

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; ++i)
    {
        char *v = argv[i];

        if (!strcmp(v, "-h") || !strcmp(v, "--help"))
        {
            prthelp();
            return 0;
        }
        else if (!strcmp(v, "-n"))
        {
            if (argc != 3)
            {
                printf("Incorrect number of arguments\n");
                return -1;
            }

            int n = atoi(argv[i + 1]);
            int ret = get_divisor_count(n, 0);
            
            printf("Number of divisors: %d\n", ret);
            printf("Divisors:\n");
            get_divisor_count(n, 1); /* I'm incredibly lazy and just want the C programmer role */
            
            if (ret == 3)
            {
                printf("Yes, there are three divisors!");
            }
            else
            {
                printf("No, there are not three divisors.");
            }

            return 0;
        }
    }

    prthelp();

    return 0;
}
