
using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        int n = s.size();
        vector<int> dp(n + 1, 0);
        
        // Initialize dp
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1; // Start with taking current character as extra
            for (int j = 0; j < i; ++j) {
                string substring = s.substr(j, i - j);
                if (dict.count(substring)) {
                    dp[i] = min(dp[i], dp[j]); // Update if substring is in dictionary
                }
            }
        }
        
        return dp[n]; // Return the result for the entire string
    }
};
