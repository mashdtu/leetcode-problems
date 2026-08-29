#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int removeDuplicates(int *nums, int numsSize)
{
    bool *freq = calloc(201, sizeof(bool));
    int resultSize = 0;

    for (size_t i = 0; i < numsSize; i++)
    {
        resultSize += !freq[nums[i] + 100];
        freq[nums[i] + 100] = 1;
    }

    int j = 0;
    for (int i = 0; i < 201; i++)
        if (freq[i])
            nums[j++] = i - 100;

    free(freq);
    return resultSize;
}

int main(int argc, char const *argv[])
{
    int nums1[] = {1, 1, 2};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int k1 = removeDuplicates(nums1, nums1Size);

    printf("k = %d, nums = [", k1);
    for (int i = 0; i < nums1Size; i++)
        printf("%s%d", i == 0 ? "" : ",", nums1[i]);
    printf("]\n");

    int nums2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    int k2 = removeDuplicates(nums2, nums2Size);

    printf("k = %d, nums = [", k2);
    for (int i = 0; i < nums2Size; i++)
        printf("%s%d", i == 0 ? "" : ",", nums2[i]);
    printf("]\n");

    return 0;
}
