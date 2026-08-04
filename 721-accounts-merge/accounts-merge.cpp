class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& arr) {
        map<string,string> owner;
        map<string,string> parent;
        map<string,set<string>> unions;

        // from owner and self parent
        for(int i=0;i<arr.size();i++){
            for(int j=1;j<arr[i].size();j++){
                parent[arr[i][j]] = arr[i][j];
                owner[arr[i][j]] = arr[i][0];
            }
        }
        for(int i=0;i<arr.size();i++){
            string p = find(arr[i][1],parent);
            for(int j=2;j<arr[i].size();j++){
                parent[find(arr[i][j],parent)] = p;
            }
        }
        for(int i=0;i<arr.size();i++){
            for(int j=1;j<arr[i].size();j++){
                unions[find(arr[i][j],parent)].insert(arr[i][j]);
            }
        }
        vector<vector<string>> res;
        for(auto& p : unions){
            vector<string> emails(p.second.begin(),p.second.end());
            emails.insert(emails.begin(),owner[p.first]);
            res.push_back(emails);
        }
        return res;
    }
    string find(string s,map<string,string>& p){
        if(s==p[s]) return s;
        return find(p[s],p);
    }
};
