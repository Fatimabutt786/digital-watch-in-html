class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 1) return points.size();
        
        int maxPointsOnLine = 1;
        
        for (int i = 0; i < points.size(); i++) {
            unordered_map<string, int> slopeCount;
            int samePoint = 0, vertical = 0, localMax = 0;
            
            for (int j = i + 1; j < points.size(); j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    samePoint++;  // Count duplicates
                } else if (dx == 0) {
                    vertical++;  // Count vertical lines
                } else {
                    // Compute slope as a fraction (dy/dx) in reduced form
                    int gcd = __gcd(dx, dy);
                    string slope = to_string(dy / gcd) + "/" + to_string(dx / gcd);
                    slopeCount[slope]++;
                    localMax = max(localMax, slopeCount[slope]);
                }
            }
            
            maxPointsOnLine = max(maxPointsOnLine, max(localMax, vertical) + samePoint + 1);
        }
        
        return maxPointsOnLine;
    }
};

