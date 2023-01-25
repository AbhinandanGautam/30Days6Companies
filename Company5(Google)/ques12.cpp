class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        reverse(piles.begin(),piles.end());

        int st = 0;
        int end = piles.size()-1;
        int as=0, bs=0, ms=0;

        while(st<end){
            as += piles[st];
            st++;

            ms += piles[st];
            st++;

            bs += piles[end];
            end--;
        }

        return ms;
    }
};