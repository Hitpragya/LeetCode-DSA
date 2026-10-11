class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int arrayLength = nums.size();
        int specialSquareSum = 0;

        for (int position = 1; position <= arrayLength; position++) {
            if (arrayLength % position == 0) {
                int element = nums[position - 1];
                specialSquareSum += element * element;
            }
        }

        return specialSquareSum;
    }
};