#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjacencyList(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjacencyList[u].push_back(v);
            adjacencyList[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int completeComponentsCount = 0;

        for (int node = 0; node < n; ++node) {
            if (visited[node]) {
                continue;
            }

            int vertexCount = 0;
            int degreeSum = 0;
            dfs(node, adjacencyList, visited, vertexCount, degreeSum);

            int edgeCount = degreeSum / 2;
            int expectedEdges = vertexCount * (vertexCount - 1) / 2;

            if (edgeCount == expectedEdges) {
                ++completeComponentsCount;
            }
        }

        return completeComponentsCount;
    }

private:
    void dfs(int node,
             const vector<vector<int>>& adjacencyList,
             vector<bool>& visited,
             int& vertexCount,
             int& degreeSum) {
        visited[node] = true;
        ++vertexCount;
        degreeSum += static_cast<int>(adjacencyList[node].size());

        for (int neighbor : adjacencyList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjacencyList, visited, vertexCount, degreeSum);
            }
        }
    }
};