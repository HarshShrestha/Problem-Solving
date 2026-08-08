class DisjointSet{
public:
    vector<int> par, size;
    DisjointSet(int n){
        par.resize(n+1);
        size.resize(n+1,1);
        // self parent initialization
        for(int i =0;i<=n;i++) par[i]=i;
    }
    int findPar(int x){
        if(par[x]==x) return x;
        return par[x] = findPar(par[x]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            par[ulp_u]=ulp_v;
            size[ulp_u]+=size[ulp_v];
        }else{
            par[ulp_v]=ulp_u;
            size[ulp_v]+=size[ulp_u];
        }

    }
};
class Solution {  
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n= accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mpp;
        
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mpp.find(mail)==mpp.end()){
                    mpp[mail] = i;
                }else{
                    ds.unionBySize(i,mpp[mail]);
                }
            }
        }

        //  Group mails using their ultimate parent
        vector<vector<string>> mergedMails(n); //max size = n , some may be empty
        for(auto &it : mpp){
            string mail = it.first;
            int node = ds.findPar(it.second);
            mergedMails[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergedMails[i].empty()) continue;

            vector<string> temp;
            temp.push_back(accounts[i][0]); //insert name first

            sort(mergedMails[i].begin(),mergedMails[i].end());

            for(auto& mail : mergedMails[i]){
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        return ans;

    }
};