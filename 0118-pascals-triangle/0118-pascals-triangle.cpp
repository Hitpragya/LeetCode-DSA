class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.reserve(numRows);

        for (int rowIndex = 0; rowIndex < numRows; rowIndex++) {
            vector<int> currentRow(rowIndex + 1, 1);

            for (int colIndex = 1; colIndex < rowIndex; colIndex++) {
                currentRow[colIndex] = triangle[rowIndex - 1][colIndex - 1] + triangle[rowIndex - 1][colIndex];
            }

            triangle.push_back(currentRow);
        }

        return triangle;
    }
};