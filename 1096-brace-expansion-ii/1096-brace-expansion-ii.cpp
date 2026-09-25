class Solution {
    string expression;
    int index = 0;

    set<string> concatenate(const set<string>& left, const set<string>& right) {
        set<string> result;

        for (const string& first : left) {
            for (const string& second : right) {
                result.insert(first + second);
            }
        }

        return result;
    }

    set<string> parseConcatenation() {
        set<string> result = {""};

        while (index < expression.size() &&
               expression[index] != ',' &&
               expression[index] != '}') {
            set<string> current;

            if (islower(expression[index])) {
                current.insert(string(1, expression[index]));
                index++;
            } else {
                index++;
                current = parseUnion();
                index++;
            }

            result = concatenate(result, current);
        }

        return result;
    }

    set<string> parseUnion() {
        set<string> result = parseConcatenation();

        while (index < expression.size() && expression[index] == ',') {
            index++;

            set<string> nextPart = parseConcatenation();
            result.insert(nextPart.begin(), nextPart.end());
        }

        return result;
    }

public:
    vector<string> braceExpansionII(string expression) {
        this->expression = expression;

        set<string> expandedWords = parseUnion();

        return vector<string>(expandedWords.begin(), expandedWords.end());
    }
};