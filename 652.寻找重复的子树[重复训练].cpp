// https://leetcode.cn/problems/find-duplicate-subtrees/
// 题解：hash_map序列化二叉树，当出现次数为两次时，则是重复子树。
class Solution {
private:
    vector<TreeNode*> res;
    unordered_map<string, int> mps;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;
    }

    string dfs(TreeNode *root) {
        if(root == nullptr) return "";
        string key = to_string(root->val) + "[" + dfs(root->left) + "]" + "[" + dfs(root->right) + "]";
        mps[key] += 1;
        if(mps[key] == 2) res.emplace_back(root);
        return key;
    }
};

/*
[1,2,3,4,null,2,4,null,null,4]

[[4],[2,4]]
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
