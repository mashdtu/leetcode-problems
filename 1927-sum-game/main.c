#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

bool sumGame(char *num)
{
    size_t n = strlen(num);
    int32_t firstHalfSum = 0, secondHalfSum = 0, firstHalfQuestions = 0, secondHalfQuestions = 0;

    for (size_t i = 0; i < n / 2; i++)
    {
        if (num[i] == '?')
            firstHalfQuestions++;
        else
            firstHalfSum += num[i] - '0';
    }
    for (size_t i = n / 2; i < n; i++)
    {
        if (num[i] == '?')
            secondHalfQuestions++;
        else
            secondHalfSum += num[i] - '0';
    }

    return 2 * (firstHalfSum - secondHalfSum) + 9 * (firstHalfQuestions - secondHalfQuestions) != 0;
}

int main(int argc, char const *argv[])
{
    printf("%s\n", sumGame("5023") ? "true" : "false");     // false
    printf("%s\n", sumGame("25??") ? "true" : "false");     // true
    printf("%s\n", sumGame("?3295???") ? "true" : "false"); // false
    return 0;
}
