class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Step 1: Create a set of allowed characters for quick lookup
        unordered_set<char> allowedSet(allowed.begin(), allowed.end());
        int consistentCount = 0;
        
        // Step 2: Check each word in the words vector
        for (const string& word : words) {
            bool isConsistent = true;
            
            // Step 3: Check if all characters of the word are in the allowed set
            for (char c : word) {
                if (allowedSet.find(c) == allowedSet.end()) {
                    isConsistent = false;
                    break;
                }
            }
            
            // Step 4: If the word is consistent, increase the count
            if (isConsistent) {
                consistentCount++;
            }
        }
        
        // Step 5: Return the total count of consistent strings
        return consistentCount;
    }
};

