class Solution {
    vector<vector<int>> combinations;
    vector<int> currentCombination;

    void backtrack(const vector<int>& candidates, int remainingTarget, int startIndex) {
        if (remainingTarget == 0) {
            combinations.push_back(currentCombination);
            return;
        }

        for (int index = startIndex; index < candidates.size(); ++index) {
            if (candidates[index] > remainingTarget) {
                break;
            }

            currentCombination.push_back(candidates[index]);
            backtrack(candidates, remainingTarget - candidates[index], index);
            currentCombination.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return combinations;
    }
};