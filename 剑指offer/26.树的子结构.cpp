// https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
// DFS递归，一个是找相同根节点，一个是根据已知根节点判断是否是子结构。
// 默认p1是母树，p2是子树。
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
    bool isSubStructure(TreeNode *p1, TreeNode *p2) {
        if(p1 == nullptr || p2 == nullptr) {
            return false;
        }
        return dfs(p1, p2) || isSubStructure(p1->left, p2) || isSubStructure(p1->right, p2);
    }

    bool dfs(TreeNode *p1, TreeNode *p2) {
        if(p2 == nullptr) return true;
        if(p1 == nullptr) return false;
        if(p1->val != p2->val) return false;

        return dfs(p1->left, p2->left) && dfs(p1->right, p2->right);
    }
};

/*
[1,2,3,4]
[3]

true
*/
