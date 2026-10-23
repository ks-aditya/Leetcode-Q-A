class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        
        int k = INT_MAX;
        
        if(is_sorted(nums.begin(), nums.end())) return 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i) k = k & nums[i];
        }

        return k;
    }
};