/**
 // https://leetcode-cn.com/problems/linked-list-cycle-ii/
 // 快慢指针，2*(A+B)=A+B+n*(B+C)，A+B=n*(B+C)，A=C有可能。
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                ListNode *temp = head;
                while(temp != slow) { // 注意是慢指针走
                    temp = temp->next;
                    slow = slow->next;
                }
                return temp;
            }
        }

        return nullptr;
    }
};

/*
[3,2,0,-4]
1
返回指向ListNode(2)的指针
*/
