// https://leetcode.cn/problems/merge-in-between-linked-lists/
// 题解：链表遍历，注意截断处b时的指针位置。
class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        int k = 0;
        ListNode ans = list1;
        ListNode a_pre = null, b_next = null;
        ListNode temp1 = list1, temp2 = list2;

        while(temp1.next != null) {
            if(k == a - 1) a_pre = temp1;
            if(k == b) {
                b_next = temp1.next; break;
            }
            temp1 = temp1.next;
            k++;
        }
        while(temp2.next != null) {
            temp2 = temp2.next;
        }

        a_pre.next = list2;
        if(b_next != null) temp2.next = b_next;
        return list1;
    }
}

/*
[0,1,2,3,4,5,6]
2
5
[1000000,1000001,1000002,1000003,1000004]

[0,1,1000000,1000001,1000002,1000003,1000004,6]
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