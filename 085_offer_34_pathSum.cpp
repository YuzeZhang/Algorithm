//
// Created by Zeno on 2020/5/9.
//

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        vector<int> path;
        int curSum = 0;
        pathSum(root, sum, curSum, path, res);

        return res;
    }
    void pathSum(TreeNode* root, int expectedSum, int curSum, vector<int>& path, vector<vector<int>>& res) {
        curSum += root->val;
        path.push_back(root->val);

        bool isLeaf = root->left == nullptr && root->right == nullptr;
        if (isLeaf && curSum == expectedSum) {
            res.push_back(path);
        }

        if (root->left != nullptr) {
            pathSum(root->left, expectedSum, curSum, path, res);
        }
        if (root->right != nullptr) {
            pathSum(root->right, expectedSum, curSum, path, res);
        }

        path.pop_back();
    }
};