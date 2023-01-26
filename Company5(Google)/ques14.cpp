typedef unsigned long long ULL;
const int N = 2010, P = 131;
ULL p[N], h[N];

class Solution {
public:
    ULL find(int l, int r) {
        return h[r] - h[l-1]*p[r-l+1];
    }
    int distinctEchoSubstrings(string s) {
        int n = s.size();
        p[0] = 1;
        for(int i=0; i<n; i++) {
            p[i+1] = p[i]*P;
            h[i+1] = h[i]*P + s[i];
        }
        unordered_set<ULL> hash;
        for(int i=1; i<=n; i++) {
            for(int len=1; i+len*2-1<=n; len++) {
                auto left = find(i, i+len-1);
                auto right = find(i+len, i+len*2-1);
                if(left == right) hash.insert(left);
            }
        }
        return hash.size();
    }
};