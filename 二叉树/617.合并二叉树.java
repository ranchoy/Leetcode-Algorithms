// https://leetcode.cn/problems/merge-two-binary-trees/
// 题解：二叉树递归，注意为空条件。
class Solution {
    public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
        if(root1 == null || root2 == null) {
            return (root2 == null) ? root1 : root2;
        }

        root1.val += root2.val;
        root1.left = mergeTrees(root1.left, root2.left);
        root1.right = mergeTrees(root1.right, root2.right);
        
        return root1;
    }
}

/*
[1,3,2,5]
[2,1,3,null,4,null,7]

[3,4,5,5,4,null,7]
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