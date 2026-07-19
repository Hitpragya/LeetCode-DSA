class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = sqrt(c);

        while (left <= right) {
            long long squareSum = left * left + right * right;

            if (squareSum == c) {
                return true;
            }

            if (squareSum < c) {
                left++;
            } else {
                right--;
            }
        }

        return false;
    }
};