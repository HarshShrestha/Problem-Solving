class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());

        int m = prices.size(), n =discounts.size();
        int i=0, j=0;
        double ans = 0.0;
        while(i<m && j<n){
            double d = 0.0;
            int p = prices[i];
            if(j<n){
                d = discounts[j];
            }
            ans += (p * (100 - d)) / 100 ;

            i++; j++;
        }
        while(i<m) {
            ans+=(double)prices[i];
            i++;
        }
        return ans;

    }
};