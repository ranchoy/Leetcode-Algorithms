// https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees/
// 栈实现中序遍历（左根右），注意这是双栈空间，每次要比较节点大小。
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
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        vector<int> res;
        stack<TreeNode*> stk1, stk2;
        TreeNode *node1 = nullptr, *node2 = nullptr;

        while(root1 || root2 || !stk1.empty() || !stk2.empty()) {
            while(root1) {
                stk1.push(root1); root1 = root1->left; // 左子树
            }
            while(root2) {
                stk2.push(root2); root2 = root2->left; // 左子树
            }

            if(!stk1.empty() && !stk2.empty()) {
                node1 = stk1.top();
                node2 = stk2.top();

                if(node1->val <= node2->val) {
                    res.push_back(node1->val); stk1.pop();
                    root1 = node1->right; // 右子树
                } else if(node1->val > node2->val) {
                    res.push_back(node2->val); stk2.pop();
                    root2 = node2->right; // 右子树
                }
            } else if(!stk1.empty()) {
                node1 = stk1.top(); stk1.pop();
                res.push_back(node1->val);
                root1 = node1->right;
            } else if(!stk2.empty()) {
                node2 = stk2.top(); stk2.pop();
                res.push_back(node2->val);
                root2 = node2->right;
            }
        }

        return res;
    }
};

/*
[2,1,4]
[1,0,3]

[0,1,1,2,3,4]
*/
