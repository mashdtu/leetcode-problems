/* Binary search: partition both arrays so left half <= right half. O(log(min(m,n))) */

#include <stdio.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    if (nums1Size > nums2Size)
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);

    int m = nums1Size, n = nums2Size;
    int lo = 0, hi = m;
    int half = (m + n + 1) / 2;

    while (lo <= hi)
    {
        int i = (lo + hi) / 2;
        int j = half - i;

        int l1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int r1 = (i == m) ? INT_MAX : nums1[i];
        int l2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int r2 = (j == n) ? INT_MAX : nums2[j];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((m + n) % 2 == 1)
                return MAX(l1, l2);
            return (MAX(l1, l2) + MIN(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
            hi = i - 1;
        else
            lo = i + 1;
    }
    return 0.0;
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 3};
    int b[] = {2, 4};
    printf("%f\n", findMedianSortedArrays(a, 2, b, 2)); /* expected 2.5 */

    int c[] = {1, 2};
    int d[] = {3, 4};
    printf("%f\n", findMedianSortedArrays(c, 2, d, 2)); /* expected 2.5 */

    int e[] = {0, 0};
    int f[] = {0, 0};
    printf("%f\n", findMedianSortedArrays(e, 2, f, 2)); /* expected 0.0 */

    return 0;
}

