// https://leetcode-cn.com/problems/symmetric-tree/
// 对称二叉树，左右半区完全对称，对称节点非空且值相等。
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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return is_symmetric(root->left, root->right);
    }
    
    bool is_symmetric(TreeNode *p_l, TreeNode *p_r) {
        if(p_l == nullptr && p_r == nullptr) return true;
        if(p_l == nullptr || p_r == nullptr) return false;
        if(p_l->val != p_r->val) return false;
        
        bool flag1 = is_symmetric(p_l->left, p_r->right);
        bool flag2 = is_symmetric(p_l->right, p_r->left);
        return flag1 & flag2;
    }
};

/*
[1,2,2,3,4,4,3]
true
[1,2,2,null,3,null,3]
false
*/
