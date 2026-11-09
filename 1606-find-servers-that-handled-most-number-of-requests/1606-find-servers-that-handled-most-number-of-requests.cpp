class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int totalRequests = arrival.size();
        vector<int> handledCount(k, 0);
        set<int> availableServers;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busyServers;

        for (int serverId = 0; serverId < k; ++serverId) {
            availableServers.insert(serverId);
        }

        for (int requestIndex = 0; requestIndex < totalRequests; ++requestIndex) {
            long long requestTime = arrival[requestIndex];
            long long finishTime = requestTime + load[requestIndex];

            while (!busyServers.empty() && busyServers.top().first <= requestTime) {
                availableServers.insert(busyServers.top().second);
                busyServers.pop();
            }

            if (availableServers.empty()) {
                continue;
            }

            int preferredServer = requestIndex % k;
            auto nextServer = availableServers.lower_bound(preferredServer);

            if (nextServer == availableServers.end()) {
                nextServer = availableServers.begin();
            }

            int assignedServer = *nextServer;
            availableServers.erase(nextServer);

            ++handledCount[assignedServer];
            busyServers.push({finishTime, assignedServer});
        }

        int maxHandled = *max_element(handledCount.begin(), handledCount.end());
        vector<int> busiestServers;

        for (int serverId = 0; serverId < k; ++serverId) {
            if (handledCount[serverId] == maxHandled) {
                busiestServers.push_back(serverId);
            }
        }

        return busiestServers;
    }
};