class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int openBrackets = 0;

        for (int index = 0; index < static_cast<int>(s.size()); ++index) {
            if (s[index] == '(') {
                ++openBrackets;
            } else {
                bool hasSecondClosingBracket =
                    index + 1 < static_cast<int>(s.size()) && s[index + 1] == ')';

                if (hasSecondClosingBracket) {
                    ++index;
                } else {
                    ++insertions;
                }

                if (openBrackets > 0) {
                    --openBrackets;
                } else {
                    ++insertions;
                }
            }
        }

        insertions += 2 * openBrackets;
        return insertions;
    }
};