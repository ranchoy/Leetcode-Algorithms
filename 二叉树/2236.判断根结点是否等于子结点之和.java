
// https://leetcode.cn/problems/root-equals-sum-of-children/
class Solution {
    public boolean checkTree(TreeNode root) {
        if(root.left == null && root.right == null) {
            return true;
        }

        return (root.val == root.left.val + root.right.val) && checkTree(root.left) && checkTree(root.right);
    }
}
/*
[10,4,6]
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