

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; // Edge case: empty input
        
        // Mapping of digits to letters
        vector<string> digitToChar = {
            "",     // '0'
            "",     // '1'
            "abc",  // '2'
            "def",  // '3'
            "ghi",  // '4'
            "jkl",  // '5'
            "mno",  // '6'
            "pqrs", // '7'
            "tuv",  // '8'
            "wxyz"  // '9'
        };

        vector<string> result;
        string currentCombination;

        // Backtracking function
        function<void(int)> backtrack = [&](int index) {
            if (index == digits.size()) { // Base case: combination is complete
                result.push_back(currentCombination);
                return;
            }

            // Get the characters corresponding to the current digit
            string letters = digitToChar[digits[index] - '0'];
            for (char letter : letters) {
                currentCombination.push_back(letter);   // Add letter to current combination
                backtrack(index + 1);                  // Recurse for the next digit
                currentCombination.pop_back();         // Backtrack
            }
        };

        backtrack(0); // Start backtracking from the first digit
        return result;
    }
};
