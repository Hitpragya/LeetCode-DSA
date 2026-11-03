class Solution {
public:
    char processStr(string s, long long k) {
        const long long LENGTH_LIMIT = 1000000000000000LL;
        long long length = 0;

        for (char operation : s) {
            if (islower(operation)) {
                ++length;
            } else if (operation == '*') {
                if (length > 0) {
                    --length;
                }
            } else if (operation == '#') {
                if (length < LENGTH_LIMIT) {
                    length *= 2;
                }
            }
        }

        if (k >= length) {
            return '.';
        }

        for (int index = s.size() - 1; index >= 0; --index) {
            char operation = s[index];

            if (islower(operation)) {
                if (k == length - 1) {
                    return operation;
                }
                --length;
            } else if (operation == '*') {
                ++length;
            } else if (operation == '#') {
                length /= 2;
                k %= length;
            } else {
                k = length - 1 - k;
            }
        }

        return '.';
    }
};