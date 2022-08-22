// https://leetcode-cn.com/problems/validate-binary-search-tree/
// 验证二叉搜索树，左孩子<根节点<右孩子，用中序遍历实现。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        long pre_val = LONG_MIN; // 注意INT_MIN会出现
        stack<TreeNode*> st;
        
        while(!st.empty() || root != nullptr) {
            while(root != nullptr) {
                st.push(root);
                root = root->left;
            }
            
            if(!st.empty()) {
                TreeNode *temp = st.top();
                st.pop();
                
                if(temp->val <= pre_val) {
                    return false;
                }
                pre_val = temp->val;
                root = temp->right;
            }
        }
        return true;
    }
};

/*
[1]
false
[2,1,3]
[true]
[2,2,2]
false
[-2147483648]
false
*/
