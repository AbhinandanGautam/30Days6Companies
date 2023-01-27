class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int res = INT_MIN;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                res = max(res, grid[i][j]+grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1]+grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1]);
            }
        }

        return res;
    }
};