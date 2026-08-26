#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

char *shortestBeautifulSubstring(char *s, int k)
{
    __uint8_t s_len = strlen(s);
    __uint8_t left = 0;
    __uint8_t left_min = 0;
    __uint8_t len_min = s_len + 1;
    int ones = 0;

    for (__uint8_t right = 0; right < s_len; right++)
    {
        ones += (s[right] == '1') ? 1 : 0;

        while (ones > k)
        {
            ones -= (s[left] == '1') ? 1 : 0;
            left++;
        }

        while (ones == k && s[left] == '0')
            left++;

        if (ones == k)
        {
            __uint8_t len_contender = right - left + 1;
            if (len_contender < len_min ||
                (len_contender == len_min && strncmp(s + left, s + left_min, len_contender) < 0))
            {
                left_min = left;
                len_min = len_contender;
            }
        }
    }

    if (len_min > s_len)
    {
        char *result = malloc(1);
        result[0] = '\0';
        return result;
    }

    char *result = malloc(len_min + 1);
    memcpy(result, s + left_min, len_min);
    result[len_min] = '\0';
    return result;
}

int main(int argc, char const *argv[])
{
    struct TestCase
    {
        char *s;
        int k;
        char *expected;
    } testCases[] = {
        {"100011001", 3, "11001"},
        {"1011", 2, "11"},
        {"000", 1, ""},
    };

    int testCount = sizeof(testCases) / sizeof(testCases[0]);
    for (int i = 0; i < testCount; i++)
    {
        char *actual = shortestBeautifulSubstring(testCases[i].s, testCases[i].k);
        printf("Input: s = \"%s\", k = %d\n", testCases[i].s, testCases[i].k);
        printf("Expected: \"%s\"\n", testCases[i].expected);
        printf("Actual: \"%s\"\n\n", actual);
    }

    return 0;
}
