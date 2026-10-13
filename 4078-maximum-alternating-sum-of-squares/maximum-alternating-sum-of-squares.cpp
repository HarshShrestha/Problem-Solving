class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), comp);
        // for(auto & num : nums) cout<<num<<" ";
        // cout<<endl;
        long long sum =0 ;
        if(n%2==0){
            for(int i=0;i<n/2;i++){
            sum+= 1LL * abs(nums[i])* abs(nums[i]);
            // cout << "+"<< abs(nums[i])* abs(nums[i]) << " " ;
        }
        for(int i=n/2;i<n ;i++){
            sum -= 1LL * abs(nums[i])* abs(nums[i]);
            // cout << "-"<< abs(nums[i])* abs(nums[i]) << " " ;
        }
        }else{
            for(int i=0;i<=n/2;i++){
            sum+= 1LL * abs(nums[i])* abs(nums[i]);
            // cout << "+"<< abs(nums[i])* abs(nums[i]) << " " ;
        }
        for(int i=n/2+1;i<n ;i++){
            sum -= 1LL * abs(nums[i])* abs(nums[i]);
            // cout << "-"<< abs(nums[i])* abs(nums[i]) << " " ;
        }
        }
        return sum;
    }
    static bool comp(int a, int b){
        return abs(a) > abs(b);
    }
};