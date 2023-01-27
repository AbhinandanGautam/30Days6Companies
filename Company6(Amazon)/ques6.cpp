class Solution {
public:
    static bool Cmp(pair<int,string> p1, pair<int,string> p2){
        if(p1.first==p2.first){
            return p1.second < p2.second;
        }
        return p1.first>p2.first;
    }

    vector<vector<string>> mostPopularCreator(vector<string>& c, vector<string>& id, vector<int>& v) {
        unordered_map<string,vector<pair<int,string>>> mp;
        int n = c.size();

        for(int i=0; i<n; i++){
            mp[c[i]].push_back({v[i],id[i]});
        }

        vector<string> names;
        int val = INT_MIN;

        for(auto &i:mp){
            long long int sum = 0;
            sort(i.second.begin(),i.second.end(),Cmp);
            for(auto j:i.second){
                sum += j.first;
            }

            if(sum>val){
                names.clear();
                val = sum;
                names.push_back(i.first);
            }
            else if(sum==val){
                names.push_back(i.first);
            }
        }

        vector<vector<string>> ans;

        for(auto i:names){
            ans.push_back({i,mp[i].front().second});
        }

        return ans;
    }
};