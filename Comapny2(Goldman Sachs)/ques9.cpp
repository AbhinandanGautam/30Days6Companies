class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        unordered_map<int,int> mp;

        for(int i=0;i<n; i++){
            string s = to_string(nums[i]);
            reverse(s.begin(),s.end());
            arr[i] = nums[i] - stoi(s);
            mp[arr[i]]++;
        }

        long long ans = 0;

        for(auto i:mp){
            long long v = i.second;
            ans += ((v*(v-1))/2);
            ans = ans % 1000000007;
        }

        return ans;
    }
};