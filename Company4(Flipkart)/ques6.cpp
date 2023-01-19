class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& curr_land_area){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0){
            return;
        }
        
        grid[i][j] = 0;
        curr_land_area++;
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        for(int k=0; k<4; k++){
            int x = i+dx[k];
            int y = j+dy[k];
            
            dfs(grid,x,y,curr_land_area);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int area = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    int curr_land_area = 0;
                    dfs(grid,i,j,curr_land_area);
                    area = max(area,curr_land_area);
                }
            }
        }
        
        return area;
    }
};