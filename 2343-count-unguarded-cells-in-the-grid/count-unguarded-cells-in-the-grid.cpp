class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        const int WALL = 1;
        const int GUARD = 2;
        const int GUARDED = 3;
        
        for (const auto& wall : walls) {
            int x = wall[0];
            int y = wall[1];
            grid[x][y] = WALL;
        }
        
        for (const auto& guard : guards) {
            int x = guard[0];
            int y = guard[1];
            grid[x][y] = GUARD;
        }
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        
        auto markGuarded = [&](int x, int y, int dx, int dy) {
            x += dx;
            y += dy;
            while (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != WALL && grid[x][y] != GUARD) {
                if (grid[x][y] == 0) {
                    grid[x][y] = GUARDED;
                }
                x += dx;
                y += dy;
            }
        };
        
        
        for (const auto& guard : guards) {
            int x = guard[0];
            int y = guard[1];
            for (const auto& dir : directions) {
                markGuarded(x, y, dir.first, dir.second);
            }
        }
        
       
        int unguardedCount = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ++unguardedCount;
                }
            }
        }
        
        return unguardedCount;
    }
};