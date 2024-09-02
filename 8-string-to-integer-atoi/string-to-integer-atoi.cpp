

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        // Skip leading whitespaces
        while (i < n && s[i] == ' ') i++;
        
        // Check if the sign is present
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Convert characters to an integer
        long long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            // Check for overflow and underflow
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;
            i++;
        }
        
        return result * sign;
    }
};
