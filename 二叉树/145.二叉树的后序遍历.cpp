// https://leetcode.cn/problems/binary-tree-postorder-traversal/
// 后序遍历，左右根，类似先序遍历，先插入左节点，再插入右节点。
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        stack<TreeNode*> stk;
        stk.push(root);

        while(!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();
            ans.push_back(node->val);

            if(node->left) stk.push(node->left);
            if(node->right) stk.push(node->right);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
[1,null,2,3]

[3,2,1]
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
