class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int neg_cnt = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int minVal = INT_MAX;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                sum += abs(matrix[i][j]);

                if(matrix[i][j]<0){
                    neg_cnt++;
                }

                minVal = min(minVal,abs(matrix[i][j]));
            }
        }
        
        if(neg_cnt%2){
            return sum - (2*minVal);
        }

        return sum;
    }
};