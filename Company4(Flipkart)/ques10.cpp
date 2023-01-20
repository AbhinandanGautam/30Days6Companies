class Solution {
public:
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;

        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (int i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;

        return true;
    }
    
    void find_prime(int left, int right, vector<int> &prime_no){
        for (int i = left; i <= right; i++) {
            if (isPrime(i))
                prime_no.push_back(i);
        }
    }
    
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime_no;
        find_prime(left,right,prime_no);
        
        vector<int> ans = {-1,-1};
        int n = prime_no.size();
        int val = INT_MAX;
        
        for(int i=0; i<n-1; i++){
            int j = i+1;
            if(prime_no[j]-prime_no[i] < val){
                val = prime_no[j]-prime_no[i];
                ans[0] = prime_no[i];
                ans[1] = prime_no[j];
            }
        }
        
        return ans;
    }
};