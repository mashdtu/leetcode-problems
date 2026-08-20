public class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][] dp = new int[m + 1][n + 1];
        
        for (String str : strs) {
            int zeros = 0, ones = 0;
            for (char c : str.toCharArray()) {
                if (c == '0') zeros++;
                else ones++;
            }
            
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

        int m = 5; int n = 3;
        String[] strs1 = {"10", "0001", "111001", "1", "0"};
        System.out.println("Test 1: " + solution.findMaxForm(strs1, m, n));
        
        m = 1; n = 1;
        String[] strs2 = {"10", "0", "1"};
        System.out.println("Test 2: " + solution.findMaxForm(strs2, m, n));
        
        m = 8; n = 5;
        String[] strs3 = {"00011","00001","00001","0011","111"};
        System.out.println("Test 3: " + solution.findMaxForm(strs3, m, n));
    }
}
