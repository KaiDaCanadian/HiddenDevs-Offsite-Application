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

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

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

void get_hundred(int num, std::vector<const char *> &words)
{
    int hundreds = num / 100;
    if (hundreds > 0)
    {
        words.push_back(ENG_BELOW_TWENTY[hundreds - 1]);
        words.push_back(ENG_HUNDRED);
    }

    num %= 100;
    int tens = num / 10;
    if (tens > 1)
    {
        words.push_back(ENG_BELOW_HUNDRED[tens - 2]);
        num %= 10;
        if (num > 0)
            words.push_back(ENG_BELOW_TWENTY[num - 1]);
    }
    else
    {
        if (num > 0)
            words.push_back(ENG_BELOW_TWENTY[num - 1]);
    }
}

std::string int_to_english(signed int num)
{
    std::string ret;
    std::vector<const char *> words;

    if (num < 0)
        words.push_back(ENG_NEGATIVE);

    if (num != 0)
    {
        num = abs(num);
        int magnitude = (int)log10((double)num) / 3;
        std::vector<int> magnitudes;

        // Get each magnitude (in reverse)
        while (num != 0)
        {
            magnitudes.push_back(num % 1000);
            num /= 1000;
        }
        // Reverse the vector
        std::reverse(magnitudes.begin(), magnitudes.end());

        for (std::vector<int>::iterator it = magnitudes.begin(); it != magnitudes.end(); ++it)
        {
            --magnitude;
            get_hundred(*it, words);

            if (*it != 0 && magnitude >= 0)
            {
                words.push_back(ENG_BASE_MAGNITUDES[magnitude]);
            }
        }
    }
    else
    {
        words.push_back(ENG_ZERO);
    }

    for (std::vector<const char *>::iterator it = words.begin(); it < words.end(); ++it)
    {
        ret += *it;
        ret.push_back(' ');
    }

    if (ret.length() > 0)
        ret.pop_back();

    ret.shrink_to_fit();
    return ret;
}

void prthelp()
{
    std::cout
        << "IntegerToEnglish by Kai#9999\n"
        << "-h or --help: Displays this help page\n"
        << "-n x: Outputs English number to stdout\n"
        << "(no args): Opens interactive prompt\n";
}

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; ++i)
    {
        std::string v = argv[i];

        if (v == "-h" || v == "--help")
        {
            prthelp();
            return 0;
        }
        else if (v == "-n")
        {
            if (argc != 3)
            {
                std::cout << "Incorrect number of arguments\n";
                return -1;
            }

            int n = std::atoi(argv[i+1]);
            std::string ret = int_to_english(n);
            std::cout << ret;
            return 0;
        }
    }

    /* Interactive prompt (no args) */
    int n;
    std::cout << "Enter number to convert to English:\n> ";
    std::cin >> n;
    std::string str = int_to_english(n);
    std::cout << n << " in English is '" << str << "'\n";

    return 0;
}
