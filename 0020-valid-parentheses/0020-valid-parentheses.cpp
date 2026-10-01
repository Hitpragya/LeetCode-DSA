class Solution {
public:
    bool isValid(string s) {
        stack<char> expectedClosing;

        for (char bracket : s) {
            if (bracket == '(') {
                expectedClosing.push(')');
            } else if (bracket == '[') {
                expectedClosing.push(']');
            } else if (bracket == '{') {
                expectedClosing.push('}');
            } else {
                if (expectedClosing.empty() || expectedClosing.top() != bracket) {
                    return false;
                }

                expectedClosing.pop();
            }
        }

        return expectedClosing.empty();
    }
};