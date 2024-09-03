class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b) {
            // If the two strings are identical, no uncommon subsequence exists
            return -1;
        }
        // If the two strings are different, the longest uncommon subsequence
        // is the length of the longer string
        return max(a.size(), b.size());
    }
};
