class Solution {
private:
    vector<vector<int>> combinations;
    vector<int> currentCombination;

    void backtrack(int startNumber, int n, int k) {
        if (currentCombination.size() == k) {
            combinations.push_back(currentCombination);
            return;
        }

        int remainingSlots = k - currentCombination.size();
        int lastCandidate = n - remainingSlots + 1;

        for (int number = startNumber; number <= lastCandidate; ++number) {
            currentCombination.push_back(number);
            backtrack(number + 1, n, k);
            currentCombination.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return combinations;
    }
};