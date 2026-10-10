class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long m = (long long)k1 + k2;

        vector<int> freq(100001, 0);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            total += d;
        }

        if (m >= total) return 0;

        for (int d = 100000; d > 0 && m > 0; d--) {
            if (freq[d] == 0) continue;

            long long moves = min(m, (long long)freq[d]);

            freq[d] -= moves;
            freq[d - 1] += moves;
            m -= moves;
        }

        long long ans = 0;

        for (int d = 1; d <= 100000; d++) {
            ans += 1LL * d * d * freq[d];
        }

        return ans;
    }
};