class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> matchingIndex(n);
        stack<int> openParentheses;

        for (int index = 0; index < n; index++) {
            if (s[index] == '(') {
                openParentheses.push(index);
            } else if (s[index] == ')') {
                int openingIndex = openParentheses.top();
                openParentheses.pop();

                matchingIndex[index] = openingIndex;
                matchingIndex[openingIndex] = index;
            }
        }

        string result;
        int index = 0;
        int direction = 1;

        while (index >= 0 && index < n) {
            if (s[index] == '(' || s[index] == ')') {
                index = matchingIndex[index];
                direction = -direction;
            } else {
                result += s[index];
            }

            index += direction;
        }

        return result;
    }
};