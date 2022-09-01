// https://leetcode.cn/problems/print-binary-tree/
// 题解：层次遍历，注意避免数组越界情况。
class Solution {
public:
    vector<vector<string>> printTree(TreeNode *root) {
        int m = tree_depth(root), n = pow(2,m) - 1;
        vector<vector<string>> res(m,vector<string>(n,""));
        build_tree_arr(root, res, 0, (n-1)/2);

        return res;
    }

    void build_tree_arr(TreeNode *root, vector<vector<string>> &res, int i, int j) {
        if(root == nullptr) return;
        int m = res.size(), n = res[0].size();
        int cur_height = i + 1, k = pow(2, m-cur_height-1);
        if(i < 0 || i >= m || j < 0 || j >= n) return;

        res[i][j] = to_string(root->val);
        if(root->left) build_tree_arr(root->left, res, i+1, j-k);
        if(root->right) build_tree_arr(root->right, res, i+1, j+k);
    }

    int tree_depth(TreeNode *root) {
        if(root == nullptr) return 0;
        int left_depth = tree_depth(root->left);
        int right_depth = tree_depth(root->right);
        return max(left_depth, right_depth) + 1;
    }
};

/*
[1,2]
[1,2,3,null,4]

[["","1",""],
 ["2","",""]]
[["","","","1","","",""],
 ["","2","","","","3",""],
 ["","","4","","","",""]]
*/

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
