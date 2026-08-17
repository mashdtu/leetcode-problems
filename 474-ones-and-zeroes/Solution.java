/*
 * LeetCode problem 474. Ones and Zeroes

 * You are given an array of binary strings strs and two integers m and n.
 * Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
 * A set x is a subset of a set y if all elements of x are also elements of y.
 
 * https://leetcode.com/problems/ones-and-zeroes/description/

 */

public class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][] dp = new int[m + 1][n + 1];
        
        // Process each string
        for (String str : strs) {
            int zeros = 0, ones = 0;
            for (char c : str.toCharArray()) {
                if (c == '0') zeros++;
                else ones++;
            }
            
            // Traverse backwards to avoid using updated values
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
    
    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1: ["10","0001","111001","1","0"], m=5, n=3
        int m = 5; int n = 3;
        String[] strs1 = {"10", "0001", "111001", "1", "0"};
        System.out.println("Test 1: " + solution.findMaxForm(strs1, m, n));
        
        // Test case 2: ["10","0","1"], m=1, n=1  
        m = 1; n = 1;
        String[] strs2 = {"10", "0", "1"};
        System.out.println("Test 2: " + solution.findMaxForm(strs2, m, n));
        
        // Test case 3: ["00011","00001","00001","0011","111"], m=8, n=5  
        m = 8; n = 5;
        String[] strs3 = {"00011","00001","00001","0011","111"};
        System.out.println("Test 3: " + solution.findMaxForm(strs3, m, n));
    }
}

// Runtime: 17 ms (top 3.78%)
// Time complexity: O(L * M * N)
// Memory: 43.34 MB (top 47.69%)
// Space complexity: O(M * N)
