class Solution {
public:
    vector<vector<vector<int>>> dp;

    bool validScore(int i, int j, int s, int ti, int tj, vector<vector<char>>& m){
        
        m[i][j] == '(' ? s+=1 :  s-=1;
        
        if (s<0) return false;

        else if (i==ti && j==tj) return s==0;
        
        if ( dp[i][j][s] != -1) return dp[i][j][s];     //if particular score for particular row & col. already calculated, return it.

        else{               // if score not already calculated.
        
            bool down = (i+1<=ti) ? validScore(i+1,j,s,ti,tj,m) : false;
            bool right = (j+1<=tj) ? validScore(i,j+1,s,ti,tj,m) : false;

            bool ans = down | right;
            dp[i][j][s] = ans;   // so dp[i][j][s] can only store (1)-true or (0)-false, (-1)-indicates not caluclated yet.

            return ans;
        }
    }

    bool hasValidPath(vector<vector<char>>& m) {
        
        int i = 0,j = 0;
        int s = 0;

        int ti = m.size() - 1;
        int tj = m[0].size() - 1;

        if( ti == 0 && tj == 0) return false;
        if(m[i][j] == ')') return false;

        dp.assign(m.size(), vector<vector<int>>(m[0].size(), vector<int>(ti + tj + 2, -1)));
        return validScore(i, j, s, ti, tj, m);
    }
};