// https://leetcode-cn.com/problems/linked-list-cycle/submissions/
// 快慢指针
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
    bool hasCycle(ListNode *head) {
        // 快慢指针，注意不要出现指针为空错误
        if(head == nullptr || head->next==nullptr) return false;

        ListNode *fast = head;
        ListNode *slow = head;

        while(fast!=nullptr && fast->next!=nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if(slow == fast) {
                return true;
            }
        }

        return false;
    }
};
