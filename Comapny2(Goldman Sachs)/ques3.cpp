class Solution {
public:
    int trailingZeroes(int n) {
        if(n==0){
            return 0;
        }
        int five_cnt = 0;
        int two_cnt = 0;

        for(int i=n; i>0; i--){
            int num = i;
            while(num>0 && (num%5==0 || num%2==0)){
                if(num%5==0){
                    five_cnt++;
                    num /= 5;
                }
                else if(num%2==0){
                    two_cnt++;
                    num /= 2;
                }
            }
        }

        return min(two_cnt,five_cnt);
    }
};