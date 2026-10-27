class Solution {
public:
    
    vector<string> createGrid(int m, int n) {
        
        string topRow(n, '.');
        string remaining = string(n-1, '#') + '.';

        vector <string> ans(m);
    
        for(int i = 0; i < m; i++){
            ans[i] = (i==0? topRow : remaining);
        }
        
        return ans;
    }
};