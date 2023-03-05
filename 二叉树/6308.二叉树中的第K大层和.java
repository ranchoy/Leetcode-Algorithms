import java.util.*;
// https://leetcode.cn/contest/weekly-contest-335/problems/kth-largest-sum-in-a-binary-tree/
// 题解：二叉树层序遍历，注意Long类型的同层节点和。
class Solution {
    public long kthLargestLevelSum(TreeNode root, int k) {
        long ans = 0, level_sum = 0;
        int level_cnt = 1;
        List<Long> sum_arr = new ArrayList<>();
        Deque<TreeNode> que = new ArrayDeque<>();
        que.addFirst(root);

        while(!que.isEmpty()) {
            TreeNode node = que.pollFirst();
            level_sum += node.val; level_cnt--;

            if(node.left != null) que.addLast(node.left);
            if(node.right != null) que.addLast(node.right);

            if(level_cnt == 0) {
                sum_arr.add(level_sum);
                level_sum = 0; level_cnt = que.size(); // update
            }
        }

        Collections.sort(sum_arr, Comparator.reverseOrder());
        if(k > sum_arr.size()) return -1;

        return sum_arr.get(k - 1);
    }
}
/*
[1,2,null,3]
1
[5,8,9,2,1,3,7,4,6]
2

3
13
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