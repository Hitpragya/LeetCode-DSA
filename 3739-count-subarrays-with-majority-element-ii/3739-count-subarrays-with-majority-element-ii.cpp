class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int offset = n + 2;
        vector<int> fenwick(2 * n + 5, 0);

        auto update = [&](int index) {
            while (index < (int)fenwick.size()) {
                fenwick[index]++;
                index += index & -index;
            }
        };

        auto query = [&](int index) {
            long long result = 0;
            while (index > 0) {
                result += fenwick[index];
                index -= index & -index;
            }
            return result;
        };

        long long answer = 0;
        int balance = 0;

        update(offset);

        for (int value : nums) {
            if (value == target) {
                balance++;
            } else {
                balance--;
            }

            int index = balance + offset;
            answer += query(index - 1);
            update(index);
        }

        return answer;
    }
};