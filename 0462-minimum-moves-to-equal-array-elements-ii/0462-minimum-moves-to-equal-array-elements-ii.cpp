class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int midEl = nums[n/2];
        int steps = 0;

        for(int i = 0; i < n; i++){
            steps += (abs(nums[i] - midEl));
        }

        return steps;
    }
};