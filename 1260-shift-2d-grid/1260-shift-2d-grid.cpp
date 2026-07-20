class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rowCount = grid.size();
        int columnCount = grid[0].size();
        int totalCount = rowCount * columnCount;

        k %= totalCount;

        vector<vector<int>> result(rowCount, vector<int>(columnCount));

        for (int row = 0; row < rowCount; ++row) {
            for (int column = 0; column < columnCount; ++column) {
                int index = row * columnCount + column;
                int shiftedIndex = (index + k) % totalCount;

                int newRow = shiftedIndex / columnCount;
                int newColumn = shiftedIndex % columnCount;

                result[newRow][newColumn] = grid[row][column];
            }
        }

        return result;
    }
};