class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long sum = 0, fn = 0;
        int len = nums.size();
        for(int i=0;i<len;i++) {
            sum += nums[i];
            fn += (i * nums[i]);
        }

        long st = 1, end;
        long newfn = fn;
        
        while(st < len) {
            end = st + len - 1;
            
            long removed = (st-1) * nums[st-1];
            long added = end * nums[end%len];
            
            newfn = newfn - removed + added - sum;
            
            fn = max(fn, newfn);
            
            st++;
        }
        
        return (int)fn;
    }
};