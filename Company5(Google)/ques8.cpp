class Solution {
public:
    int find_sum(int r, int c, vector<vector<int>> &prefixSum){
        if(r<0 || c<0){
            return 0;
        }
        if(r>=prefixSum.size()) r = prefixSum.size()-1;
        if(c>=prefixSum[0].size()) c = prefixSum[0].size()-1;
        return prefixSum[r][c];
    }

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> prefixSum(n,vector<int>(m));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                prefixSum[i][j] = mat[i][j] + find_sum(i-1,j,prefixSum) + find_sum(i,j-1,prefixSum) - find_sum(i-1,j-1,prefixSum);
            }
        }

        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[i][j] = find_sum(i+k,j+k,prefixSum) - find_sum(i+k,j-k-1,prefixSum) - find_sum(i-k-1,j+k,prefixSum) + find_sum(i-k-1,j-k-1,prefixSum);
            }
        }

        return ans;
    }
};