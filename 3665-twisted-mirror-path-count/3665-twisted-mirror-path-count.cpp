class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1'000'000'007;
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<pair<int, int>>> rightLand(
            rows, vector<pair<int, int>>(cols, {-1, -1})
        );
        vector<vector<pair<int, int>>> downLand(
            rows, vector<pair<int, int>>(cols, {-1, -1})
        );

        for (int row = rows - 1; row >= 0; --row) {
            for (int col = cols - 1; col >= 0; --col) {
                if (col + 1 < cols) {
                    if (grid[row][col + 1] == 0) {
                        rightLand[row][col] = {row, col + 1};
                    } else {
                        rightLand[row][col] = downLand[row][col + 1];
                    }
                }

                if (row + 1 < rows) {
                    if (grid[row + 1][col] == 0) {
                        downLand[row][col] = {row + 1, col};
                    } else {
                        downLand[row][col] = rightLand[row + 1][col];
                    }
                }
            }
        }

        vector<vector<int>> pathCount(rows, vector<int>(cols, 0));
        pathCount[0][0] = 1;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (pathCount[row][col] == 0) {
                    continue;
                }

                pair<int, int> rightTarget = rightLand[row][col];
                pair<int, int> downTarget = downLand[row][col];

                if (rightTarget.first != -1) {
                    int nextRow = rightTarget.first;
                    int nextCol = rightTarget.second;
                    pathCount[nextRow][nextCol] =
                        (pathCount[nextRow][nextCol] + pathCount[row][col]) % MOD;
                }

                if (downTarget.first != -1) {
                    int nextRow = downTarget.first;
                    int nextCol = downTarget.second;
                    pathCount[nextRow][nextCol] =
                        (pathCount[nextRow][nextCol] + pathCount[row][col]) % MOD;
                }
            }
        }

        return pathCount[rows - 1][cols - 1];
    }
};