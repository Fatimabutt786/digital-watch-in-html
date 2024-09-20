class Solution {
public:
    string shortestPalindrome(string s) {
        // Edge case: if the string is empty or has only one character, it's already a palindrome
        if (s.empty()) return s;
        
        // Create the concatenated string: original + "#" + reversed original
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string combined = s + "#" + rev_s;
        
        // Build the KMP table (pi array) for the combined string
        int n = combined.size();
        vector<int> pi(n, 0);  // Prefix table
        
        // Fill the prefix table using KMP algorithm logic
        for (int i = 1; i < n; ++i) {
            int j = pi[i - 1];
            
            // Find the longest prefix which is also suffix
            while (j > 0 && combined[i] != combined[j]) {
                j = pi[j - 1];
            }
            
            if (combined[i] == combined[j]) {
                j++;
            }
            pi[i] = j;
        }
        
        // pi.back() gives us the length of the longest palindromic prefix
        int longest_palindromic_prefix = pi.back();
        
        // Take the remaining part of the string (that is not part of the palindrome)
        // and append it to the front after reversing
        string to_add = s.substr(longest_palindromic_prefix);
        reverse(to_add.begin(), to_add.end());
        
        // Add the reversed part to the original string
        return to_add + s;
    }
};
