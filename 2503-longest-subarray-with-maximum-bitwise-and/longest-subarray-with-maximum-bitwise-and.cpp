
class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int maxVal = *std::max_element(nums.begin(), nums.end());  // Find the maximum value
        int longestLength = 0;
        int currentLength = 0;
        
        for (int num : nums) {
            if (num == maxVal) {
                ++currentLength;
                longestLength = std::max(longestLength, currentLength);
            } else {
                currentLength = 0;  // Reset the current length when a non-max value is encountered
            }
        }
        
        return longestLength;
    }
};