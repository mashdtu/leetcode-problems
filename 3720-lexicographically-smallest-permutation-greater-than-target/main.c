#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

char *lexSort(char *res, char *tar, int *freq, int i)
{
    for (size_t j = tar[i] - 'a' + 1; j < 26; j++)
    {
        if (freq[j] > 0)
        {
            res[i] = j + 'a';
            freq[j]--;
            i++;
            break;
        }
    }

    for (size_t j = 0; j < 26; j++)
    {
        while (freq[j] > 0)
        {
            res[i] = j + 'a';
            freq[j]--;
            i++;
        }
    }

    if (strcmp(res, tar) > 0)
        return res;

    res[0] = '\0';
    return res;
}

char *lexGreaterPermutation(char *s, char *target)
{
    int n = strlen(s);

    char *result = malloc((n + 1) * sizeof(char));
    result[strlen(s)] = '\0';

    int *freq = calloc(26, sizeof(*freq));
    for (size_t i = 0; i < n; i++)
        freq[s[i] - 'a']++;

    int i = 0;
    for (; i < n; i++)
    {
        if (freq[target[i] - 'a'] > 0)
        {
            result[i] = target[i];
            freq[target[i] - 'a']--;
        }
        else
        {
            break;
        }
    }

    if (i < n)
    {
        for (int letter = target[i] - 'a' + 1; letter < 26; letter++)
        {
            if (freq[letter] > 0)
                return lexSort(result, target, freq, i);
        }
    }

    for (i--; i >= 0; i--)
    {
        freq[result[i] - 'a']++;
        for (int letter = result[i] - 'a' + 1; letter < 26; letter++)
        {
            if (freq[letter] > 0)
                return lexSort(result, target, freq, i);
        }
    }

    return "";
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

    char s4[] = "ab";
    char target4[] = "ab";
    printf("Input: s = \"%s\", target = \"%s\"\n", s4, target4);
    printf("Output: \"%s\"\nExpected: \"ba\"\n",
           lexGreaterPermutation(s4, target4));

    char s5[] = "aab";
    char target5[] = "abb";
    printf("Input: s = \"%s\", target = \"%s\"\n", s5, target5);
    printf("Output: \"%s\"\nExpected: \"baa\"\n",
           lexGreaterPermutation(s5, target5));

    return 0;
}
