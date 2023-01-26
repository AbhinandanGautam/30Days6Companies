class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        map<vector<float>,set<vector<int>>> mp;
        
        int n = points.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                float dy = y2-y1;
                float dx = x2-x1;
                float y = y1;
                float x = x1;

                if(dx==0){
                    mp[{INT_MAX,x}].insert(points[i]);
                    mp[{INT_MAX,x}].insert(points[j]);
                    continue;
                }

                float slope = dy/dx;

                float intercept = y - (slope)*x;

                mp[{slope,intercept}].insert(points[i]);
                mp[{slope,intercept}].insert(points[j]);
            }
        }

        int ans = INT_MIN;

        for(auto i:mp){
            int temp = i.second.size();
            ans = max(ans,temp);
        }

        if(ans==INT_MIN){
            return 1;
        }

        return ans;
    }
};