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

const char *ENG_BASE_NUMBERS_[] = {
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"
};

const char *ENG_BELOW_TWENTY[] = {
    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

const char *ENG_BELOW_HUNDRED[] = {
    "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

const char *ENG_BASE_MAGNITUDES[] = {
    "hundred", "thousand", "million", "billion"
};

const char *ENG_ZERO = "zero";
const char *ENG_NEGATIVE = "negative";

std::string int_to_english(signed int num)
{
    std::string ret;
    std::vector<const char *> words;
    std::string num_s;
    char *num_c;

    num_c = (char *)malloc(sizeof(char) * 500);
    if (!num_c)
        exit(-1);
    sprintf(num_c, "%d", abs(num));
    num_s = std::string(num_c);
    free(num_c);
    
    if (num < 0)
        words.push_back(ENG_NEGATIVE);

    for (std::string::iterator it = num_s.begin(); it != num_s.end(); ++it)
    {
        std::cout << *it << "\n";
    }

    for (std::vector<const char *>::iterator it = words.begin(); it != words.end(); ++it)
    {
        ret += *it;
        ret.push_back(' ');
    }

    if (ret.length() > 0)
        ret.pop_back();

    ret.shrink_to_fit();
    return ret;
}

int main(int argc, char **argv)
{
    int num;
    std::cout << "Enter number to convert to English:\n> ";
    std::cin >> num;
    std::string str = int_to_english(num);
    std::cout << num << " in English is '" << str << "'\n";

    return 0;
}
