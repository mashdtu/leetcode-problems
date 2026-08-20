#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *resultArray(int *nums, int numsSize, int *returnSize)
{
    int *arr1 = malloc(numsSize * sizeof(int));
    int *arr2 = malloc(numsSize * sizeof(int));
    int size1 = 0;
    int size2 = 0;

    arr1[size1++] = nums[0];
    arr2[size2++] = nums[1];

    for (int i = 2; i < numsSize; i++)
    {
        if (arr1[size1 - 1] > arr2[size2 - 1])
            arr1[size1++] = nums[i];
        else
            arr2[size2++] = nums[i];
    }

    int *result = malloc(numsSize * sizeof(int));
    memcpy(result, arr1, size1 * sizeof(int));
    memcpy(result + size1, arr2, size2 * sizeof(int));

    free(arr1);
    free(arr2);

    *returnSize = numsSize;
    return result;
}

int main(int argc, char const *argv[])
{
    int returnSize;

    int nums1[] = {2, 1, 3};
    int *result1 = resultArray(nums1, 3, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d ", result1[i]);
    printf("\n");
    free(result1);

    int nums2[] = {5, 4, 3, 8};
    int *result2 = resultArray(nums2, 4, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d ", result2[i]);
    printf("\n");

    return 0;
}
