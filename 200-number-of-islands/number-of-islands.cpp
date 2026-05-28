class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        int m=grid.size();
        int n=grid[0].size();
        if(row<0||col<0||row>=m||col>=n||grid[row][col]=='0')
            return;
        grid[row][col]='0';
        dfs(grid,row+1,col);
        dfs(grid,row-1,col);
        dfs(grid,row,col+1);
        dfs(grid,row,col-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m =grid.size();
        int n =grid[0].size();
        int islands=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    dfs(grid,i,j);
                }
            }
        }
        return islands;
    }
};