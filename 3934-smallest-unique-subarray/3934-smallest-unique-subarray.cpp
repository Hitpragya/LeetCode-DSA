class Solution {
    static constexpr long long MOD1 = 1'000'000'007LL;
    static constexpr long long MOD2 = 998'244'353LL;
    static constexpr long long BASE = 131LL;

    vector<long long> prefixHash1;
    vector<long long> prefixHash2;
    vector<long long> power1;
    vector<long long> power2;

    long long windowHash1(int start, int length) {
        long long hash = prefixHash1[start + length] - prefixHash1[start] * power1[length] % MOD1;
        hash %= MOD1;
        if (hash < 0) hash += MOD1;
        return hash;
    }

    long long windowHash2(int start, int length) {
        long long hash = prefixHash2[start + length] - prefixHash2[start] * power2[length] % MOD2;
        hash %= MOD2;
        if (hash < 0) hash += MOD2;
        return hash;
    }

    bool hasUniqueSubarray(int arraySize, int length, vector<int>& nums) {
        unordered_map<long long, int> hashFrequency;
        hashFrequency.reserve(2 * arraySize);

        for (int start = 0; start + length <= arraySize; start++) {
            long long firstHash = windowHash1(start, length);
            long long secondHash = windowHash2(start, length);
            long long combinedHash = firstHash * MOD2 + secondHash;
            hashFrequency[combinedHash]++;
        }

        for (const auto& [hashValue, frequency] : hashFrequency) {
            if (frequency == 1) {
                return true;
            }
        }

        return false;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int arraySize = nums.size();

        prefixHash1.assign(arraySize + 1, 0);
        prefixHash2.assign(arraySize + 1, 0);
        power1.assign(arraySize + 1, 1);
        power2.assign(arraySize + 1, 1);

        for (int index = 0; index < arraySize; index++) {
            prefixHash1[index + 1] = (prefixHash1[index] * BASE + nums[index]) % MOD1;
            prefixHash2[index + 1] = (prefixHash2[index] * BASE + nums[index]) % MOD2;

            power1[index + 1] = power1[index] * BASE % MOD1;
            power2[index + 1] = power2[index] * BASE % MOD2;
        }

        int low = 1;
        int high = arraySize;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (hasUniqueSubarray(arraySize, mid, nums)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};