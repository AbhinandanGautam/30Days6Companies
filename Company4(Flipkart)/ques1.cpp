class Solution {
public:
    map<vector<int>,int>state;
    int noOffers(vector<int>&price, vector<int>&needs){
        int totalPrice = 0;
        for(int i = 0; i < price.size(); i++)
            totalPrice += price[i] * needs[i];
        return totalPrice;
    }

    void subtractOffer(vector<int>&offer, vector<int>&needs){
        for(int i = 0; i < needs.size(); i++)
            needs[i] -= offer[i];
    }

    bool noNegativeNeed(vector<int>&needs){
        for(auto need : needs) 
            if(need < 0) 
                return false;
        return true;
    }

    void addOffer(vector<int>&offer, vector<int>&needs){
        for(int i = 0; i < needs.size(); i++)
            needs[i] += offer[i];
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
        if(state[needs]) return state[needs];
        int bestPrice = noOffers(price, needs);     
        for(auto offer : special){
            subtractOffer(offer, needs);
            if(noNegativeNeed(needs)){
                int withOffer = offer.back() + shoppingOffers(price, special, needs);
                bestPrice = min(bestPrice , withOffer);
            }
            addOffer(offer, needs);
        }
        return state[needs] = bestPrice;
    }
};