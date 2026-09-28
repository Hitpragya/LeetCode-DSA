class Solution {
public:
    int maxDepth(string s) {
        int currentDepth = 0;
        int maximumDepth = 0;

        for (char character : s) {
            if (character == '(') {
                currentDepth++;
                maximumDepth = max(maximumDepth, currentDepth);
            } else if (character == ')') {
                currentDepth--;
            }
        }

        return maximumDepth;
    }
};