class Solution {
public:
    typedef long long ll;
    ll mod = 1e9 + 7;

    vector<vector<ll>> PascalTriangle;

    int solve(vector<int> &arr){
        int n = arr.size();

        if(n<3) return 1;

        vector<int> leftarr, rightarr;

        int root = arr[0];

        for(int i = 1; i < n; i++){
            if(arr[i] <= root) leftarr.push_back(arr[i]);
            else rightarr.push_back(arr[i]);
        }

        ll x = solve(leftarr) % mod;
        ll y = solve(rightarr) % mod;

        ll z = PascalTriangle[n-1][leftarr.size()];

        return (((x*y) % mod)*z) % mod;

    }

    int numOfWays(vector<int>& nums) {

        int n = nums.size();
        PascalTriangle.resize(n+1);  // no. of rows.

        for(int i = 0; i <= n; i++){
            PascalTriangle[i] = vector<ll> (i+1, 1);   // all columns of each row.

            for(int j = 1; j < i; j++){         //updating each value in each column of the row.
                PascalTriangle[i][j] = (PascalTriangle[i-1][j] + PascalTriangle[i-1][j-1])% mod;
            }
        }

        return (solve(nums) - 1) % mod;
    }
};