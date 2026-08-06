class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int x = n; x <= n + 9; x++) {
            int product = 1;
            int value = x;

            if (value == 0) {
                product = 0;
            } else {
                while (value > 1) {
                    int digit = value % 10;
                    product *= digit;
                    value /= 10;
                }
            }

            if (product % t == 0) {
                return x;
            }
        }
        return -1;
    }
};