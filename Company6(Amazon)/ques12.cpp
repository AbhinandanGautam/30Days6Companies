class Solution {
public:
    unordered_set<string> st_accept;
    unordered_set<string> st_not_accept;

    bool check(string s1, string s2){
        int i = s1.size()-1;
        int j = s2.size()-1;

        while(i>=0 && j>=0){
            if(s1[i]==s2[j]){
                j--;
            }
            i--;
        }
        
        if(j==-1){
            st_accept.insert(s2);
            return true;
        }

        st_not_accept.insert(s2);
        return false;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt = 0;
        
        for(auto i:words){
            if(st_not_accept.find(i)!=st_not_accept.end()){
                continue;
            }
            if(st_accept.find(i)!=st_accept.end() || check(s,i)){
                cnt++;
            }
        }

        return cnt;
    }
};