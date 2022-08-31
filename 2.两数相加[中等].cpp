// https://leetcode.cn/problems/add-two-numbers/
// 题解：加法进位+链表，注意避免链表为空情况。
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        int s = 0, carry = 0;
        ListNode *res = new ListNode(-1), *tmp = res;

        while(l1 != nullptr || l2 != nullptr) {
            int v1 = (l1 != nullptr) ? l1->val : 0;
            int v2 = (l2 != nullptr) ? l2->val : 0;

            s = v1 + v2 + carry;
            carry = s / 10; s = s % 10;
            tmp->next = new ListNode(s); tmp = tmp->next;

            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        if(carry) tmp->next = new ListNode(carry);

        return res->next;
    }
};

/*
[2,4,3]
[5,6,4]
[9,9,9,9,9,9,9]
[9,9,9,9]

[7,0,8]
[8,9,9,9,0,0,0,1]
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
