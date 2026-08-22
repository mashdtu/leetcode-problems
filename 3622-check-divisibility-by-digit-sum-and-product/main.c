#include <stdbool.h>
#include <stdio.h>

bool checkDivisibility(int n)
{
    int original_n = n;
    int sum = 0, product = 1;
    while (n > 0)
    {
        int digit = n % 10;
        sum += digit;
        product *= digit;
        n /= 10;
    }
    return original_n % (sum + product) == 0;
}

int main(int argc, char const *argv[])
{
    printf("checkDivisibility(99) = %s (expected true)\n", checkDivisibility(99) ? "true" : "false");
    printf("checkDivisibility(23) = %s (expected false)\n", checkDivisibility(23) ? "true" : "false");
    return 0;
}
