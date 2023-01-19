class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        int n = order.size();

        for(int i=0; i<n; i++){
            mp[order[i]] = i;
        }

        vector<string> v(n,"");
        string temp = "";
        int m = s.size();

        for(int i=0; i<m; i++){
            if(mp.find(s[i])!=mp.end()){
                v[mp[s[i]]] += s[i];
            }
            else{
                temp += s[i];
            }
        }

        string ans = "";

        for(auto i:v){
            ans += i;
        }
        ans += temp;

        return ans;
    }
};