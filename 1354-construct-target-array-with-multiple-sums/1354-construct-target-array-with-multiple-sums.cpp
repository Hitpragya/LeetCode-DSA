class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) {
            return target[0] == 1;
        }

        priority_queue<int> maxHeap(target.begin(), target.end());
        long long totalSum = accumulate(target.begin(), target.end(), 0LL);

        while (maxHeap.top() > 1) {
            long long largest = maxHeap.top();
            maxHeap.pop();

            long long remainingSum = totalSum - largest;

            if (remainingSum == 1) {
                totalSum = remainingSum + 1;
                maxHeap.push(1);
                continue;
            }

            long long previousValue = largest % remainingSum;

            if (previousValue == 0 || previousValue == largest) {
                return false;
            }

            totalSum -= largest - previousValue;
            maxHeap.push(previousValue);
        }

        return true;
    }
};