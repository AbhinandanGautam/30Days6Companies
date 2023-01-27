class Solution {
public:

    int ans = INT_MIN;

    void func(int idx, string &s, unordered_set<string> &st, string temp){
        if(idx==s.size()){
            int val = st.size();
            ans = max(ans,val);
            return;
        }

        temp += s[idx];

        if(st.find(temp)==st.end()){
            func(idx+1,s,st,temp);
            st.insert(temp);
            func(idx+1,s,st,"");
            st.erase(temp);
        }
        else{
            func(idx+1,s,st,temp);
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        func(0,s,st,"");
        return ans;
    }
};