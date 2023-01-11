class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        priority_queue<int,vector<int>> pq;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pq.push(grid[i][j]);
                int up = i-1;
                int down = i+1;
                int right = j+2;
                int next = j+1;
                while(next<m && right<m && up>=0 && down<n){
                    int sum = 0;

                    for(int k=i,l=j; k>=up && l<=next; k--,l++){
                        sum += grid[k][l];    
                    }

                    for(int k=i+1,l=j+1; k<=down && l<=next; k++,l++){
                        sum += grid[k][l];
                    }

                    for(int k=i,l=right; k>up && l>next; k--,l--){
                        sum += grid[k][l];    
                    }

                    for(int k=i+1,l=right-1; k<down && l>next; k++,l--){
                        sum += grid[k][l];    
                    }

                    pq.push(sum);
                    up--;
                    down++;
                    next++;
                    right+=2;
                }
            }
        }

        vector<int> ans;
        set<int> s;

        while(!pq.empty() && s.size()<3){
            s.insert(pq.top());
            pq.pop();
        }

        set<int>::reverse_iterator rit;
        for (rit = s.rbegin(); rit != s.rend(); rit++)
            ans.push_back(*rit);

        return ans;
    }
};