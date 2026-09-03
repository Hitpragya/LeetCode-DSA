class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallestValue = *min_element(nums1.begin(), nums1.end());
        bool hasOdd = false;
        bool hasEven = false;

        for (int value : nums1) {
            if (value % 2 == 0) {
                hasEven = true;
            } else {
                hasOdd = true;
            }
        }

        return !hasOdd || !hasEven || smallestValue % 2 == 1;
    }
};