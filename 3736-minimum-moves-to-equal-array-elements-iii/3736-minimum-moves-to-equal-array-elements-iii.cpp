class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxEl = *max_element(nums.begin(), nums.end());

        int steps = 0;

        for(int i = 0; i < nums.size(); i++){
            steps += (maxEl - nums[i]);
        }

        return steps;
    }
};