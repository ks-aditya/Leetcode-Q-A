class Solution {
public:
    int rows, columns;

    bool checkIsland( int i, int j, vector<vector<int>>& grid){

        if( i < 0 || i >= rows || j < 0 || j >= columns)
            return false;   // if we touched the border, then not a valid island.

        if(grid[i][j] == 1)
            return true;    // water/ land that we already have visited.

        grid[i][j] = 1;     // mark this cell as visited.

        bool left = checkIsland(i, j-1, grid);
        bool right = checkIsland(i, j+1, grid);
        bool top = checkIsland(i-1, j, grid);
        bool bottom = checkIsland(i+1, j, grid);

        return left && right && top && bottom;
    }

    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        columns = grid[0].size();
        int k = 0;

        for(int i = 1; i < rows - 1; i++){
            for(int j = 1; j < columns - 1; j++){

                if(grid[i][j] == 0){

                    if(checkIsland(i, j, grid)) k++;

                }

            }
        }

        return k;
    }
};