class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int depth = 0;

        for (int index = 0; index < s.size(); index++) {
            if (s[index] == '(') {
                depth++;
            } else {
                depth--;

                if (s[index - 1] == '(') {
                    score += 1 << depth;
                }
            }
        }

        return score;
    }
};