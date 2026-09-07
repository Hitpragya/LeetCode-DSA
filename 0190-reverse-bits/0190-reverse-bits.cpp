class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversedBits = 0;
        for (int bitIndex = 0; bitIndex < 32; bitIndex++) {
            reversedBits = (reversedBits << 1) | (n & 1);
            n >>= 1;
        }
        return reversedBits;
    }
};