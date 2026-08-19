class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reservedMaskByRow;

        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int column = seat[1];

            if (column >= 2 && column <= 9) {
                reservedMaskByRow[row] |= (1 << column);
            }
        }

        int answer = 2 * (n - reservedMaskByRow.size());

        int leftBlock = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int middleBlock = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int rightBlock = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for (const auto& [row, reservedMask] : reservedMaskByRow) {
            bool leftAvailable = (reservedMask & leftBlock) == 0;
            bool middleAvailable = (reservedMask & middleBlock) == 0;
            bool rightAvailable = (reservedMask & rightBlock) == 0;

            if (leftAvailable && rightAvailable) {
                answer += 2;
            } else if (leftAvailable || middleAvailable || rightAvailable) {
                answer++;
            }
        }

        return answer;
    }
};