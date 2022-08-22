// https://leetcode.cn/problems/successor-lcci/
// 中序遍历：左根右，找到当前p节点，再往后找一位即可。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        bool flag = false;
        stack<TreeNode*> st;

        while(root || !st.empty()) {
            while(root) {
                st.push(root);
                root = root->left;
            }

            if(!st.empty()) {
                TreeNode *node = st.top(); st.pop();
                if(flag == true) return node;
                if(node == p) flag = true; // 标记
                root = node->right;
            }
        }

        return nullptr;
    }
};

/*

[2,1,3]
1
[5,3,6,2,4,null,null,1]
6

2
null
*/
