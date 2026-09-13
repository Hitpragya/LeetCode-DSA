class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> onesInFirst;
        vector<pair<int, int>> onesInSecond;

        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                if (img1[row][col] == 1) {
                    onesInFirst.push_back({row, col});
                }
                if (img2[row][col] == 1) {
                    onesInSecond.push_back({row, col});
                }
            }
        }

        unordered_map<int, int> shiftFrequency;
        int maximumOverlap = 0;

        for (const auto& firstCell : onesInFirst) {
            for (const auto& secondCell : onesInSecond) {
                int rowShift = secondCell.first - firstCell.first;
                int colShift = secondCell.second - firstCell.second;

                int shiftKey = (rowShift + n) * (2 * n - 1) + (colShift + n);

                maximumOverlap = max(maximumOverlap, ++shiftFrequency[shiftKey]);
            }
        }

        return maximumOverlap;
    }
};