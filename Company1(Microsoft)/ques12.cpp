class Solution {
public:
    long long cnt;

    void checkCount(vector<int>& nums, int st, int mid, int end, int diff){
        int lo = st;
        int hi = mid+1;

        while(lo<=mid && hi<=end){
            if(nums[lo]<=(nums[hi]+diff)){
                cnt += (end-hi+1);
                lo++;
            }
            else{
                hi++;
            }
        }
        sort(nums.begin()+st, nums.begin()+end+1);
    }

    void mergeSort(vector<int>& nums, int st, int end, int diff){
        if(st==end){
            return;
        }

        int mid = (st+end)/2;

        mergeSort(nums,st,mid,diff);
        mergeSort(nums,mid+1,end,diff);

        checkCount(nums,st,mid,end,diff);
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        cnt = 0;

        vector<int> c(n);
        for(int i=0; i<n; i++){
            c[i] = nums1[i]-nums2[i];
        }

        mergeSort(c,0,n-1,diff);

        return cnt;
    }
};