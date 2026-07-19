class Solution {
public:
    int titleToNumber(string columnTitle) {
        int columnNumber = 0;

        for (char character : columnTitle) {
            int letterValue = character - 'A' + 1;
            columnNumber = columnNumber * 26 + letterValue;
        }

        return columnNumber;
    }
};