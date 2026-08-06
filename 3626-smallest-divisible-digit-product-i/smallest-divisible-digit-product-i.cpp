class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans = 0;
        while(n<=200){
            int prod = findProd(n);
            if(prod%t==0) return n;
            n++;
        }
        return -1;
    }
    int findProd(int x){
        int ans = 1;
        while(x){
            ans*=(x%10);
            x/=10;
        }
        return ans;
    }
};