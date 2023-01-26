class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<vector<string>> v(n);

        for(int i=0; i<n; i++){
            string str = transactions[i];
            int j=0;
            string temp = "";
            while(j<str.size()){
                if(str[j]==','){
                    v[i].push_back(temp);
                    temp = "";
                }
                else{
                    temp += str[j];
                }
                j++;
            }
            v[i].push_back(temp);
        }

        vector<string> ans;
        set<int> idx;

        for(int i=0; i<n; i++){
            if(stoi(v[i][2])>1000){
                idx.insert(i);
            }
        }

        for(int i=0; i<n; i++){
            
            for(int j=i+1; j<n; j++){

                if(v[i][0]==v[j][0] && v[i][3]!=v[j][3] && abs(stoi(v[i][1])-stoi(v[j][1]))<=60){
                    idx.insert(i);
                    idx.insert(j);
                }
            }
        }


        for(auto i:idx){
            ans.push_back(transactions[i]);
        }

        return ans;
    }
};