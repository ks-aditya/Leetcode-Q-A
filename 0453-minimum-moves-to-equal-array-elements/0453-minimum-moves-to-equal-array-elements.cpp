class Solution {
public:
    
    int minMoves(vector<int>& nums) {

        int steps = 0;

        int minEl = *min_element(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            steps += (nums[i] - minEl);
        }

       return steps;
    }
};