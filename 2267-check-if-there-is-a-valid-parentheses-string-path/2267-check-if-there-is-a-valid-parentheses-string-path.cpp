class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int pathLength = rows + columns - 1;

        if (pathLength % 2 == 1 || grid[0][0] == ')' || grid[rows - 1][columns - 1] == '(') {
            return false;
        }

        vector<vector<bool>> dp(columns, vector<bool>(pathLength + 1, false));
        dp[0][1] = true;

        for (int row = 0; row < rows; row++) {
            for (int column = 0; column < columns; column++) {
                if (row == 0 && column == 0) {
                    continue;
                }

                int change = grid[row][column] == '(' ? 1 : -1;
                vector<bool> current(pathLength + 1, false);

                for (int balance = 0; balance <= pathLength; balance++) {
                    bool reachableFromTop = row > 0 && dp[column][balance];
                    bool reachableFromLeft = column > 0 && dp[column - 1][balance];

                    if (!reachableFromTop && !reachableFromLeft) {
                        continue;
                    }

                    int nextBalance = balance + change;

                    if (nextBalance >= 0 && nextBalance <= pathLength) {
                        current[nextBalance] = true;
                    }
                }

                dp[column] = current;
            }
        }

        return dp[columns - 1][0];
    }
};