class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        if(n==1) return 1;
        pair<int,int> prev = {speed[n-1], position[n-1]};
        int cnt = 1;
        for(int i = n-2; i >= 0; i--){
            if(speed[i] > prev.first || prev.second - position[i] <= distance){
                prev = {prev.first, position[i]};
            }else{
                cnt++;
                prev = {speed[i],position[i]};
            }
        }
        return cnt;
    }
};