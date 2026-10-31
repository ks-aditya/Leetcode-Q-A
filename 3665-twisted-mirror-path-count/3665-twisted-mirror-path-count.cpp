class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;
    vector<vector<vector<int>>> memo;

    int solve(int i, int j, int dir, vector<vector<int>>& grid) {
        if (i >= m || j >= n) return 0;           // out of grid
        if (i == m - 1 && j == n - 1) return 1;   // reached end

        if (memo[i][j][dir] != -1) return memo[i][j][dir];

        int ans;
        if (grid[i][j] == 1) {                    // mirror: forced move
            if (dir == 0) ans = solve(i + 1, j, 1, grid);   // from left -> go down
            else          ans = solve(i, j + 1, 0, grid);   // from top  -> go right
        } else {                                  // empty: both moves
            ans = (solve(i + 1, j, 1, grid) + solve(i, j + 1, 0, grid)) % MOD;
        }
        return memo[i][j][dir] = ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memo.assign(m, vector<vector<int>>(n, vector<int>(2, -1)));
        return solve(0, 0, 0, grid);
    }
};