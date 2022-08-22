// https://leetcode-cn.com/problems/recover-binary-search-tree/
// 不满足的情况分为：两个节点相邻或者两个节点不相邻。
// 相邻情况，前节点值大于后节点值出现一次；不相邻情况，此情况出现两次。
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
    void recoverTree(TreeNode* root) {
        if(root == nullptr) return;
        TreeNode *pre_node = nullptr;
        TreeNode *p_x = nullptr, *p_y = nullptr;
        stack<TreeNode*> st;
        
        while(!st.empty() || root != nullptr) {
            while(root != nullptr) {
                st.push(root);
                root = root->left;
            }
            
            if(!st.empty()) {
                root = st.top();
                st.pop();
                if(pre_node != nullptr && root->val <= pre_node->val) {
                    p_y = root;
                    if(p_x == nullptr) {
                        p_x = pre_node;
                    } else {
                        break;
                    }
                }
                pre_node = root;
                root = root->right;
            }
        }
        int temp = p_x->val;
        p_x->val = p_y->val;
        p_y->val = temp;
    }
};

/*
[1,3,null,null,2]
[3,1,null,null,2]
[3,1,4,null,null,2]
[2,1,4,null,null,3]
*/
