class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int st = -1;
        int end = -1;

        for(int i=0; i<n; i++){
            if(nums[i]!=temp[i]){
                st = i;
                break;
            }
        }

        for(int i=n-1; i>=0; i--){
            if(nums[i]!=temp[i]){
                end = i;
                break;
            }
        }

        if(st==-1 && end==-1){
            return 0;
        }

        return end-st+1;
    }
};