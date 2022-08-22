// https://www.nowcoder.com/practice/b58434e200a648c589ca2063f1faf58c?tpId=117
// 模拟题目，注意链表翻转格式，以及循环终止条件
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode *head, int m, int n) {
        if(m == n) return head;
        
        int i = 1;
        ListNode *temp = head, *new_head = nullptr;
        ListNode *left = nullptr, *right = nullptr;
        
        while(i <= n) {
            if(i == m-1) left = temp;
            temp = temp->next; i++;
        }
        right = temp;
        
        if(m == 1) {
            temp = reverse_node(head, n-m+1);
            new_head = temp;
        } else {
            temp = reverse_node(left->next, n-m+1);
            left->next = temp;
            new_head = head;
        }
        
        if(temp != nullptr) {
            while(temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = right;
        }
        
        return new_head;
    }
    
    ListNode *reverse_node(ListNode *head, int len) {
        int i = 1;
        ListNode *pre=nullptr, *temp=nullptr;
        while(head != nullptr && i < len) {
            temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
            i++;
        }
        head->next = pre;
        return head;
    }
};

/*
{5},1,1
{5}
{1,2,3,4,5},1,5
{5,4,3,2,1}
{1,2,3,4,5},2,4
{1,4,3,2,5}
*/
