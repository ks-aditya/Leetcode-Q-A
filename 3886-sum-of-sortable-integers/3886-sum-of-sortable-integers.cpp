class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;
            int prevMax = INT_MIN;

            for (int s = 0; s < n && valid; s += k) {
                int e = s + k - 1;
                int mn = nums[s], mx = nums[s];
                int desc = 0;

                for (int i = s; i <= e; i++) {
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);

                    if (i < e && nums[i] > nums[i + 1])
                        desc++;
                }

                // Check the circular boundary
                if (nums[e] > nums[s]) desc++;

                // Must be rotatable and compatible with previous block
                if (desc > 1 || mn < prevMax) {
                    valid = false;
                    break;
                }

                prevMax = mx;
            }

            if (valid) ans += k;
        }

        return ans;
    }
};