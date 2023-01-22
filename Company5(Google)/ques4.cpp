class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, int n, int m, bool &res){
        if(grid[i][j]==1){
            return;
        }

        if(i==0 || i==n-1 || j==0 || j==m-1){
            res = false;
            return;
        }

        grid[i][j] = 1;

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        for(int k=0; k<4; k++){
            int x = i+dx[k];
            int y = j+dy[k];

            dfs(x,y,grid,n,m,res);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(n==1 || m==1){
            return 0;
        }

        int cnt = 0;

        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(grid[i][j]==0){
                    bool res = true;
                    dfs(i,j,grid,n,m,res);
                    if(res)cnt++;
                }
            }
        }

        return cnt;
    }
};