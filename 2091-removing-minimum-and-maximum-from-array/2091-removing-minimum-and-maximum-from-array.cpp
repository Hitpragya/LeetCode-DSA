class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIndex = 0;
        int maxIndex = 0;

        for (int index = 0; index < n; index++) {
            if (nums[index] < nums[minIndex]) {
                minIndex = index;
            }

            if (nums[index] > nums[maxIndex]) {
                maxIndex = index;
            }
        }

        int leftIndex = min(minIndex, maxIndex);
        int rightIndex = max(minIndex, maxIndex);

        int removeFromFront = rightIndex + 1;
        int removeFromBack = n - leftIndex;
        int removeFromBothEnds = (leftIndex + 1) + (n - rightIndex);

        return min(removeFromFront, min(removeFromBack, removeFromBothEnds));
    }
};