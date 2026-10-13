class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        if(nums.size() == 1) return nums[0]*nums[0];

        long long ans = 0;

        for(int i = 0; i<nums.size(); i++) nums[i] = abs(nums[i]);

        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size()-1;

        while(i<=j){
            if(i==j) ans+=nums[j]*nums[j];
            else ans = ans + (nums[j]*nums[j] - nums[i]*nums[i]);
            i++;
            j--;
        }

        return ans;
    }
};