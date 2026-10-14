class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int cumSum = 0;
        int ans = 0;

        unordered_map <int, int> mpp;
        mpp.insert({0,1});

        for(int i = 0; i<nums.size(); i++){

            cumSum += nums[i];

            if(mpp.find(cumSum - k) != mpp.end()){
                ans += mpp[cumSum - k];
            }

            mpp[cumSum]++;
        }

        return ans;
    }
};