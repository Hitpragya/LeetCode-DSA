class Solution {
public:
    int hammingDistance(int x, int y) {
        int differentBits = x ^ y;
        int distance = 0;

        while (differentBits != 0) {
            differentBits &= (differentBits - 1);
            ++distance;
        }

        return distance;
    }
};