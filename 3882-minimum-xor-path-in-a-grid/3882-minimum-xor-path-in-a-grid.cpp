class Solution {
public:
    int m,n;
    vector<vector<vector<bool>>> visited;
    int result = INT_MAX;

    void solve(int i, int j, int score, vector<vector<int>>& grid){

        if(i >= m || j >= n) return;

        score = score ^ grid[i][j];

        if(visited[i][j][score]) return;
        
        visited[i][j][score] = true;

        if( i == m-1 && j == n-1 ){
            result = min(result, score);
            return;
        }
        
        solve(i, j+1, score, grid);
        solve(i+1, j, score, grid);
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<vector<bool>>(n, vector<bool>(1024, false)));

        solve(0, 0, 0, grid);

        return result;
    }
};