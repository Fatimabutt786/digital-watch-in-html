class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        // If the transformed sum is invalid, return 0
        if ((sum + target) % 2 != 0 || sum + target < 0) {
            return 0;
        }
        
        int subsetSum = (sum + target) / 2;
        
        // Initialize DP array
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1; // There's one way to make sum 0: by choosing nothing.
        
        // Fill the DP array
        for (int num : nums) {
            for (int j = subsetSum; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[subsetSum];
    }
};
