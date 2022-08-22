#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head);

int main()
{
	int i;
	int nums[] = {1,2,3,4,5};
	ListNode *head, *end, *node;
	head = (ListNode*)malloc(sizeof(ListNode));
	
	end = head;
	end->val = nums[0];
	for(i=1; i<5; i++)
	{
		node = (ListNode*)malloc(sizeof(ListNode));
		node->val = nums[i];
		end->next = node;
		end = node;
		cout << node->val << endl;
	}
	end->next = NULL;

	end = head;
	for(i=0; i<5; i++)
	{
		cout << end->next << " " << end->val << endl;
		end = end->next;
	}
		
	head = reverseList(head);
	
	end = head;
	for(i=0; i<5; i++)
	{
		cout << end->next << " " << end->val << endl;
		end = end->next;
	}
	return 0;
}

ListNode* reverseList(ListNode* head)
{
	ListNode *end, *p_pre, *p_next;
	
	end = head;
	p_pre = nullptr;
	while(end != nullptr)
	{
		p_next = end->next;
		end->next = p_pre;
		
		p_pre = end;
		end = p_next;
	}
	
	return p_pre;
}
