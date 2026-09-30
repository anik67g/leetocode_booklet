class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if (!root)
            return 0;

        long long ans = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {

            int size = q.size();

            long long mmin = q.front().second;

            long long first = 0;
            long long last = 0;

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front().first;

                long long cur_ind = q.front().second - mmin;

                q.pop();

                if (i == 0)
                    first = cur_ind;

                if (i == size - 1)
                    last = cur_ind;

                if (node->left) {
                    q.push({
                        node->left,
                        cur_ind * 2 + 1
                    });
                }

                if (node->right) {
                    q.push({
                        node->right,
                        cur_ind * 2 + 2
                    });
                }
            }

            ans = max(ans, last - first + 1);
        }

        return (int)ans;
    }
};