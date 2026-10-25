class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rowCount = grid.size();
        int columnCount = grid[0].size();

        for (int row = 0; row < rowCount; row++) {
            removeOpenIsland(grid, row, 0);
            removeOpenIsland(grid, row, columnCount - 1);
        }

        for (int column = 0; column < columnCount; column++) {
            removeOpenIsland(grid, 0, column);
            removeOpenIsland(grid, rowCount - 1, column);
        }

        int closedIslandCount = 0;

        for (int row = 1; row < rowCount - 1; row++) {
            for (int column = 1; column < columnCount - 1; column++) {
                if (grid[row][column] == 0) {
                    closedIslandCount++;
                    removeOpenIsland(grid, row, column);
                }
            }
        }

        return closedIslandCount;
    }

private:
    void removeOpenIsland(vector<vector<int>>& grid, int row, int column) {
        if (row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size()) {
            return;
        }

        if (grid[row][column] == 1) {
            return;
        }

        grid[row][column] = 1;

        removeOpenIsland(grid, row + 1, column);
        removeOpenIsland(grid, row - 1, column);
        removeOpenIsland(grid, row, column + 1);
        removeOpenIsland(grid, row, column - 1);
    }
};