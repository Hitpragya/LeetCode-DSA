class Solution {
public:
    int maxLength(vector<int>& nums) {
        int primeMasks[11] = {0};

        int primes[4] = {2, 3, 5, 7};
        for (int value = 1; value <= 10; value++) {
            for (int bit = 0; bit < 4; bit++) {
                if (value % primes[bit] == 0) {
                    primeMasks[value] |= (1 << bit);
                }
            }
        }

        int left = 0;
        int windowMask = 0;
        int longest = 2;

        for (int right = 0; right < nums.size(); right++) {
            int currentMask = primeMasks[nums[right]];

            while (windowMask & currentMask) {
                windowMask &= ~primeMasks[nums[left]];
                left++;
            }

            windowMask |= currentMask;
            longest = max(longest, right - left + 1);
        }

        return longest;
    }
};