class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> rowCount; 
        
        for (const auto& row : matrix) {
            string original = "", flipped = "";
        
            for (int num : row) {
                original += to_string(num);
                flipped += to_string(1 - num); 
            }
            
            rowCount[original]++;
            rowCount[flipped]++;
        }
     
        int maxRows = 0;
        for (const auto& entry : rowCount) {
            maxRows = max(maxRows, entry.second);
        }
        
        return maxRows;
         }
};
  