class Solution {
public:
    typedef long long ll;
    int ans = 0;
    
    long long dfs( int i, int j, vector<vector<int>>& grid ){

        if( i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0) return 0;
        else if(grid[i][j] == 0) return 0;
        
        ll value = grid[i][j];
        grid[i][j] = 0;

        ll left = dfs(i, j-1, grid);
        ll right = dfs(i, j+1, grid);
        ll top = dfs(i-1, j, grid);
        ll bottom = dfs(i+1, j, grid);

        return ( value + left + right + top + bottom );

    }

    int countIslands(vector<vector<int>>& grid, int k) {
        ll sum = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){

                if(grid[i][j] != 0){
                    sum = dfs(i, j, grid);
                    if(sum % k == 0) ans++;
                }

            }
        }

        return ans;
    }
};