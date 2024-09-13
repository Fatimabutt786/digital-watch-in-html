class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXor(n);
        vector<int> result;
        
        // Compute the prefix XOR array
        prefixXor[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            prefixXor[i] = prefixXor[i - 1] ^ arr[i];
        }
        
        // Process each query
        for (const auto& query : queries) {
            int L = query[0];
            int R = query[1];
            if (L == 0) {
                result.push_back(prefixXor[R]);
            } else {
                result.push_back(prefixXor[R] ^ prefixXor[L - 1]);
            }
        }
        
        return result;
    }
};