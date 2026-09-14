class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int prev = points[0][1];
        int cnt = 1, n= points.size();
        for(int i=1;i<n;i++){
            if(points[i][0] <= prev ){
                prev = min(prev, points[i][1]);
            }else{
                prev = points[i][1];
                cnt+=1;
            }
        }
        return cnt;
    }
};