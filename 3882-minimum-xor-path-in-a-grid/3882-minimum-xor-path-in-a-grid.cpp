class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bitset<1024>>> reachable(
            rows, vector<bitset<1024>>(cols)
        );

        reachable[0][0][grid[0][0]] = true;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int value = grid[row][col];

                if (row > 0) {
                    for (int incomingXor = 0; incomingXor < 1024; incomingXor++) {
                        if (reachable[row - 1][col][incomingXor]) {
                            reachable[row][col][incomingXor ^ value] = true;
                        }
                    }
                }

                if (col > 0) {
                    for (int incomingXor = 0; incomingXor < 1024; incomingXor++) {
                        if (reachable[row][col - 1][incomingXor]) {
                            reachable[row][col][incomingXor ^ value] = true;
                        }
                    }
                }
            }
        }

        for (int finalXor = 0; finalXor < 1024; finalXor++) {
            if (reachable[rows - 1][cols - 1][finalXor]) {
                return finalXor;
            }
        }

        return -1;
    }
};