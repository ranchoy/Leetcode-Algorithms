// https://leetcode.cn/problems/linked-list-components/
// 题解：哈希+标记，通过flag标记连续节点段。
class Solution {
public:
    int numComponents(ListNode *head, vector<int> &nums) {
        int res = 0;
        bool flag = false; // avoid repeat

        set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        while(head != nullptr){
            if(st.count(head->val) > 0 && flag == false) {
                flag = true; res++;
            } else if(st.count(head->val) == 0) {
                flag = false;
            }
            head = head->next;
        }

        return res;
    }
};

/*
[0,1,2,3]
[0,1,3]

2
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
