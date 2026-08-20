class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            
            if (map.containsKey(complement)) {
                return new int[] { map.get(complement), i };
            }
            
            map.put(nums[i], i);
        }

        throw new IllegalArgumentException("No solution found");
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        
        // Example 1: nums = [2,7,11,15], target = 9
        int[] nums1 = {2, 7, 11, 15};
        int target1 = 9;
        int[] result1 = solution.twoSum(nums1, target1);
        System.out.println("Example 1: [" + result1[0] + "," + result1[1] + "]"); // Expected: [0,1]
        
        // Example 2: nums = [3,2,4], target = 6  
        int[] nums2 = {3, 2, 4};
        int target2 = 6;
        int[] result2 = solution.twoSum(nums2, target2);
        System.out.println("Example 2: [" + result2[0] + "," + result2[1] + "]"); // Expected: [1,2]
        
        // Example 3: nums = [3,3], target = 6
        int[] nums3 = {3, 3};
        int target3 = 6;
        int[] result3 = solution.twoSum(nums3, target3);
        System.out.println("Example 3: [" + result3[0] + "," + result3[1] + "]"); // Expected: [0,1]
        
        // Example 4: nums = [-3,4,3,90], target = 0
        int[] nums4 = {-3,4,3,90};
        int target4 = 0;
        int[] result4 = solution.twoSum(nums4, target4);
        System.out.println("Example 4: [" + result4[0] + "," + result4[1] + "]"); // Expected: [0,2]
    }
}
