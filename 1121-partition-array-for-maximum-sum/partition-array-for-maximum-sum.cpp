class Solution {
    vector<vector<int>> dp;
    vector<vector<int>> preSum;
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        dp.resize(n,vector<int>(n,-1));
        preSum.resize(n,vector<int>(n));

        for(int i = 0 ; i<n; i++){
            preSum[i][i] = arr[i];
            for(int j=i+1; j<n; j++){
                preSum[i][j] = max(preSum[i][j-1], arr[j]);
            }
        }
        return func(0,n-1,k,arr);
        
    }
    int func(int i, int j, int k, vector<int>& arr){
        if(j-i+1 <= k) return (j-i+1) * preSum[i][j];
        
        if( dp[i][j]!=-1 ) return dp[i][j];
        int maxi = -1;
        for(int p=0; p<k; p++){
            int sum = func(i,i+p,k,arr) + func(i+p+1,j,k,arr);
            maxi = max(maxi, sum);
        }
        return dp[i][j] = maxi;
    }
};