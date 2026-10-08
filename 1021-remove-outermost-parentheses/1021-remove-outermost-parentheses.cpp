class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int depth = 0;

        for (char currentCharacter : s) {
            if (currentCharacter == '(') {
                if (depth > 0) {
                    result += currentCharacter;
                }
                ++depth;
            } else {
                --depth;
                if (depth > 0) {
                    result += currentCharacter;
                }
            }
        }

        return result;
    }
};