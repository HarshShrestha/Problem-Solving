class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n=nums.size(), ans =0;
        int l =0, r=0;
        while(r<n){
            mpp[nums[r]]++;
            while(mpp[nums[r]]>k){
                mpp[nums[l]]--;
                l++;
            }
            if(mpp[nums[r]]<=k) ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};