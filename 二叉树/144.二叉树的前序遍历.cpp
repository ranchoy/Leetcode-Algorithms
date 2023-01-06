// https://leetcode.cn/problems/binary-tree-preorder-traversal/
// 题解：先序遍历，根左右，注意在栈中先插入右节点，再左节点。
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if(root == nullptr) return {};
        vector<int> ans;
        stack<TreeNode*> stk;
        stk.push(root);

        while(!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();
            ans.push_back(node->val);

            if(node->right) stk.push(node->right);
            if(node->left) stk.push(node->left);
        }

        return ans;
    }
};

/*
[1,null,2,3]
[1,4,3,2]

[1,2,3]
[1,4,2,3]
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
