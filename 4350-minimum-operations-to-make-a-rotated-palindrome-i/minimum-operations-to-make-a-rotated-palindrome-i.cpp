class Solution {
public:
    int minOperations(string s) {
        int n= s.length();
        int ans=find(s);
        // cout<<"first " << ans << "->" << s<<endl;
        for(int i = 1 ; i<n; i++){
            reverse(s.begin() + 1 , s.end());
            reverse(s.begin(), s.begin()+1);
            reverse(s.begin(),s.end());
            int res = find(s);
            ans = min(ans , i + res);
            // cout<<ans << "->" << s<<endl;
        }
        return ans;
    }
    int find(string s){
        int res = 0;
        int n = s.length();
        for(int i =0 ; i< n/2;i++){
            res += min(abs(s[i] - s[n-i-1]) , 26 - abs(s[i] - s[n-i-1]));
        }
        return res;
    }
};