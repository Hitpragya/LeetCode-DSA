class Solution {
public:
    int longestValidParentheses(string s) {
        int maximumLength = 0;
        int openCount = 0;
        int closeCount = 0;

        for (char parenthesis : s) {
            if (parenthesis == '(') {
                openCount++;
            } else {
                closeCount++;
            }

            if (openCount == closeCount) {
                maximumLength = max(maximumLength, 2 * closeCount);
            } else if (closeCount > openCount) {
                openCount = 0;
                closeCount = 0;
            }
        }

        openCount = 0;
        closeCount = 0;

        for (int index = static_cast<int>(s.size()) - 1; index >= 0; index--) {
            if (s[index] == '(') {
                openCount++;
            } else {
                closeCount++;
            }

            if (openCount == closeCount) {
                maximumLength = max(maximumLength, 2 * openCount);
            } else if (openCount > closeCount) {
                openCount = 0;
                closeCount = 0;
            }
        }

        return maximumLength;
    }
};