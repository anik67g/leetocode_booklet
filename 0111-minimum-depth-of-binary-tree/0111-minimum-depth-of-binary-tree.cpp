class Solution {
public:

    int ans = INT_MAX;

    void dfs(TreeNode* root, int depth) {

        // Stop if there is no node
        if (root == nullptr) {
            return;
        }

        // A leaf node marks the end of a valid path
        if (root->left == nullptr && root->right == nullptr) {
            ans = min(ans, depth);
            return;
        }

        // Explore left and right subtrees
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    int minDepth(TreeNode* root) {

        // Empty tree has depth 0
        if (root == nullptr) {
            return 0;
        }

        // Root starts at depth 1
        dfs(root, 1);

        return ans;
    }
};