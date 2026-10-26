class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rowCount = grid.size();
        int colCount = grid[0].size();

        vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
        int divisibleIslands = 0;

        for (int row = 0; row < rowCount; row++) {
            for (int col = 0; col < colCount; col++) {
                if (grid[row][col] > 0 && !visited[row][col]) {
                    if (getIslandRemainder(grid, visited, row, col, k) == 0) {
                        divisibleIslands++;
                    }
                }
            }
        }

        return divisibleIslands;
    }

private:
    int getIslandRemainder(vector<vector<int>>& grid,
                           vector<vector<bool>>& visited,
                           int startRow,
                           int startCol,
                           int k) {
        int rowCount = grid.size();
        int colCount = grid[0].size();

        queue<pair<int, int>> cells;
        cells.push({startRow, startCol});
        visited[startRow][startCol] = true;

        int islandRemainder = grid[startRow][startCol] % k;

        while (!cells.empty()) {
            auto [row, col] = cells.front();
            cells.pop();

            int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

            for (auto& direction : directions) {
                int nextRow = row + direction[0];
                int nextCol = col + direction[1];

                if (nextRow >= 0 && nextRow < rowCount &&
                    nextCol >= 0 && nextCol < colCount &&
                    grid[nextRow][nextCol] > 0 &&
                    !visited[nextRow][nextCol]) {

                    visited[nextRow][nextCol] = true;
                    islandRemainder = (islandRemainder + grid[nextRow][nextCol]) % k;
                    cells.push({nextRow, nextCol});
                }
            }
        }

        return islandRemainder;
    }
};