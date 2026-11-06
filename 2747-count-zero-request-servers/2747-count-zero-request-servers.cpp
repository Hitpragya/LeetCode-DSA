class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int queryCount = queries.size();
        vector<int> queryIndices(queryCount);
        iota(queryIndices.begin(), queryIndices.end(), 0);

        sort(queryIndices.begin(), queryIndices.end(), [&](int a, int b) {
            return queries[a] < queries[b];
        });

        vector<int> serverRequestCount(n + 1, 0);
        vector<int> zeroRequestServers(queryCount);
        int activeServers = 0;
        int left = 0, right = 0;

        for (int queryIndex : queryIndices) {
            int queryTime = queries[queryIndex];
            int windowStart = queryTime - x;

            while (right < logs.size() && logs[right][1] <= queryTime) {
                int serverId = logs[right][0];
                if (serverRequestCount[serverId] == 0) {
                    activeServers++;
                }
                serverRequestCount[serverId]++;
                right++;
            }

            while (left < right && logs[left][1] < windowStart) {
                int serverId = logs[left][0];
                serverRequestCount[serverId]--;
                if (serverRequestCount[serverId] == 0) {
                    activeServers--;
                }
                left++;
            }

            zeroRequestServers[queryIndex] = n - activeServers;
        }

        return zeroRequestServers;
    }
};