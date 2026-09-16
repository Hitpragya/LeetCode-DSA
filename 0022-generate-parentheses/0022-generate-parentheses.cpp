class Solution {
    vector<string> validCombinations;

    void buildCombinations(int openUsed, int closeUsed, int n, string& current) {
        if (current.length() == 2 * n) {
            validCombinations.push_back(current);
            return;
        }

        if (openUsed < n) {
            current.push_back('(');
            buildCombinations(openUsed + 1, closeUsed, n, current);
            current.pop_back();
        }

        if (closeUsed < openUsed) {
            current.push_back(')');
            buildCombinations(openUsed, closeUsed + 1, n, current);
            current.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string current;
        buildCombinations(0, 0, n, current);
        return validCombinations;
    }
};