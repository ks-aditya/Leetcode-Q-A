class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty()) return 0;

        int longest = 0;
        int count = 1;

        sort(nums.begin(), nums.end());

        int i=0, j=1;
        while(j<nums.size()){
            if(nums[i]==nums[j]){
                i++;
                j++;
                continue;
            }
            else{
                if(nums[i]+1==nums[j]){
                    count++;
                }
                else{
                    if(count>longest) longest = count;
                    count = 1;
                }
                i++;
                j++;
            }
            
        }

        if(count>longest) return count;
        else return longest;
    }
};