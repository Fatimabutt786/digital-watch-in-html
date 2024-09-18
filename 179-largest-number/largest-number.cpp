class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert numbers to strings
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        // Custom sort using lambda
        sort(strNums.begin(), strNums.end(), [](const string& a, const string& b) {
            return a + b > b + a; // Compare concatenated results
        });

        // If the largest number is "0", we should return "0"
        if (strNums[0] == "0") {
            return "0";
        }

        // Concatenate sorted strings
        string result;
        for (const string& str : strNums) {
            result += str;
        }

        return result;
    }
};