#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUMS_MAX 100

static int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int missingMultipleSlow(int *nums, int numsSize, int k)
{
    // 1. Remove all non-divisible by k O(n).
    // 2. Sort integer array O(n log(n)).
    // 3. Return smallest missing value in array O(n).
    // All in all O(n log(n)).

    for (int i = 0; i < numsSize; i++)
    {
        nums[i] = (nums[i] % k == 0) ? nums[i] : 0;
    }

    qsort(nums, numsSize, sizeof(int), cmp);

    for (int m = k, j = 0; m <= NUMS_MAX + k; m += k)
    {
        while (j < numsSize && nums[j] < m)
            j++;
        if (j >= numsSize || nums[j] != m)
            return m;
    }
    return 0;
}

int missingMultipleFast(int *nums, int numsSize, int k)
{
    // Theoretically in this instance sorting in O(n) time:
    // a. Set specific memory address.
    // b. Malloc for max width.
    // c. Set &(head address + n * sizeOf(int)) as n.
    // Also removes duplicates. Since 1 <= nums[i] <= 100, max malloc is k + 101.
    // Downside: very memory inefficient.

    int *sorted = calloc(NUMS_MAX + k + 1, sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        sorted[nums[i]] = (nums[i] % k == 0) ? nums[i] : 0;
    }
    for (int m = k; m <= NUMS_MAX + k; m += k)
    {
        if (sorted[m] == 0)
        {
            free(sorted);
            return m;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int nums1[] = {8, 2, 3, 4, 6};
    printf("%d %d\n", missingMultipleSlow(nums1, 5, 2), missingMultipleFast((int[]){8, 2, 3, 4, 6}, 5, 2)); // expected: 10

    int nums2[] = {1, 4, 7, 10, 15};
    printf("%d %d\n", missingMultipleSlow(nums2, 5, 5), missingMultipleFast((int[]){1, 4, 7, 10, 15}, 5, 5)); // expected: 5

    int nums3[] = {42, 13, 99, 13, 71, 32, 64, 32, 63, 44, 6, 22, 8, 2, 55, 88, 43, 40, 71, 80, 95, 32, 46, 19};
    printf("%d %d\n", missingMultipleSlow(nums3, 24, 44), missingMultipleFast((int[]){42, 13, 99, 13, 71, 32, 64, 32, 63, 44, 6, 22, 8, 2, 55, 88, 43, 40, 71, 80, 95, 32, 46, 19}, 24, 44)); // expected: 132

    // benchmark with 10000 elements, 1000 iterations each
    int n = 10000;
    int *big = malloc(n * sizeof(int));
    srand(42);
    for (int i = 0; i < n; i++)
        big[i] = rand() % 100 + 1;
    int *bigCopy = malloc(n * sizeof(int));
    memcpy(bigCopy, big, n * sizeof(int));

    clock_t t1 = clock();
    for (int r = 0; r < 1000; r++)
    {
        memcpy(big, bigCopy, n * sizeof(int));
        missingMultipleSlow(big, n, 7);
    }
    clock_t t2 = clock();
    for (int r = 0; r < 1000; r++)
        missingMultipleFast(bigCopy, n, 7);
    clock_t t3 = clock();

    printf("slow: %.3f ms\n", (double)(t2 - t1) / CLOCKS_PER_SEC * 1000);
    printf("fast: %.3f ms\n", (double)(t3 - t2) / CLOCKS_PER_SEC * 1000);

    free(big);
    free(bigCopy);
    return 0;
}
