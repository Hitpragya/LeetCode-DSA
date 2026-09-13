class FenwickTree {
    vector<int> tree;

public:
    FenwickTree(int size) : tree(size + 1, 0) {}

    void add(int index, int value) {
        while (index < tree.size()) {
            tree[index] += value;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;

        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }

        return sum;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int length = nums.size();
        int offset = length + 1;
        FenwickTree frequencyTree(2 * length + 3);

        long long majoritySubarrayCount = 0;
        int prefixSum = 0;

        frequencyTree.add(offset, 1);

        for (int value : nums) {
            prefixSum += (value == target ? 1 : -1);

            int compressedIndex = prefixSum + offset;

            majoritySubarrayCount += frequencyTree.query(compressedIndex - 1);

            frequencyTree.add(compressedIndex, 1);
        }

        return majoritySubarrayCount;
    }
};