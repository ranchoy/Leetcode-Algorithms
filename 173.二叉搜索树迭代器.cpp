// https://leetcode-cn.com/problems/binary-search-tree-iterator/
// 中序遍历题，注意next()函数的编写，先把下一节点弹出，并把当前节点的右孩子弹入，再弹入左孩子。
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
 /**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        if(st.empty()) return 0;
        TreeNode *root = st.top();
        st.pop();
        int val = root->val;
        root = root->right;
        while(root) {
            st.push(root);
            root = root->left;
        }
        return val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/*
["BSTIterator","next","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]
[[[7,3,15,null,null,9,20]],[],[],[],[],[],[],[],[],[]]
[null,3,7,true,9,true,15,true,20,false]
*/
