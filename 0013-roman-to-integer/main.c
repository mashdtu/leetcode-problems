#include <stdio.h>
#include <string.h>

int integerFactors(char c)
{
    switch (c)
    {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
}

int romanToInt(char *s)
{
    int sum = 0;
    for (__uint32_t i = 0; i < strlen(s); i++)
    {
        sum += (i + 1 < strlen(s) && integerFactors(s[i]) < integerFactors(s[i + 1]))
            ? - integerFactors(s[i]) : integerFactors(s[i]);
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", romanToInt("III"));     // 3
    printf("%d\n", romanToInt("LVIII"));   // 58
    printf("%d\n", romanToInt("MCMXCIV")); // 1994
    return 0;
}
