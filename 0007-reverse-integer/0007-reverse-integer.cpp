class Solution {
public:
    int reverse(int x) {
        int reversedNumber = 0;

        while (x != 0) {
            int digit = x % 10;

            if (reversedNumber > INT_MAX / 10 ||
                (reversedNumber == INT_MAX / 10 && digit > 7)) {
                return 0;
            }

            if (reversedNumber < INT_MIN / 10 ||
                (reversedNumber == INT_MIN / 10 && digit < -8)) {
                return 0;
            }

            reversedNumber = reversedNumber * 10 + digit;
            x /= 10;
        }

        return reversedNumber;
    }
};