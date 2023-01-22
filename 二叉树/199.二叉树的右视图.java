// https://leetcode.cn/problems/binary-tree-right-side-view/
// 题解：二叉树层序遍历，
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        if(root == null) return new ArrayList<Integer>();
        int cur_cnt = 1;
        List<Integer> ans = new ArrayList<Integer>();
        LinkedList<TreeNode> que = new LinkedList<TreeNode>();
        que.push(root);

        while(!que.isEmpty()) {
            TreeNode node = que.peek();
            que.pop(); cur_cnt--;

            if(node.left != null) que.add(node.left);
            if(node.right != null) que.add(node.right);

            if(cur_cnt == 0) {
                cur_cnt = que.size();
                if(!que.isEmpty()) ans.add(node.val);
            }
        }

        return ans;
    }
}

/*
[1,null,3]
[1,2,3,null,5,null,4]

[1,3]
[1,3,4]
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */