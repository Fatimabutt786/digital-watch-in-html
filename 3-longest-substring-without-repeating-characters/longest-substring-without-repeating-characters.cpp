class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap; // To store the last index of each character
        int maxLength = 0; // To keep track of the maximum length found
        int start = 0; // Starting index of the current substring

        for (int end = 0; end < s.size(); ++end) {
            char currentChar = s[end];

            // If the character is already in the substring, move the start pointer
            if (charIndexMap.find(currentChar) != charIndexMap.end()) {
                start = max(start, charIndexMap[currentChar] + 1);
            }

            // Update the last seen index of the character
            charIndexMap[currentChar] = end;

            // Calculate the length of the current substring
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength; // Return the maximum length found
    }
};