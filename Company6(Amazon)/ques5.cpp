class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        int n = a.size();

        long long int m = mass;

        for(int i=0; i<n; i++){
            if(a[i]>m){
                return false;
            }
            else{
                m += a[i];
            }
        }

        return true;
    }
};