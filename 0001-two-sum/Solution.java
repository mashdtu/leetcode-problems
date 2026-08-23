class Solution {
    public int[] twoSum(int[] nums, int target) {
        for (int i = 1; i < nums.length; i++) {
            for (int j = i; j < nums.length; j++) {
                if (nums[j] + nums[j - i] == target) {
                    return new int[] { j, j - i };
                }
            }
        }
        return new int[2];

    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] nums1 = { 2, 7, 11, 15 };
        int target1 = 9;
        int[] result1 = solution.twoSum(nums1, target1);
        System.out.println("Example 1: [" + result1[0] + "," + result1[1] + "]");

        int[] nums2 = { 3, 2, 4 };
        int target2 = 6;
        int[] result2 = solution.twoSum(nums2, target2);
        System.out.println("Example 2: [" + result2[0] + "," + result2[1] + "]");

        int[] nums3 = { 3, 3 };
        int target3 = 6;
        int[] result3 = solution.twoSum(nums3, target3);
        System.out.println("Example 3: [" + result3[0] + "," + result3[1] + "]");

        int[] nums4 = { -3, 4, 3, 90 };
        int target4 = 0;
        int[] result4 = solution.twoSum(nums4, target4);
        System.out.println("Example 4: [" + result4[0] + "," + result4[1] + "]");
    }
}
