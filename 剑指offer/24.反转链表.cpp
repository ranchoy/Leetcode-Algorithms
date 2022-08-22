// https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/
// 链表翻转，注意树为空的情况。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode *pre = nullptr, *temp = nullptr;
        while(head->next != nullptr) {
            temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        head->next = pre;
        return head;
    }
};

/*
[1,2,3,4,5]
[5,4,3,2,1]
*/
