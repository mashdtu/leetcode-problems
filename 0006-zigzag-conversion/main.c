#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *convert(char *s, int numRows)
{
    int len = strlen(s);
    char *result = malloc((len + 1) * sizeof(char));
    result[len] = '\0';

    if (numRows == 1)
    {
        memcpy(result, s, len + 1);
        return result;
    }

    int cycle = 2 * (numRows - 1);
    int pos = 0;
    for (int r = 0; r < numRows; r++)
    {
        for (int i = 0; i * cycle + r < len; i++)
        {
            result[pos++] = s[i * cycle + r];
            if (r != 0 && r != numRows - 1 && i * cycle + cycle - r < len)
                result[pos++] = s[i * cycle + cycle - r];
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    printf("%s\n", convert("PAYPALISHIRING", 3)); // "PAHNAPLSIIGYIR"
    printf("%s\n", convert("PAYPALISHIRING", 4)); // "PINALSIGYAHRPI"
    printf("%s\n", convert("A", 1));              // "A"
    return 0;
}
