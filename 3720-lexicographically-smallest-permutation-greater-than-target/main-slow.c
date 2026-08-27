#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

// heaps algorithm for permutations
static void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

static void permute(char *s, __uint16_t k, char **result, __uint16_t *count)
{
    if (k == 1)
    {
        result[*count] = strdup(s);
        (*count)++;
        return;
    }

    permute(s, k - 1, result, count);

    for (__uint16_t i = 0; i < k - 1; i++)
    {
        if (k % 2 == 0)
            swap(&s[i], &s[k - 1]);
        else
            swap(&s[0], &s[k - 1]);

        permute(s, k - 1, result, count);
    }
}

char **permutations(char *s, __uint16_t n)
{
    __uint16_t total = 1;
    for (__uint16_t i = 2; i <= n; i++)
        total *= i;

    char **result = malloc(total * sizeof(char *));

    __uint16_t count = 0;
    permute(s, n, result, &count);

    return result;
}
__uint16_t factorial(__uint16_t N)
{
    __uint16_t fact = 1;
    for (size_t i = 1; i <= N; i++)
        fact *= i;

    return fact;
}

char *lexGreaterPermutation(char *s, char *target)
{
    __uint16_t n = strlen(s);

    char *smallest = malloc((n + 1) * sizeof(char));
    smallest[0] = '\0';

    char **p = permutations(s, n);
    for (size_t i = 0; i < factorial(n); i++)
    {
        if (strncmp(p[i], target, n) > 0 &&
            (smallest[0] == '\0' || strncmp(p[i], smallest, n) < 0))
        {
            strcpy(smallest, p[i]);
        }
    }

    return smallest;
}

int main(int argc, char const *argv[])
{
    char s1[] = "abc";
    char target1[] = "bba";
    printf("Input: s = \"%s\", target = \"%s\"\n", s1, target1);
    printf("Output: \"%s\"\nExpected: \"bca\"\n\n",
           lexGreaterPermutation(s1, target1));

    char s2[] = "leet";
    char target2[] = "code";
    printf("Input: s = \"%s\", target = \"%s\"\n", s2, target2);
    printf("Output: \"%s\"\nExpected: \"eelt\"\n\n",
           lexGreaterPermutation(s2, target2));

    char s3[] = "baba";
    char target3[] = "bbaa";
    printf("Input: s = \"%s\", target = \"%s\"\n", s3, target3);
    printf("Output: \"%s\"\nExpected: \"\"\n",
           lexGreaterPermutation(s3, target3));

    return 0;
}
