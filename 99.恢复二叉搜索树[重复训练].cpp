// https://leetcode-cn.com/problems/recover-binary-search-tree/
// ������������Ϊ�������ڵ����ڻ��������ڵ㲻���ڡ�
// ���������ǰ�ڵ�ֵ���ں�ڵ�ֵ����һ�Σ������������������������Ρ�
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
