#include <stdio.h>

int stoneGameVIII(int *stones, int stonesSize)
{
}

int main(int argc, char const *argv[])
{
    int s1[] = {-1, 2, -3, 4, -5};
    printf("%d\n", stoneGameVIII(s1, 5)); /* expected: 5 */

    int s2[] = {7, -6, 5, 10, 5, -2, -6};
    printf("%d\n", stoneGameVIII(s2, 7)); /* expected: 13 */

    int s3[] = {-10, -12};
    printf("%d\n", stoneGameVIII(s3, 2)); /* expected: -22 */

    return 0;
}
