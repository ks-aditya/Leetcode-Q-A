class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        
        int minIdx = nums.size();
        for(int i = 0; i < nums.size(); i++){

            if(nums[i] <= 9 && nums[i] == i && i<=minIdx) return i;

            else if(nums[i] >= 9){

                int sum = 0;
                int a = nums[i];

                while(a>0){
                    sum += a%10;
                    a/=10;
                }
                if(sum == i) return i;
            }
        }
        return -1;
    }
};