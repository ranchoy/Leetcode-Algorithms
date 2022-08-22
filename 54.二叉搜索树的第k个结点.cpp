// https://www.nowcoder.com/practice/ef068f602dde4d28aab2b210e859150a?tpId=13&tqId=23456&ru=/ta/sql-quick-study&qru=/ta/sql-quick-study/question-ranking
// 堆栈 + 指针
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        // 堆栈实现，先遍历完左子树，不满足则上升到父节点，再进入右节点
        if(pRoot == nullptr) return nullptr;
        
        int cnt = 0;
        stack<TreeNode*> stk;
        TreeNode *p_node = pRoot;
        
        while(!stk.empty() || p_node!=nullptr) {
            while(p_node != nullptr) {
                stk.push(p_node);
                p_node = p_node->left;
            }
            
            p_node = stk.top();
            stk.pop();

            if((--k) == 0) return p_node;

            p_node = p_node->right;
        }
        return nullptr;
    }
};
