class Solution {
public:
    struct State {
        int row;
        int col;
        int mask;
        int remainingEnergy;
        int moves;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int rows = classroom.size();
        int cols = classroom[0].size();

        vector<vector<int>> litterIndex(rows, vector<int>(cols, -1));

        int startRow = 0;
        int startCol = 0;
        int litterCount = 0;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (classroom[row][col] == 'S') {
                    startRow = row;
                    startCol = col;
                } 
                else if (classroom[row][col] == 'L') {
                    litterIndex[row][col] = litterCount++;
                }
            }
        }

        int totalMasks = 1 << litterCount;
        int targetMask = totalMasks - 1;

        vector<vector<vector<int>>> bestEnergy(
            rows,
            vector<vector<int>>(cols, vector<int>(totalMasks, -1))
        );

        queue<State> bfsQueue;
        bfsQueue.push({startRow, startCol, 0, energy, 0});
        bestEnergy[startRow][startCol][0] = energy;

        vector<int> rowChange = {-1, 1, 0, 0};
        vector<int> colChange = {0, 0, -1, 1};

        while (!bfsQueue.empty()) {
            State current = bfsQueue.front();
            bfsQueue.pop();

            if (current.mask == targetMask) {
                return current.moves;
            }

            if (current.remainingEnergy == 0) {
                continue;
            }

            for (int direction = 0; direction < 4; ++direction) {
                int nextRow = current.row + rowChange[direction];
                int nextCol = current.col + colChange[direction];

                if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols) {
                    continue;
                }

                if (classroom[nextRow][nextCol] == 'X') {
                    continue;
                }

                int nextMask = current.mask;
                int nextEnergy = current.remainingEnergy - 1;

                if (classroom[nextRow][nextCol] == 'L') {
                    nextMask |= (1 << litterIndex[nextRow][nextCol]);
                }

                if (classroom[nextRow][nextCol] == 'R') {
                    nextEnergy = energy;
                }

                if (nextEnergy <= bestEnergy[nextRow][nextCol][nextMask]) {
                    continue;
                }

                bestEnergy[nextRow][nextCol][nextMask] = nextEnergy;

                bfsQueue.push({
                    nextRow,
                    nextCol,
                    nextMask,
                    nextEnergy,
                    current.moves + 1
                });
            }
        }

    return -1;
    }
};