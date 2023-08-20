// https://leetcode.cn/problems/merge-two-sorted-lists/
// 题解：新建一个链表头进行排序。
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode ans = new ListNode(-1);
        ListNode temp = ans;

        while(list1 != null && list2 != null) {
            if(list1.val <= list2.val) {
                temp.next = list1; list1 = list1.next;
            } else {
                temp.next = list2; list2 = list2.next;
            }
            temp = temp.next;
        }
        temp.next = (list1 == null) ? list2 : list1;

        return ans.next;
    }
}

/*
[1,2,4]
[1,3,4]

[1,1,2,3,4,4]
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */