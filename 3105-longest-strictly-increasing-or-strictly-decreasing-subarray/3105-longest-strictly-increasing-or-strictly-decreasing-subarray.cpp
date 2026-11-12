class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int maxlength = 1;

        for(int i = 0; i < nums.size(); i++){

            int inc = 1;
            int dec = 1;

            for(int j = i + 1; j < nums.size(); j++){

                if(nums[j] > nums[j-1] && dec == 1) inc++;
                else if(nums[j] < nums[j-1] && inc == 1) dec++;
                else break;
            }

            maxlength = max({maxlength, inc, dec});
        }

        return maxlength;
    }
};