class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> firstArray = {nums[0]};
        vector<int> secondArray = {nums[1]};

        for (int index = 2; index < nums.size(); ++index) {
            if (firstArray.back() > secondArray.back()) {
                firstArray.push_back(nums[index]);
            } else {
                secondArray.push_back(nums[index]);
            }
        }

        firstArray.insert(firstArray.end(), secondArray.begin(), secondArray.end());

        return firstArray;
    }
};