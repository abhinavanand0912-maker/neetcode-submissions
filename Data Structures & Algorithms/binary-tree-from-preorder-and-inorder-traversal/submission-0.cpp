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
    unordered_map<int,int> pos;
    int preindex=0;
    TreeNode* build(vector<int>& preorder,int instart,int inend){
        if(instart>inend){
            return NULL;
        }
        int rootval=preorder[preindex++];
        TreeNode* root = new TreeNode(rootval);

        int mid=pos[rootval];
        root->left = build(preorder, instart, mid - 1);
        root->right = build(preorder, mid + 1, inend);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            pos[inorder[i]]=i;
        }
        preindex=0;
        return build(preorder,0,inorder.size()-1);
    }
};
