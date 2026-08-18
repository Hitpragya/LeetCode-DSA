class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        unordered_map<int, int> frequency;
        for (int value : nums) {
            frequency[value]++;
        }

        if (k == 1) {
            int answer = -1;

            for (int value : nums) {
                if (frequency[value] == 1) {
                    answer = max(answer, value);
                }
            }

            return answer;
        }

        int answer = -1;

        if (frequency[nums[0]] == 1) {
            answer = nums[0];
        }

        if (frequency[nums[n - 1]] == 1) {
            answer = max(answer, nums[n - 1]);
        }

        return answer;
    }
};