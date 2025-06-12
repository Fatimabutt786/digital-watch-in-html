#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxDist = 0;
        for (int i = 0; i < n; ++i) {
            int next = (i + 1) % n;  
            int dist = abs(nums[i] - nums[next]);
            maxDist = max(maxDist, dist);
        }
        return maxDist;
    }
};
