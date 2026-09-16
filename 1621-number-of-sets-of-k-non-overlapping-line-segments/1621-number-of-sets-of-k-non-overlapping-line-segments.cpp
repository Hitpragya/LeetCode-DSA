class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    long long modPow(long long base, long long exponent) {
        long long result = 1;

        while (exponent > 0) {
            if (exponent & 1) {
                result = result * base % MOD;
            }

            base = base * base % MOD;
            exponent >>= 1;
        }

        return result;
    }

    int numberOfSets(int n, int k) {
        int total = n + k - 1;
        int choose = 2 * k;

        vector<long long> factorial(total + 1, 1);
        vector<long long> inverseFactorial(total + 1, 1);

        for (int value = 1; value <= total; ++value) {
            factorial[value] = factorial[value - 1] * value % MOD;
        }

        inverseFactorial[total] = modPow(factorial[total], MOD - 2);

        for (int value = total; value >= 1; --value) {
            inverseFactorial[value - 1] = inverseFactorial[value] * value % MOD;
        }

        return factorial[total] * inverseFactorial[choose] % MOD *
               inverseFactorial[total - choose] % MOD;
    }
};