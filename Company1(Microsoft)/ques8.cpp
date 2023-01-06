class Solution {
public:
    int numberOfSubstrings(string s) {
        int a_c = 0;
        int b_c = 0;
        int c_c = 0;

        int i=0;
        int j=0;
        int n = s.size();
        int ans = 0;

        while(i<n){

            if(s[i]=='a'){
                a_c++;
            }
            else if(s[i]=='b'){
                b_c++;
            }
            else{
                c_c++;
            }

            if(a_c && b_c && c_c){
                ans++;
                ans += (n-i-1);

                while(j<i){
                    if(s[j]=='a'){
                        a_c--;
                    }
                    else if(s[j]=='b'){
                        b_c--;
                    }
                    else{
                        c_c--;
                    }
                    j++;

                    if(a_c && b_c && c_c){
                        ans++;
                        ans += (n-i-1);
                    }
                    else{
                        break;
                    }
                }
            }

            i++;
        }

        return ans;
    }
};