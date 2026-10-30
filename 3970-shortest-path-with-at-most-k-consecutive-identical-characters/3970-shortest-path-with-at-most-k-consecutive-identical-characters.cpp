class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adjacency(n);

        for (const auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            adjacency[from].push_back({to, weight});
        }

        vector<vector<int>> bestDistance(n, vector<int>(k + 1, INT_MAX));
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > minHeap;

        bestDistance[0][1] = 0;
        minHeap.push({0, 0, 1});

        while (!minHeap.empty()) {
            auto [currentCost, node, consecutiveCount] = minHeap.top();
            minHeap.pop();

            if (currentCost > bestDistance[node][consecutiveCount]) {
                continue;
            }

            if (node == n - 1) {
                return currentCost;
            }

            for (const auto& [nextNode, edgeWeight] : adjacency[node]) {
                int nextCount = (labels[node] == labels[nextNode])
                                    ? consecutiveCount + 1
                                    : 1;

                if (nextCount > k) {
                    continue;
                }

                int nextCost = currentCost + edgeWeight;

                if (nextCost < bestDistance[nextNode][nextCount]) {
                    bestDistance[nextNode][nextCount] = nextCost;
                    minHeap.push({nextCost, nextNode, nextCount});
                }
            }
        }

        return -1;
    }
};