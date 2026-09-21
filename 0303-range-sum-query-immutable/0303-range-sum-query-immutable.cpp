class NumArray {
private:
    vector<long long> prefixSum;

public:
    NumArray(vector<int>& nums) {
        prefixSum.resize(nums.size() + 1);

        for (int index = 0; index < nums.size(); index++) {
            prefixSum[index + 1] = prefixSum[index] + nums[index];
        }
    }

    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }
};