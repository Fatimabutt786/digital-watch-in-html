class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int n = nums.size();
        int min_num = *min_element(nums.begin(), nums.end());
        int max_num = *max_element(nums.begin(), nums.end());
        
        if (max_num == min_num) return 0;

        int bucket_size = max(1, (max_num - min_num) / (n - 1));
        int bucket_count = (max_num - min_num) / bucket_size + 1;
        
        vector<int> min_bucket(bucket_count, INT_MAX);
        vector<int> max_bucket(bucket_count, INT_MIN);
        
        for (int num : nums) {
            int bucket_idx = (num - min_num) / bucket_size;
            min_bucket[bucket_idx] = min(min_bucket[bucket_idx], num);
            max_bucket[bucket_idx] = max(max_bucket[bucket_idx], num);
        }
        
        int max_gap = 0;
        int previous_max = min_num;
        
        for (int i = 0; i < bucket_count; i++) {
            if (min_bucket[i] == INT_MAX) continue;  
            max_gap = max(max_gap, min_bucket[i] - previous_max);
            previous_max = max_bucket[i];
        }
        
        return max_gap;
    }
};
