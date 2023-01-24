class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int sum = 0;
                for(int r=i-k; r<=i+k; r++){
                    if(r<0 || r>=n){
                        continue;
                    }
                    for(int c=j-k; c<=j+k; c++){
                        if(c<0 || c>=m){
                            continue;
                        }
                        sum += mat[r][c];
                    }
                }
                ans[i][j] = sum;
            }
        }

        return ans;
    }
};