class Solution {
public:
    // Function to find the first position of target
    int findFirstPosition(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                result = mid;
                high = mid - 1;  // Move left to find first occurrence
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return result;
    }

    // Function to find the last position of target
    int findLastPosition(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                result = mid;
                low = mid + 1;  // Move right to find last occurrence
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return result;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        
        // Find the first position of target
        result[0] = findFirstPosition(nums, target);
        if (result[0] != -1) {
            // If found, find the last position of target
            result[1] = findLastPosition(nums, target);
        }

        return result;
    }
};
