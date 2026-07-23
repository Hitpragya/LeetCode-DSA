#include <vector>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n < 3) {
            return n;
        }

        int nextPowerOfTwo = 1;

        while (nextPowerOfTwo <= n) {
            nextPowerOfTwo <<= 1;
        }

        return nextPowerOfTwo;
    }
};