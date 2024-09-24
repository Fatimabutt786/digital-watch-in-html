class Solution {
public:
    // Helper function to find the common prefix length of two strings
    int commonPrefixLength(string &s1, string &s2) {
        int n = min(s1.size(), s2.size());
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) return i; // Return the index where characters differ
        }
        return n; // If all characters match up to the length of the smaller string
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // Convert integers to strings
        vector<string> s1, s2;
        for (int x : arr1) s1.push_back(to_string(x));
        for (int y : arr2) s2.push_back(to_string(y));

        // Sort both arrays of strings
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        int maxLength = 0;

        // Use two pointers to compare strings from both sorted arrays
        int i = 0, j = 0;
        while (i < s1.size() && j < s2.size()) {
            int prefixLength = commonPrefixLength(s1[i], s2[j]);
            maxLength = max(maxLength, prefixLength);
            
            // Move forward in the array with the smaller current value
            if (s1[i] < s2[j]) {
                i++;
            } else {
                j++;
            }
        }

        return maxLength;
    }
};
