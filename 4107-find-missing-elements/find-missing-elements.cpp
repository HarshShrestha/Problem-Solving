class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> res;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]!=1){
                for(int j=nums[i-1]+1 ; j<nums[i];j++){
                    res.push_back(j);
                }
            }
        }
        return res;
    }
};