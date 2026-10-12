class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) {
            return false;
        }

        int n = grid.size();
        int totalCells = n * n;
        
        vector<pair<int, int>> positions(totalCells);
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                positions[grid[r][c]] = {r, c};
            }
        }

        for (int i = 1; i < totalCells; ++i) {
            int prevRow = positions[i - 1].first;
            int prevCol = positions[i - 1].second;
            int currRow = positions[i].first;
            int currCol = positions[i].second;

            int rowDiff = abs(currRow - prevRow);
            int colDiff = abs(currCol - prevCol);

            if (!((rowDiff == 1 && colDiff == 2) || (rowDiff == 2 && colDiff == 1))) {
                return false;
            }
        }

        return true;
    }
};