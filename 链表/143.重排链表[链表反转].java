// https://leetcode.cn/problems/reorder-list/
// 题解：链表反转 + 快慢指针，注意快慢指针的遍历方法。
class Solution {
    public void reorderList(ListNode head) {
        if(head == null) return;

        ListNode mid = mid_node(head);
        ListNode rev_list = reverse_node(mid.next);
        mid.next = null; // cut

        merge_list_node(head, rev_list);
    }

    public ListNode mid_node(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while(fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }

    public ListNode reverse_node(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;

        while(cur != null) {
            ListNode next = cur.next;
            cur.next = pre;
            pre = cur; cur = next;
        }

        return pre;
    }

    public void merge_list_node(ListNode l1, ListNode l2) {
        ListNode temp1 = null, temp2 = null;

        while(l1 != null && l2 != null) {
            temp1 = l1.next; temp2 = l2.next;
            l1.next = l2; l1 = temp1;
            l2.next = l1; l2 = temp2;
        }
    }
}

/*
[1,2,3,4,5]

[1,5,2,4,3]
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