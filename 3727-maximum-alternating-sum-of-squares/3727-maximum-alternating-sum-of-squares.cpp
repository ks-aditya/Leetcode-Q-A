class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        if(nums.size() == 1) return nums[0]*nums[0];

        long long ans = 0;

        for(auto& it: nums) it = it*it;

        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = n-1; i>=0; i--){
            if(i>=n/2) ans += nums[i];
            else ans -= nums[i];
        }

        return ans;
    }
};