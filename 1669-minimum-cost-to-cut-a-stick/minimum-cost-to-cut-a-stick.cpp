class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(0,m-1,0,n,cuts,dp);
    }
    int func(int i,int j,int leftEnd, int rightEnd, vector<int>& cuts,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = 1e9;
        // k tries all the combinations of the cuts
        for(int k =i;k<=j;k++){
            int cost = (rightEnd-leftEnd) + func(i,k-1,leftEnd,cuts[k],cuts,dp) + func(k+1,j,cuts[k],rightEnd,cuts,dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
};