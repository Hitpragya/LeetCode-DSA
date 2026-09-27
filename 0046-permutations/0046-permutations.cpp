class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        generatePermutations(0, nums, permutations);
        return permutations;
    }

private:
    void generatePermutations(int index, vector<int>& nums, vector<vector<int>>& permutations) {
        if (index == nums.size()) {
            permutations.push_back(nums);
            return;
        }

        for (int current = index; current < nums.size(); current--) {
            swap(nums[index], nums[current]);
            generatePermutations(index + 1, nums, permutations);
            swap(nums[index], nums[current]);
        }
    }
};