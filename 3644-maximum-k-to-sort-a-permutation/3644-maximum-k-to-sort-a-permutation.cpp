class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        
        int k = INT_MAX;
        int n = nums.size();

        if(is_sorted(nums.begin(), nums.end())) return 0;

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        for(int i = 0; i < n; i++){
            if(nums[i] != sorted[i]) k = k & nums[i];
        }

        return k;
    }
};