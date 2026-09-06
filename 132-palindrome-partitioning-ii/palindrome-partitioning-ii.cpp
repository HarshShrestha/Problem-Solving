class Solution {
    vector<int> dp;
    vector<vector<int>> palind;

public:
    int minCut(string s) {
        int n = s.length();
        dp.resize(n ,- 1);
        palind.resize(n, vector<int>(n, 0));

        //pre palindrome check
        for(int i=0; i<n; i++) palind[i][i] = 1;
        for(int len=2; len<=n; len++){
            for(int i=0; i<= n-len; i++){
                int j = i+len-1;
                if(s[i] == s[j]){
                    if(len==2 || palind[i+1][j-1]){
                        palind[i][j] = 1;
                    }
                }
            }
        }
        return func(0, n, s);
    }
    int func(int i, int n, string& s) {
        if (i == n || palind[i][n - 1])
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int mini = 1e9;
        for (int k = i; k < n; k++) {
            // If the left piece s[i...k] is a valid palindrome
            if ( palind[i][k] ) {
                // Cut right here: cost is 1 cut + whatever cuts the remaining suffix needs
                int cost = 1 + func(k + 1, n, s);
                mini = min(cost, mini);
            }
        }
        return dp[i] = mini;
    }
};