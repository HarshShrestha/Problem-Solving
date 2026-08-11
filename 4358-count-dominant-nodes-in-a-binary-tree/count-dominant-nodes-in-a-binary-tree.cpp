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
    int countDominantNodes(TreeNode* root) {
        int cnt=0;

        func(root,cnt);
        return cnt;
    }
    int func(TreeNode* root, int& cnt){
        if(!root) return -1;
        int maxi = -1;
        int l = func(root->left,cnt);
        int r = func(root->right,cnt);

        cnt+=(root->val >= max(l,r));
        return maxi = max({l,r,root->val});

    }
};