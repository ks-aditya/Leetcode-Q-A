class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        long long mod = 1e9 + 7;

        vector<pair<int, int>> arr(nums1.size());

        for (int i = 0; i < nums1.size(); i++) {
            arr[i] = {nums1[i], nums0[i]};
        }

        sort(arr.begin(), arr.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 // 1. Segments containing only 1s come first
                 if (a.second == 0 || b.second == 0) {
                     if (a.second == 0 && b.second != 0)
                         return true;
                     if (b.second == 0 && a.second != 0)
                         return false;
                     return a.first > b.first;
                 }

                 // 2. Segments containing only 0s come last
                 if (a.first == 0 || b.first == 0) {
                     if (a.first == 0 && b.first != 0)
                         return false;
                     if (b.first == 0 && a.first != 0)
                         return true;
                     return a.second < b.second;
                 }

                 // 3. Both contain 1s and 0s - 1's descending and 0's ascending.
                 if (a.first != b.first)
                     return a.first > b.first;

                 return a.second < b.second;
             });

        long long ans = 0;
        long long exp2 = 1;

        for (int item = arr.size() - 1; item >= 0; item--) {

            // Process zeros first: they occupy bit positions
            for (int i = 0; i < arr[item].second; i++)
                exp2 = (exp2 * 2) % mod;

            // Process ones: add their positional values
            for (int i = 0; i < arr[item].first; i++) {
                ans = (ans + exp2) % mod;
                exp2 = (exp2 * 2) % mod;
            }
        }

        return ans;
    }
};