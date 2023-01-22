class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int n = fruits.size();
        int res = INT_MIN;
        int j = 0;

        for(int i=0; i<n; i++){
            if(mp.find(fruits[i])!=mp.end()){
                mp[fruits[i]]++;
            }
            else{
                if(mp.size()==2){
                    int sum = 0;
                    for(auto k:mp){
                        sum += k.second;
                    }
                    res = max(res,sum);
                }

                while(mp.size()==2){
                    mp[fruits[j]]--;
                    if(mp[fruits[j]]==0){
                        mp.erase(fruits[j]);
                    }
                    j++;
                }

                mp[fruits[i]]++;
            }
        }

        int sum = 0;
        for(auto k:mp){
            sum += k.second;
        }
        res = max(res,sum);

        return res;
    }
};