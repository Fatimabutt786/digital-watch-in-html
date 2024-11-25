class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = board.size();    // Number of rows
        int n = board[0].size(); // Number of columns

        // Convert board into a string
        string start;
        string target;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                start += to_string(board[i][j]);
                target += to_string(i * n + j + 1);
            }
        }
        target.back() = '0'; // Last element in target is the empty slot '0'

        // Helper function to calculate neighbors of a position
        auto getNeighbors = [&](int idx) -> vector<int> {
            int x = idx / n; // Row of the current index
            int y = idx % n; // Column of the current index
            vector<int> neighbors;

            // Possible directions: up, down, left, right
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (const auto& [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    neighbors.push_back(nx * n + ny); // Convert (nx, ny) to 1D index
                }
            }
            return neighbors;
        };

        // BFS initialization
        queue<pair<string, int>> q; // {current state, number of moves}
        unordered_set<string> visited; // To track visited states

        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            auto [current, moves] = q.front();
            q.pop();

            // Check if we have reached the target state
            if (current == target) {
                return moves;
            }

            // Find the index of the empty slot (0)
            int zeroIndex = current.find('0');

            // Generate all possible states by swapping 0 with its neighbors
            for (int neighbor : getNeighbors(zeroIndex)) {
                string next = current;
                swap(next[zeroIndex], next[neighbor]);

                if (!visited.count(next)) {
                    visited.insert(next);
                    q.push({next, moves + 1});
                }
            }
        }

        // If no solution exists
        return -1;
    }
};