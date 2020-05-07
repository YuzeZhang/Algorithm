//
// Created by Zeno on 2020/5/7.
//

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
    int rob(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        if (memo.count(root)) {
            return memo[root];
        }


        // rob this house and go to the next house's next house(root->left->left and root->left->right and root->right->left and root->right->right)
        int do_rob = root->val +
                     (root->left == nullptr ? 0 : rob(root->left->left) + rob(root->left->right)) +
                     (root->right == nullptr ? 0 : rob(root->right->left) + rob(root->right->right));

        // don't rob this house and go to the next house(root->left and root->right)
        int not_rob = rob(root->left) + rob(root->right);

        int res = std::max(do_rob, not_rob);
        memo[root] = res;
        return res;
    }
private:
    map<TreeNode*, int> memo;
};