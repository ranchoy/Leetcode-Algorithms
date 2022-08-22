// https://leetcode-cn.com/problems/merge-two-sorted-lists/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

int main()
{
	return 0;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode *head, *end;
	
	head = new ListNode(-1);
	end = head;
	while(l1!=nullptr && l2!=nullptr)
	{
		if(l1->val < l2->val)
		{
			end->next = l1;
			l1 = l1->next;
		}
		else
		{
			end->next = l2;
			l2 = l2->next;
		}
		end = end->next;
	}
	
	end->next = (l1 == nullptr) ? l2 : l1;
	
	return head->next;
}
