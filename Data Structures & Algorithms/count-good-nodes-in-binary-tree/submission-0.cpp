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
    int dfs(TreeNode* root,int k) {
        if(root == nullptr) return 0;
        int count=0;
        if(root->val>=k){
            count++;
        }
        k=max(k,root->val);
        count+=dfs(root->right,k);
        count+=dfs(root->left,k);
        return count;

    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};
