// https://leetcode.cn/problems/evaluate-boolean-binary-tree/
// 题解：递归遍历，注意题目提供的树都是完整二叉树，叶子节点层层向上递归得到结果。
class Solution {
    public boolean evaluateTree(TreeNode root) {
        if(root.left == null && root.right == null) {
            return (root.val == 1) ? true : false;
        }
        boolean left = evaluateTree(root.left);
        boolean right = evaluateTree(root.right);
        return (root.val == 2) ? (left || right) : (left && right);
    }
}

/*
[0]
[2,1,3,null,null,0,1]

false
true
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