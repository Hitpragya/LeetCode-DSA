class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        vector<pair<int, long long>> constrainedBuildings;

        constrainedBuildings.push_back({1, 0});
        for (const auto& restriction : restrictions) {
            constrainedBuildings.push_back({restriction[0], restriction[1]});
        }
        constrainedBuildings.push_back({n, n - 1});

        sort(constrainedBuildings.begin(), constrainedBuildings.end());

        int totalConstraints = constrainedBuildings.size();

        for (int i = 1; i < totalConstraints; i++) {
            long long previousHeight = constrainedBuildings[i - 1].second;
            long long distance = constrainedBuildings[i].first - constrainedBuildings[i - 1].first;

            constrainedBuildings[i].second = min(
                constrainedBuildings[i].second,
                previousHeight + distance
            );
        }

        for (int i = totalConstraints - 2; i >= 0; i--) {
            long long nextHeight = constrainedBuildings[i + 1].second;
            long long distance = constrainedBuildings[i + 1].first - constrainedBuildings[i].first;

            constrainedBuildings[i].second = min(
                constrainedBuildings[i].second,
                nextHeight + distance
            );
        }

        long long tallestHeight = 0;

        for (int i = 1; i < totalConstraints; i++) {
            long long leftPosition = constrainedBuildings[i - 1].first;
            long long rightPosition = constrainedBuildings[i].first;

            long long leftHeight = constrainedBuildings[i - 1].second;
            long long rightHeight = constrainedBuildings[i].second;

            long long distance = rightPosition - leftPosition;
            long long heightDifference = abs(leftHeight - rightHeight);

            long long extraHeight = (distance - heightDifference) / 2;
            long long currentPeak = max(leftHeight, rightHeight) + extraHeight;

            tallestHeight = max(tallestHeight, currentPeak);
        }

        return tallestHeight;
    }
};