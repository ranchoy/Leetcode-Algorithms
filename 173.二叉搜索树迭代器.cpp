// https://leetcode-cn.com/problems/binary-search-tree-iterator/
// ��������⣬ע��next()�����ı�д���Ȱ���һ�ڵ㵯�������ѵ�ǰ�ڵ���Һ��ӵ��룬�ٵ������ӡ�
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
