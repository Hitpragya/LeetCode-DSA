class Solution {
    vector<string> combinations;
    vector<string> keypad = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void generateCombinations(const string& digits, int index, string& current) {
        if (index == digits.size()) {
            combinations.push_back(current);
            return;
        }

        const string& letters = keypad[digits[index] - '0'];

        for (char letter : letters) {
            current.push_back(letter);
            generateCombinations(digits, index + 1, current);
            current.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        string current;
        generateCombinations(digits, 0, current);

        return combinations;
    }
};