class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 0);
        row[0] = 1;

        for (int currentRow = 1; currentRow <= rowIndex; ++currentRow) {
            for (int position = currentRow; position >= 1; --position) {
                row[position] += row[position - 1];
            }
        }

        return row;
    }
};