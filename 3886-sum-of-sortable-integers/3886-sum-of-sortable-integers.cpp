class Solution {
public:
    long long sortableIntegers(vector<int>& nums) {
        int arraySize = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        vector<int> frequency(100001, 0);
        long long sortableSum = 0;

        for (int blockSize = 1; blockSize <= arraySize; ++blockSize) {
            if (arraySize % blockSize != 0) continue;

            if (canSortByRotatingBlocks(nums, sortedNums, blockSize, frequency)) {
                sortableSum += blockSize;
            }
        }

        return sortableSum;
    }

private:
    bool canSortByRotatingBlocks(
        vector<int>& nums,
        vector<int>& sortedNums,
        int blockSize,
        vector<int>& frequency
    ) {
        int totalBlocks = nums.size() / blockSize;
        vector<int> touchedValues;

        for (int blockIndex = 0; blockIndex < totalBlocks; ++blockIndex) {
            int blockStart = blockIndex * blockSize;
            int circularDescents = 0;

            for (int offset = 0; offset < blockSize; ++offset) {
                int currentValue = nums[blockStart + offset];
                int nextValue = nums[blockStart + (offset + 1) % blockSize];

                if (currentValue > nextValue) {
                    ++circularDescents;
                }

                int expectedValue = sortedNums[blockStart + offset];

                ++frequency[currentValue];
                --frequency[expectedValue];

                touchedValues.push_back(currentValue);
                touchedValues.push_back(expectedValue);
            }

            bool blockIsValid = circularDescents <= 1;

            if (blockIsValid) {
                for (int value : touchedValues) {
                    if (frequency[value] != 0) {
                        blockIsValid = false;
                        break;
                    }
                }
            }

            for (int value : touchedValues) {
                frequency[value] = 0;
            }

            touchedValues.clear();

            if (!blockIsValid) {
                return false;
            }
        }

        return true;
    }
};