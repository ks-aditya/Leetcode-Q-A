class Solution {
public:
    int maxSum(vector<int>& nums, int k) {

        int mod = 1e9 + 7;

        vector<int> count (32,0);

        for(int num: nums){
            for(int b = 0; b<32; b++){
                if(num & (1LL<<b)) count[b]++;
            }
        }
        long long ans = 0;

        while(k--){
            long long curr = 0;
            for(int i=0; i<32; i++){
                if(count[i]>0){
                    curr = curr | (1LL<<i);
                    count[i]--;
                }
            }
            ans = (ans + (curr*curr)) % mod;
        }

        return ans%mod;
    }
};