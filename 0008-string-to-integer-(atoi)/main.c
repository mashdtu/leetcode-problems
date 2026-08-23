#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int myAtoi(char *s)
{
    size_t start = 0, end = strlen(s);
    while (start < end && s[start] == ' ')
        start++;
    while (end > start && s[end - 1] == ' ')
        end--;
    char *trimmed = malloc((end - start + 1) * sizeof(char));
    memcpy(trimmed, s + start, end - start);
    trimmed[end - start] = '\0';
    s = trimmed;

    int sign = 1;
    if (s[0] == '-')
    {
        sign = -1;
        s++;
    }
    else if (s[0] == '+')
        s++;

    int result = 0;
    for (size_t i = 0; i < strlen(s); i++)
    {
        char c = s[i];
        if (c < '0' || c > '9')
            return result * sign;

        int digit = c - '0';
        if (result > (INT_MAX - digit) / 10)
            return sign == -1 ? INT_MIN : INT_MAX;
        result = result * 10 + digit;
    }
    return result * sign;
}

int main(int argc, char const *argv[])
{
    printf("42: %d\n", myAtoi("42"));
    printf("-042: %d\n", myAtoi("-042"));
    printf("-91283472332: %d\n", myAtoi("-91283472332"));
    return 0;
}
