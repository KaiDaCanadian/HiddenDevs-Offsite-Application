// https://www.cprogramming.com/challenges/dectobin.html
// Solution by Kai#9999

/*
Write a program that accepts a base ten (non-fractional) number at the command line and outputs the binary representation of that number.

Sample input is
dectobin 120
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Returns array of bits
int *dectobin(int num)
{
    size_t n_bits = (int)(log2((double)num) + 1);
    int *bits = (int *)calloc(n_bits, sizeof(int));
    
    // Get bits using repeated division
    int i = 0;
    while (num != 0)
    {
        bits[i++] = num % 2;
        num /= 2;
    }

    // Bits are in reverse order, reverse the array
    for (int l = 0, h = n_bits - 1; l < h; ++l, --h)
    {
        int t = bits[l];
        bits[l] = bits[h];
        bits[h] = t;
    }

    return bits;
}

void prthelp()
{
    printf("DecimalToBinary by Kai#9999\n");
    printf("-h or --help: Displays this help page\n");
    printf("-n x: Outputs binary string to stdout\n");
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
                printf("Incorrect number of arguments");
                return -1;
            }

            int n = atoi(argv[i + 1]);
            int *bits = dectobin(n);
            size_t n_bits = (int)(log2((double)n) + 1);

            for (int i = 0; i < n_bits; ++i)
            {
                printf("%d", bits[i]);
            }

            return 0;
        }
    }

    prthelp();

    return 0;
}
