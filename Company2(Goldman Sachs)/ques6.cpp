class Solution {
public:
    int func(vector<int>& v){
        int n = v.size();
        int val = INT_MAX;
        for(int i=1; i<n; i++){
            val = min(val,v[i]-v[i-1]+1);
        }
        return val;
    }

    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,vector<int>> mp;
        int n = cards.size();
        int cnt = INT_MAX;

        for(int i=0; i<n; i++){
            mp[cards[i]].push_back(i);
        }

        for(auto i:mp){
            if(i.second.size()>1){
                cnt = min(cnt,func(i.second));
            }
        }

        if(cnt==INT_MAX){
            return -1;
        }

        return cnt;
    }
};