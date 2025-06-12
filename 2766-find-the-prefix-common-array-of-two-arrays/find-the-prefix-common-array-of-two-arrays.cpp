class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<bool> seen(n + 1, false);
        vector<int> result(n);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (seen[A[i]]) count++;
            else seen[A[i]] = true;
            
            if (seen[B[i]]) count++;
            else seen[B[i]] = true;
            
            result[i] = count;
        }
        return result;
    }
};
