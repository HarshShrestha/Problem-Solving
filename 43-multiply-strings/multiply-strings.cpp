class Solution {
public:
    string multiply(string num1, string num2) {
        
        int n1 = num1.length(), n2 = num2.length();
        if(num1=="0" || num2=="0") return "0";
        string ans = "0";
        int F = 0;
        for(int i= n2-1; i >=0; i--){
            int b = num2[i]-'0';
            int carry = 0;
            long long stay = 0;
            string temp = "";
            // cout<< "i = " << i << ", b = "<<b<<" "<<endl;  
            for(int j = n1-1; j>=0; j--){
                int a = num1[j]-'0';
                int prod = a*b + carry;
                stay = prod %10;
                carry = prod/10;
                temp = to_string(stay) + temp;
                // cout<< "j = " << j;
                // cout<< ", a = "<<a<<endl;
                // cout<< "prod = "<<prod<<endl;
                // cout<<"stay = " << stay<<endl ;
                // cout<<"carry = " << carry <<endl;
                // cout<<"temp = " << temp<<endl ;

                
            }
            if(carry){
                temp = to_string(carry)+ temp;
            }
            ans = add(temp,ans,F);
            // cout<<"ans = "<<ans<<endl;
            // cout<<"=============="<<endl;
            F++;
        }
        return ans;
    }
    string add(string temp, string ans, int F) {
    if (temp == "0") return ans;
    
    string shifted_temp = temp + string(F, '0');
    
    int i = shifted_temp.size() - 1;
    int j = ans.size() - 1;
    int carry = 0;
    string result = "";

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) {
            sum += shifted_temp[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += ans[j] - '0';
            j--;
        }
        carry = sum / 10;
        result += to_string(sum % 10);
    }

    reverse(result.begin(), result.end());
    return result;
}
};