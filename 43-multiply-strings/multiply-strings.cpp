
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> result(m + n, 0);
        
        // Multiply each digit and place it in the appropriate position in the result array
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j;
                int p2 = i + j + 1;
                
                int sum = mul + result[p2];
                result[p2] = sum % 10;
                result[p1] += sum / 10;
            }
        }
        
        // Build the result string
        string resultStr;
        for (int num : result) {
            if (!(resultStr.empty() && num == 0)) { // Skip leading zeros
                resultStr.push_back(num + '0');
            }
        }
        
        return resultStr.empty() ? "0" : resultStr;
    }
};