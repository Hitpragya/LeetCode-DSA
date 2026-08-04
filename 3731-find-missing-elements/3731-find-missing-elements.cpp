class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        bool present[101] = {};
        int minimumValue = 101;
        int maximumValue = 0;

        for (int number : nums) {
            present[number] = true;
            minimumValue = min(minimumValue, number);
            maximumValue = max(maximumValue, number);
        }

        vector<int> missingElements;

        for (int number = minimumValue; number <= maximumValue; ++number) {
            if (!present[number]) {
                missingElements.push_back(number);
            }
        }

        return missingElements;
    }
};