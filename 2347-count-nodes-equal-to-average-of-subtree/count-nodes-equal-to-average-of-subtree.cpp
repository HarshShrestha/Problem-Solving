/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        auto res = func(root,cnt);
        // cout<<res.first<<" "<<res.second;
        // node,
        // cntSubtreeNodes, 
        //count nodes which satisfy : ( node-> val ) * (no. of subtrees) = ( sum of subtrees  )
        return cnt;
    }
    pair<int,int> func(TreeNode* root, int& cnt){ //returns { no. of subtrees , sum of subTr}
        if(!root->left && !root->right){
            cnt++;
            return {1,root->val};
        }

        pair<int,int> l = {0,0};
        pair<int,int> r = {0,0};

        if(root->left) l = func(root->left, cnt);
        if(root->right) r = func(root->right, cnt);

        //check
        int totalSubtrees = 1 + l.first + r.first;
        int totalSum = root->val + l.second + r.second;

        if( totalSum / totalSubtrees == root->val ) cnt++;

        return {totalSubtrees, totalSum};
    } 
};