class Solution {
public:
    int nextNumber(int number) {
        int sumOfSquares = 0;

        while (number > 0) {
            int digit = number % 10;
            sumOfSquares += digit * digit;
            number /= 10;
        }

        return sumOfSquares;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = nextNumber(slow);
            fast = nextNumber(nextNumber(fast));
        } while (slow != fast);

        return slow == 1;
    }
};