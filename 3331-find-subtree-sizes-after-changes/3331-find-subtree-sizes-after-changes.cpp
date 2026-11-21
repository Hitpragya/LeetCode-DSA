class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> originalChildren(n);
        vector<vector<int>> finalChildren(n);
        vector<int> newParent = parent;
        vector<int> answer(n, 1);
        array<int, 26> lastSeen;
        lastSeen.fill(-1);

        for (int node = 1; node < n; ++node) {
            originalChildren[parent[node]].push_back(node);
        }

        function<void(int)> assignParents = [&](int node) {
            int previousSeen = lastSeen[s[node] - 'a'];
            if (previousSeen != -1) {
                newParent[node] = previousSeen;
            }

            lastSeen[s[node] - 'a'] = node;

            for (int child : originalChildren[node]) {
                assignParents(child);
            }

            lastSeen[s[node] - 'a'] = previousSeen;
        };

        assignParents(0);

        for (int node = 1; node < n; ++node) {
            finalChildren[newParent[node]].push_back(node);
        }

        function<void(int)> computeSizes = [&](int node) {
            for (int child : finalChildren[node]) {
                computeSizes(child);
                answer[node] += answer[child];
            }
        };

        computeSizes(0);
        return answer;
    }
};