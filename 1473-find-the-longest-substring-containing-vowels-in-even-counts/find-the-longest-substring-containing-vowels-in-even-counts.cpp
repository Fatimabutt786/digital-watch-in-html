
class Solution {
public:
    int findTheLongestSubstring(std::string s) {
        std::unordered_map<int, int> maskIndexMap;
        int mask = 0;
        int maxLength = 0;
        maskIndexMap[0] = -1; // Base case: an empty substring with all vowels even

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            // Update the bitmask based on the current character
            switch (c) {
                case 'a': mask ^= 1 << 0; break;
                case 'e': mask ^= 1 << 1; break;
                case 'i': mask ^= 1 << 2; break;
                case 'o': mask ^= 1 << 3; break;
                case 'u': mask ^= 1 << 4; break;
            }

            // Check if this bitmask has been seen before
            if (maskIndexMap.find(mask) != maskIndexMap.end()) {
                maxLength = std::max(maxLength, i - maskIndexMap[mask]);
            } else {
                maskIndexMap[mask] = i;
            }
        }

        return maxLength;
    }
};
