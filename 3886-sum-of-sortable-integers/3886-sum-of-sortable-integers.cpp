

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;
            int prevmaxElement = INT_MIN;

            // Traverse each segment of length = k.
            for (int start = 0; start < n && valid; start += k) {
                int end = start + k - 1;
                int minElement = nums[start], maxElement = nums[start];
                int desc = 0;

                // In each segment, check minElement and maxElement elements.
                for (int i = start; i <= end; i++) {
                    minElement = min(minElement, nums[i]);
                    maxElement = max(maxElement, nums[i]);

                    if (i < end && nums[i] > nums[i + 1])
                        desc++;
                }

                // Check the circular boundary
                if (nums[end] > nums[start]) desc++;

                // Must be rotatable and compatible with previous block
                if (desc > 1 || minElement < prevmaxElement) {
                    valid = false;
                    break;
                }

                prevmaxElement = maxElement;
            }

            if (valid) ans += k;
        }

        return ans;
    }
};