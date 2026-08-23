#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define STR_MAX "2147483647"
#define INT_MIN -2147483648

void reverse_string(char *str)
{
    if (strlen(str) > 0)
    {
        __uint8_t i, j, size;
        size = strlen(str);

        j = 0;
        for (i = size - 1; i > j; i--)
        {
            char temp = str[j];
            str[j] = str[i];
            str[i] = temp;
            j++;
        }
    }
}

int reverse(int x)
{
    bool isNegative = false;
    if (x < 0)
        isNegative = true;

    if (x == INT_MIN)
        return 0;

    x = abs(x);

    char *str = malloc(10 * sizeof(char));
    sprintf(str, "%d", x);

    reverse_string(str);

    int overflow = strlen(str) > 10 || (strlen(str) == 10 && strcmp(str, STR_MAX) > 0);
    if (overflow)
    {
        free(str);
        return 0;
    }

    x = atoi(str);
    free(str);

    x *= isNegative ? -1 : 1;
    return x;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", reverse(123));  // 321
    printf("%d\n", reverse(-123)); // -321
    printf("%d\n", reverse(120));  // 21
    return 0;
}
