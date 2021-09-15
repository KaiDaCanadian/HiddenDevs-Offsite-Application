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

// Set up our english constants
const char *ENG_BASE_NUMBERS[] = {
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"
};

const char *ENG_BELOW_TWENTY[] = {
    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

const char *ENG_BELOW_HUNDRED[] = {
    "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

const char *ENG_BASE_MAGNITUDES[] = {
    "thousand", "million", "billion"
};

const char *ENG_HUNDRED = "hundred";
const char *ENG_ZERO = "zero";
const char *ENG_NEGATIVE = "negative";

void get_hundred(int num, std::vector<const char *> words)
{
    if (num >= 100)
    {
        int hundred = (int)(num / pow(10, 2));
        words.push_back(ENG_BASE_NUMBERS[hundred - 1]);
        words.push_back(ENG_HUNDRED);
    }

}

std::string int_to_english(signed int num)
{
    std::string ret;
    std::vector<const char *> words;

    if (num < 0)
        words.push_back(ENG_NEGATIVE);

    num = abs(num);
    size_t num_zeros = floor(log10((double)abs(num)));

    

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

int main(int argc, char **argv)
{
    int num;
    std::cout << "Enter number to convert to English:\n> ";
    std::cin >> num;
    std::string str = int_to_english(num);
    std::cout << num << " in English is '" << str << "'\n";

    return 0;
}
