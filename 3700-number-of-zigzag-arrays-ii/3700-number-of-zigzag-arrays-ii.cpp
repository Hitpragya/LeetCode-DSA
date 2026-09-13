class Solution {
    static constexpr long long MOD = 1000000007;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& first, const Matrix& second) {
        int size = first.size();
        Matrix product(size, vector<long long>(size));

        for (int row = 0; row < size; ++row) {
            for (int middle = 0; middle < size; ++middle) {
                if (first[row][middle] == 0) continue;

                for (int column = 0; column < size; ++column) {
                    product[row][column] = (product[row][column] +
                        first[row][middle] * second[middle][column]) % MOD;
                }
            }
        }

        return product;
    }

    Matrix matrixPower(Matrix base, long long exponent) {
        int size = base.size();
        Matrix result(size, vector<long long>(size));

        for (int index = 0; index < size; ++index) {
            result[index][index] = 1;
        }

        while (exponent > 0) {
            if (exponent & 1) {
                result = multiply(result, base);
            }

            base = multiply(base, base);
            exponent >>= 1;
        }

        return result;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int valueCount = r - l + 1;
        int stateCount = 2 * valueCount;

        Matrix transition(stateCount, vector<long long>(stateCount));

        for (int current = 0; current < valueCount; ++current) {
            for (int next = 0; next < current; ++next) {
                transition[valueCount + next][current] = 1;
            }

            for (int next = current + 1; next < valueCount; ++next) {
                transition[next][valueCount + current] = 1;
            }
        }

        Matrix poweredTransition = matrixPower(transition, n - 1);
        vector<long long> initialState(stateCount, 1);
        long long answer = 0;

        for (int row = 0; row < stateCount; ++row) {
            long long ways = 0;

            for (int column = 0; column < stateCount; ++column) {
                ways = (ways + poweredTransition[row][column] * initialState[column]) % MOD;
            }

            answer = (answer + ways) % MOD;
        }

        return answer;
    }
};