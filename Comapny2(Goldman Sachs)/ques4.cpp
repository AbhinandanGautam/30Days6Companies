class Solution {
public:

    double dis(vector<int> &x, vector<int>&y){
        int x1 = x[0];
        int y1 = x[1];
        int x2 = y[0];
        int y2 = y[1];

        double dx = x2-x1;
        double dy = y2-y1;

        return sqrt((dx*dx)+(dy*dy));
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int cnt = 0;
        int n = points.size();

        for(int i=0; i<n; i++){
            unordered_map<double,int> mp;
            for(int j=0; j<n; j++){
                mp[dis(points[i],points[j])]++;
            }

            for(auto i:mp){
                int val = i.second;
                cnt += (val*(val-1));
            }
        }

        return cnt;
    }
};