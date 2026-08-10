class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for(int i=0;i<n;i++){
            if(parent[i]==-1) continue;
            children[parent[i]].push_back(i);
        }
        queue<int> q;
        vector<int> depth(n);
        q.push(0);
        depth[0]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto& nbd : children[node]){
                depth[nbd] = depth[node]+1;
                q.push(nbd);
            }
        }
        int h = 0;
        for(auto& d : depth){
            h = max(h,d);
        }
        long long ans =0;
        for(int i =0;i<n;i++){
            ans+= 1LL*nums[i] * (h - depth[i] + 1);
        }
        return ans;
    }
};