// https://www.cprogramming.com/challenges/integer-to-english.html
// Solution by Kai#9999

/*
Integer to english number conversion
Write a program that takes an integer and displays the English name of that value.

You should support both positive and negative numbers, in the range supported by a 32-bit integer (approximately -2 billion to 2 billion).

Examples:

10 -> ten
121 -> one hundred twenty one
1032 -> one thousand thirty two
11043 -> eleven thousand forty three
1200000 -> one million two hundred thousand
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Set up our English constants
const char *ENG_BELOW_TWENTY[] = {
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};
const char *ENG_BELOW_HUNDRED[] = {
    "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"
};
const char *ENG_BASE_MAGNITUDES[] = {
    "thousand", "million", "billion", "trillion", "quadrillion", "quintillion"
};
const char *ENG_HUNDRED = "hundred";
const char *ENG_ZERO = "zero";
const char *ENG_NEGATIVE = "negative";

void wpush(char **words, int *n_words, const char *string)
{
    words[(*n_words)++] = (char *)string;
}

void get_hundred(int num, char **words, int *n_words)
{
    int hundreds = num / 100;
    if (hundreds > 0)
    {
        wpush(words, n_words, ENG_BELOW_TWENTY[hundreds - 1]);
        wpush(words, n_words, ENG_HUNDRED);
    }

    num %= 100;
    int tens = num / 10;
    if (tens > 1)
    {
        wpush(words, n_words, ENG_BELOW_HUNDRED[tens - 2]);
        num %= 10;
        if (num > 0)
            wpush(words, n_words, ENG_BELOW_TWENTY[num - 1]);
    }
    else
    {
        if (num > 0)
            wpush(words, n_words, ENG_BELOW_TWENTY[num - 1]);
    }
}

const char *int_to_english(signed int num)
{
    int magnitude = (int)log10((double)abs(num)) / 3;
    char *ret = (char *)calloc(1000, sizeof(char));
    char **words = (char **)calloc(1 + ((magnitude + 1) * 4), sizeof(char *));
    int n_words = 0;

    if (num < 0)
        wpush(words, &n_words, ENG_NEGATIVE);

    if (num != 0)
    {
        num = abs(num);
        int *magnitudes = (int *)calloc(magnitude + 1, sizeof(int));
        int n_magnitudes = 0;

        // Get each magnitude in reverse
        while (num != 0)
        {
            magnitudes[n_magnitudes++] = num % 1000;
            num /= 1000;
        }

        // Traverse backwards
        for (int i = 0; i < n_magnitudes; ++i)
        {
            --magnitude;
            int j = n_magnitudes - 1 - i;
            get_hundred(magnitudes[j], words, &n_words);

            if (magnitudes[j] != 0 && magnitude >= 0)
            {
                wpush(words, &n_words, ENG_BASE_MAGNITUDES[magnitude]);
            }
        }
    }
    else
    {
        wpush(words, &n_words, ENG_ZERO);
    }

    // Compile words list into return string
    for (int i = 0; i < n_words; ++i)
    {
        strcat(ret, words[i]);
        strcat(ret, " ");
    }

    size_t len = strlen(ret);
    if (len > 0)
        ret[len - 1] = '\0';

    ret = (char *)realloc(ret, len * sizeof(char));
    return (const char *)ret;
}

void prthelp()
{
    printf("IntegerToEnglish by Kai#9999\n");
    printf("-h or --help: Displays this help page\n");
    printf("-n x: Outputs English number to stdout\n");
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
            const char *ret = int_to_english(n);
            printf("%s", ret);
            return 0;
        }
    }

    prthelp();

    return 0;
}
