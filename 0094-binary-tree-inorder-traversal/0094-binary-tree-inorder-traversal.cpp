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
    vector<int> tree;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL){
            return tree ;
        }
       inorderTraversal(root->left);
       tree.push_back(root->val);
        inorderTraversal(root->right);
        return tree;
    }
};